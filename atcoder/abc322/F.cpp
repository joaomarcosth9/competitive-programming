#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif
#define endl '\n'
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto& x){ return res; }
#define L2(res...) [&](const auto& x, const auto& y){ return res; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

int n, q;
string s;

struct node {
    int res0, res1, pref0, pref1, suff0, suff1;
    int len;
    node() : res0(0), res1(0), pref0(0), pref1(0), suff0(0), suff1(0), len(0) {}
    node (char c) : res0(c == '0'), res1(c == '1'), pref0(c == '0'), pref1(c == '1'), suff0(c == '0'), suff1(c == '1'), len(1) {}
    node (node &l, node &r) {
        len = l.len + r.len;
        res0 = max({l.res0, r.res0, l.suff0 + r.pref0});
        res1 = max({l.res1, r.res1, l.suff1 + r.pref1});
        pref0 = l.pref0 + (l.pref0 == l.len) * r.pref0;
        pref1 = l.pref1 + (l.pref1 == l.len) * r.pref1;
        suff0 = r.suff0 + (r.suff0 == r.len) * l.suff0;
        suff1 = r.suff1 + (r.suff1 == r.len) * l.suff1;
    }
};

const node neutral = node();

class SegmentTree {
  private:
    vector<node> st;
    vector<int> lazy;
    int size;
#define left(p) (p << 1)
#define right(p) ((p << 1) + 1)
    void build(int p, int l, int r, string& S) {
        if (l == r) {
            st[p] = node(S[l]);
            return;
        }
        int m = (l + r) / 2;
        build(left(p), l, m, S);
        build(right(p), m + 1, r, S);
        st[p] = node(st[left(p)], st[right(p)]);
    }
    void push(int p, int l, int r) {
        if (lazy[p] & 1) {
            swap(st[p].res0, st[p].res1);
            swap(st[p].pref0, st[p].pref1);
            swap(st[p].suff0, st[p].suff1);
        }
        if (l != r) {
            lazy[right(p)] += lazy[p] & 1;
            lazy[left(p)] += lazy[p] & 1;
        }
        lazy[p] = 0;
    }
    void update(int p, int l, int r, int a, int b, int k) {
        push(p, l, r);
        if (a > r || b < l) return;
        else if (l >= a && r <= b) {
            lazy[p] = k;
            push(p, l, r);
            return;
        }
        int m = (l + r) / 2;
        update(left(p), l, m, a, b, k);
        update(right(p), m + 1, r, a, b, k);
        st[p] = node(st[left(p)], st[right(p)]);
    }
    node query(int p, int l, int r, int a, int b) {
        push(p, l, r);
        if (a > r || b < l) return neutral;
        if (l >= a && r <= b) return st[p];
        int m = (l + r) / 2;
        node p1 = query(left(p), l, m, a, b);
        node p2 = query(right(p), m + 1, r, a, b);
        return node(p1, p2);
    }

  public:
    SegmentTree(string S) {
        size = (int)S.size();
        st.assign(4 * size, neutral);
        lazy.assign(4 * size, 0);
        build(1, 0, size - 1, S);
    }
    node query(int a, int b) { return query(1, 0, size - 1, a, b); }
    void update(int a, int b, int k) { update(1, 0, size - 1, a, b, k); }
};

void solve() {
    cin >> n >> q;
    cin >> s;
    SegmentTree seg(s);
    for (int i = 0; i < q; i++) {
        int t, l, r; cin >> t >> l >> r;
        l--; r--;
        if (t == 1) {
            seg.update(l, r, 1);
        } else {
            cout << seg.query(l, r).res1 << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
