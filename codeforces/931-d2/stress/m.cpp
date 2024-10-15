#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

const int MAX_N = 20004;

struct suffix_array {
    string s;
    int n, sum, r, ra[MAX_N], sa[MAX_N], auxra[MAX_N], auxsa[MAX_N], c[MAX_N], lcp[MAX_N];
    void counting_sort(int k) {
        memset(c, 0, sizeof(c));
        for (int i = 0; i < n; i++) c[(i + k < n) ? ra[i + k] : 0]++;
        for (int i = sum = 0; i < max(256, n); i++) sum += c[i], c[i] = sum - c[i];
        for (int i = 0; i < n; i++) auxsa[c[sa[i] + k < n ? ra[sa[i] + k] : 0]++] = sa[i];
        for (int i = 0; i < n; i++) sa[i] = auxsa[i];
    }
    void build_sa() {
        for (int k = 1; k < n; k <<= 1) {
            counting_sort(k);
            counting_sort(0);
            auxra[sa[0]] = r = 0;
            for (int i = 1; i < n; i++) {
                auxra[sa[i]] =
                    (ra[sa[i]] == ra[sa[i - 1]] && ra[sa[i] + k] == ra[sa[i - 1] + k])
                        ? r
                        : ++r;
            }
            for (int i = 0; i < n; i++) ra[i] = auxra[i];
            if (ra[sa[n - 1]] == n - 1) break;
        }
    }
    void build_lcp() {
        for (int i = 0, k = 0; i < n - 1; i++) {
            int j = sa[ra[i] - 1];
            while (s[i + k] == s[j + k]) k++;
            lcp[ra[i]] = k;
            if (k) k--;
        }
    }
    void set_string(string _s) {
        s = _s + '$';
        n = s.size();
        for (int i = 0; i < n; i++) ra[i] = s[i], sa[i] = i;
        memset(auxra, 0, sizeof(auxra));
        memset(auxsa, 0, sizeof(auxsa));
        build_sa();
        build_lcp();
        // cout << n << " -- " << endl;
        // for (int i = 0; i < n; i++)
        // printf("%2d %2d: %s\n", i, sa[i], s.c_str() + sa[i]);
    }
    int operator[](int i) { return sa[i]; }
} sas, sast;

struct SparseTable {
    int n, LG;
    vector<vector<int>> st;
    int merge(int a, int b) { return min(a, b); }
    const int neutral = 1e9;
    void build(const vector<int> &v) {
        n = (int)v.size();
        LG = 32 - __builtin_clz(n);
        st = vector<vector<int>>(LG, vector<int>(n));
        for (int i = 0; i < n; i++) st[0][i] = v[i];
        for (int i = 0; i < LG - 1; i++)
            for (int j = 0; j + (1 << i) < n; j++)
                st[i + 1][j] = merge(st[i][j], st[i][j + (1 << i)]);
    }
    void build(int *bg, int *en) { build(vector<int>(bg, en)); }
    int _query(int l, int r) {
        if (l > r) return neutral;
        int i = 31 - __builtin_clz(r - l + 1);
        return merge(st[i][l], st[i][r - (1 << i) + 1]);
    }
    int query(int l, int r) {
        r = min(r, n-1);
        l = max(l, 0);
        if (l > r) swap(l, r);
        if (l == r) return neutral;
        return _query(l+1, r);
    }
} sts, stst;

ll solve(string &s, string &t, bool leg) {
    // cout << "ss: " << endl;
    sas.set_string(s);
    sts.build(sas.lcp, sas.lcp + sas.n);
    // cout << "st: " << endl;
    sast.set_string(s + '$' + t);
    stst.build(sast.lcp, sast.lcp + sast.n);

    vector<int> et(sast.n);
    for (int i = 0; i < (int)et.size(); i++) {
        if (sast[i] > s.size()) et[i] = 1;
    }
    for (int i = 1; i < (int)et.size(); i++) et[i] += et[i-1];

    ll res = 0;
    for (int p = 0; p < (int)s.size(); p++) {
        for (int q = p; q < (int)s.size(); q++) {
            int sz = q - p + 1;

            int pos = sast.ra[p];

            int L = pos+1, R = pos, off = 0;
            int esq = pos+1, dir = sast.n-1;
            while (esq <= dir) {
                int mid = (esq + dir)/2;
                int lcp = stst.query(pos, mid);
                if (lcp >= sz) {
                    esq = mid + 1;
                    R = mid;
                } else dir = mid - 1;
            }
            esq = 0, dir = pos;
            while (esq <= dir) {
                int mid = (esq + dir)/2;
                int lcp = stst.query(mid, pos);
                if (lcp >= sz) {
                    dir = mid - 1;
                    L = mid;
                } else esq = mid + 1;
            }
            
            esq = 1, dir = min(p, (int)s.size() - q - 1);
            while (esq <= dir) {
                int mid = (esq + dir)/2;
                assert(0 <= p-mid && p-mid < p);
                assert(q+1 <= q+mid && q+mid < s.size());
                int lcp = sts.query(sas.ra[p-mid], sas.ra[q+1]);
                if (lcp >= mid) {
                    esq = mid + 1;
                    off = mid;
                } else dir = mid - 1;
            }

            off += leg;
            ll myres = (ll)(et[R] - et[L-1]) * (off);
            res += myres;

            // for (int i = p; i <= q; i++) cout << s[i];
            // cout << ": " << L << " " << R << " " << off << ": " << myres << endl;
        }
    }
    return res;
}

void fakemain() {
    string s, t;
    cin >> s >> t;

    ll r1 = solve(s, t, 1);
    ll r2 = solve(t, s, 0);
    // cout << "res: " << r1 << " " << r2 << endl;
    cout << r1 + r2<< endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    fakemain();
}



