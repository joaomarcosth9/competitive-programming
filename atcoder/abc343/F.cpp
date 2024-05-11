#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

struct node {
    int ma1, fma1, ma2, fma2;
    node() : ma1(0), fma1(0), ma2(0), fma2(0) { }
    node(int x) : ma1(x), fma1(1), ma2(0), fma2(0) { }
};

node comp(const node& a, const node& b) {
    node res;
    map<int, int, greater<>> f;
    f[a.ma1] += a.fma1;
    f[b.ma1] += b.fma1;
    f[a.ma2] += a.fma2;
    f[b.ma2] += b.fma2;
    int cnt = 0;
    for (auto [k, v] : f) {
        if (cnt == 0) {
            res.ma1 = k;
            res.fma1 = v;
        } else {
            res.ma2 = k;
            res.fma2 = v;
        }
        cnt++;
        if (cnt == 2) break;
    }
    return res;
}

template <class T> class segtree {
    const T neutral = T();
  private:
    vector<T> tree;
    int n;
  public:
    segtree(vector<int> st) {
        int sz = (int)size(st);
        for (n = 1; n < sz; n <<= 1);
        tree.assign(n << 1, neutral);
        for (int i = 0; i < sz; i++) tree[i + n] = node(st[i]);
        for (int i = n - 1; i; i--) tree[i] = comp(tree[i << 1], tree[i << 1 | 1]);
    }
    void update(int i, int x) {
        tree[i += n] = T(x);
        for (i >>= 1; i; i >>= 1) tree[i] = comp(tree[i << 1], tree[i << 1 | 1]);
    }
    T query(int l, int r) {
        T res = neutral;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = comp(res, tree[l++]);
            if (r & 1) res = comp(res, tree[--r]);
        }
        return res;
    }
};

void solve() {
    int n; cin >> n;
    int q; cin >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    segtree<node> seg(a);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int p, x; cin >> p >> x;
            p--;
            /* ms.update(p, x); */
            seg.update(p, x);
        } else {
            int l, r; cin >> l >> r;
            l--; r--;
            auto [mx, fmx, mx2, fmx2] = seg.query(l, r);
            cout << fmx2 << endl;
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
