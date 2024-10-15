#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

#ifndef ONLINE_JUDGE
const int MAX_N = 4e2 + 5;
#else
const int MAX_N = 4e5 + 5;
#endif

struct suffix_array {
    string s;
    int n, sum, r, ra[MAX_N], sa[MAX_N], auxra[MAX_N], auxsa[MAX_N], c[MAX_N], lcp_[MAX_N];
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
            lcp_[ra[i]] = k;
            if (k) k--;
        }
    }
    void set_string(string _s) {
        s = _s + '$';
        n = (int)s.size();
        for (int i = 0; i < n; i++) ra[i] = s[i], sa[i] = i;
        build_sa();
        build_lcp();
        // for (int i = 0; i < n; i++)
        // printf("%2d: %s\n", sa[i], s.c_str() +
        // sa[i]);
    }
    int operator[](int i) { return sa[i]; }
} sa;

const int INF = 1e9;

struct Seg {
    tuple<ll, int, int> seg[4 * MAX_N];
    int lazy[4 * MAX_N];
    Seg() {
        memset(lazy, -1, sizeof(lazy));
        for (int i = 0; i < 4 * MAX_N; i++) seg[i] = {0, -INF, INF};
    }
    void push(int p, int L, int R) {
        if (lazy[p] == -1) return;
        ll sum = (ll)(lazy[p] + 1) * (R - L + 1);
        int mx = lazy[p], mn = lazy[p];
        seg[p] = {sum, mx, mn};
        if (L != R) {
            lazy[2 * p] = lazy[p];
            lazy[2 * p + 1] = lazy[p];
        }
        lazy[p] = -1;
    }
    tuple<ll, int, int> query(int l, int r, int p = 1, int L = 0, int R = MAX_N - 1) {
        push(p, L, R);
        if (L > r || R < l) return {0, -INF, INF};
        if (L >= l && R <= r) return seg[p];
        int mid = (L + R) / 2;
        auto [sl, mxl, mnl] = query(l, r, 2 * p, L, mid);
        auto [sr, mxr, mnr] = query(l, r, 2 * p + 1, mid + 1, R);
        return {sl + sr, max(mxl, mxr), min(mnl, mnr)};
    }
    void update_set(int l, int r, int val, int p = 1, int L = 0, int R = MAX_N - 1) {
        push(p, L, R);
        if (L > r || R < l) return;
        if (L >= l && R <= r) {
            lazy[p] = val;
            push(p, L, R);
            return;
        }
        int mid = (L + R) / 2;
        update_set(l, r, val, 2 * p, L, mid);
        update_set(l, r, val, 2 * p + 1, mid + 1, R);
        auto &[sl, mxl, mnl] = seg[2 * p];
        auto &[sr, mxr, mnr] = seg[2 * p + 1];
        seg[p] = {sl + sr, max(mxl, mxr), min(mnl, mnr)};
    }
    int find_first_smaller(int l, int r, int val, int p = 1, int L = 0, int R = MAX_N - 1) {
        push(p, L, R);
        if (L > r || R < l) return INF;
        if (L >= l && R <= r) {
            auto &[sum, mx, mn] = seg[p];
            if (mn >= val) return INF;
            if (L == R) {
                return L;
            }
            int mid = (L + R) / 2;
            push(2 * p, L, mid);
            push(2 * p + 1, mid + 1, R);
            auto &[sr, mxr, mnr] = seg[2 * p + 1];
            if (mnr < val) return find_first_smaller(l, r, val, 2 * p + 1, mid + 1, R);
            return find_first_smaller(l, r, val, 2 * p, L, mid);
        }
        int mid = (L + R) / 2;
        int qr = find_first_smaller(l, r, val, 2 * p + 1, mid + 1, R);
        if (qr != INF) return qr;
        return find_first_smaller(l, r, val, 2 * p, L, mid);
    }
} seg;

void solve() {
    string s; cin >> s;
    int n = (int)s.size();

    sa.set_string(s);

    ll ans = 0;

    // for (int i = 0; i < n; i++) {
    //     for (int j = i + 1; j < n; j++) {
    //         ans += sa.lcp(i, j) + 1;
    //     }
    // }

    for (int i = 1; i <= n; i++) {
        auto j = sa.lcp_[i];
        int k = seg.find_first_smaller(1, i - 1, j);
        if (k == INF) k = 0;
        seg.update_set(k + 1, i, j);
        auto [sum, mx, mn] = seg.query(1, i);
        ans += sum;
    }

    cout << ans << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}
