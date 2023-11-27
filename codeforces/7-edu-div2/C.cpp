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

struct node {
    int minn, maxx, mni, mxi;
    node () : minn(INT_MAX), maxx(INT_MIN), mni(-1), mxi(-1) { }
    node (int u, int i) : minn(u), maxx(u), mni(i), mxi(i) { }
    node (node &l, node &r) {
        if (l.minn < r.minn) {
            minn = l.minn;
            mni = l.mni;
        } else {
            minn = r.minn;
            mni = r.mni;
        }
        if (l.maxx > r.maxx) {
            maxx = l.maxx;
            mxi = l.mxi;
        } else {
            maxx = r.maxx;
            mxi = r.mxi;
        }
    }
};

template <class T> class segtree {
  private:
    vector<T> tree;
    int n;

  public:
    segtree(vector<T> st) {
        int sz = size(st);
        for (n = 1; n < sz; n <<= 1);
        tree.resize(n << 1);
        for (int i = 0; i < sz; i++) tree[i + n] = st[i];
        for (int i = n - 1; i; i--) tree[i] = node(tree[i << 1], tree[i << 1 | 1]);
    }
    void update(int i, int x) {
        tree[i += n] += x;
        for (i >>= 1; i; i >>= 1) tree[i] = node(tree[i << 1], tree[i << 1 | 1]);
    }
    T query(int l, int r) {
        T res;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = node(res, tree[l++]);
            if (r & 1) res = node(res, tree[--r]);
        }
        return res;
    }
};

void solve() {
    int n; cin >> n;
    int q; cin >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<node> v;
    for (int i = 0; i < n; i++) {
        v.emplace_back(a[i], i);
    }
    segtree<node> seg(v);
    while (q--) {
        int l, r, x; cin >> l >> r >> x;
        l--; r--;
        auto nodo = seg.query(l, r);
        if (x == nodo.minn && x == nodo.maxx) {
            cout << -1 << endl;
        } else {
            if (x != nodo.minn) {
                cout << nodo.mni + 1 << endl;
            } else {
                cout << nodo.mxi + 1 << endl;
            }
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
