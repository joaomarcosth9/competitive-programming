#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long ll;

// 0 - INDEXED
// segtree<TIPO> seg(*start, *end);
template <class T> class segtree {
    const T neutral = 0;
#define comp(a, b) ((a) + (b))
  private:
    vector<T> tree;
    int n;

  public:
    segtree(int _n) : n(_n) { tree.assign(2 * n + 10, 0); }
    segtree(T *st, T *en) {
        int sz = int(en - st);
        for (n = 1; n < sz; n <<= 1)
            ;
        tree.assign(n << 1, neutral);
        for (int i = 0; i < sz; i++) tree[i + n] = st[i];
        for (int i = n + sz - 1; i; i--) tree[i >> 1] = comp(tree[i >> 1], tree[i]);
    }
    void update(int i, T x) {
        tree[i += n] = x;
        for (i >>= 1; i; i >>= 1) tree[i] = comp(tree[i << 1], tree[1 + (i << 1)]);
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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> seg(m);
    for (int i = 0; i < m; i++) {
        auto &[l, r] = seg[i];
        cin >> l >> r;
        l--, r--;
    }
    int q;
    cin >> q;
    vector<int> Q(q);
    for (int &i : Q) {
        cin >> i;
        i--;
    }
    vector<int> L(m), R(m);
    for (int i = 0; i < m; i++) R[i] = q - 1;
    vector<vector<int>> has(q);
    for (int i = 0; i < m; i++) {
        has[(q - 1) / 2].emplace_back(i);
    }
    vector<int> ans(m, -1);
    /* vector<int> curr(n); */
    while (1) {
        segtree<int> t(n);
        bool foi = 0;
        for (int i = 0; i < q; i++) {
            debug(i);
            t.update(Q[i], 1);
            if (has[i].size()) {
                foi = 1;
                for (auto u : has[i]) {
                    auto [l, r] = seg[u];
                    int o = t.query(l, r);
                    int z = (r - l + 1) - o;
                    if (o > z) {
                        // deu bom aqui
                        ans[u] = i;
                        R[u] = i - 1;
                    } else {
                        L[u] = i + 1;
                    }
                    if (L[u] <= R[u]) {
                        int mid = (L[u] + R[u]) / 2;
                        has[mid].emplace_back(u);
                    }
                }
            }
            has[i].clear();
        }
        if (!foi) break;
    }
    debug(ans);
    if (ans == vector<int>(m, -1)) {
        cout << -1 << '\n';
    } else {
        int res = INT_MAX;
        for (auto u : ans) {
            if (u == -1) continue;
            res = min(res, u);
        }
        cout << res + 1 << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
