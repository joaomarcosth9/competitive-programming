#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
#define int ll

template <class T> class segtree {
    const T neutral = 1;
    int m;
#define comp(a, b) (ll(a) * ll(b) % m)
  private:
    vector<T> tree;
    int n;

  public:
    segtree(vector<T> st, int _m) {
        int sz = size(st);
        m = _m;
        for (n = 1; n < sz; n <<= 1);
        tree.assign(n << 1, neutral);
        for (int i = 0; i < sz; i++) tree[i + n] = st[i];
        for (int i = n - 1; i; i--) tree[i] = comp(tree[i << 1], tree[i << 1 | 1]);
    }
    void update(int i, int x) {
        tree[i += n] = x % m;
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
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string s; cin >> s;

    segtree<int> seg(a, m);
    cout << seg.query(0, n - 1) << " ";

    int sz = n;

    int itl = 0, itr = n - 1;

    for (int i = 0; i < n; i++) {
        sz--;
        if (s[i] == 'L') {
            seg.update(itl++, 1);
        } else {
            seg.update(itr--, 1);
        }
        if (sz > 0) cout << seg.query(0, n - 1) << " ";
    }

    cout << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
