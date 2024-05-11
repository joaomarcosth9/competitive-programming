#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

struct SegTree {
    int merge(int a, int b) { return a | b; }
    const int neutral = 0;

    int n;
    vector<int> t;

    void build(int u, int l, int r, const vector<int> &v) {
        if (l == r) {
            t[u] = v[l];
        } else {
            int mid = (l + r) >> 1;
            build(u << 1, l, mid, v);
            build(u << 1 | 1, mid + 1, r, v);
            t[u] = merge(t[u << 1], t[u << 1 | 1]);
        }
    }

    void build(int _n) { // pra construir com tamanho, mas vazia
        n = _n;
        t.assign(n << 2, neutral);
    }

    void build(const vector<int> &v) { // pra construir com vector
        n = int(v.size());
        t.assign(n << 2, neutral);
        build(1, 0, n - 1, v);
    }
    void build(int *bg, int *en) { // pra construir com array de C
        build(vector<int>(bg, en));
    }

    int query(int u, int l, int r, int L, int R) {
        if (l > R || r < L) {
            return neutral;
        }
        if (l >= L && r <= R) {
            return t[u];
        }
        int mid = (l + r) >> 1;
        int ql = query(u << 1, l, mid, L, R);
        int qr = query(u << 1 | 1, mid + 1, r, L, R);
        return merge(ql, qr);
    }
    int query(int l, int r) { return query(1, 0, n - 1, l, r); }

    void update(int u, int l, int r, int i, int x) {
        if (l == r) {
            t[u] += x; // soma
            // t[u] = x; // substitui
        } else {
            int mid = (l + r) >> 1;
            if (i <= mid) {
                update(u << 1, l, mid, i, x);
            } else {
                update(u << 1 | 1, mid + 1, r, i, x);
            }
            t[u] = merge(t[u << 1], t[u << 1 | 1]);
        }
    }
    void update(int i, int x) { update(1, 0, n - 1, i, x); }
};

void solve() {
    int n; cin >> n;
    vector<int> L(n), R(n);
    for (int i = 0; i < n; i++) {
        cin >> L[i] >> R[i];
    }

    vector<int> always(n);
    vector<vector<int>> bit(30, vector<int>(n));

    for (int i = 0; i < n; i++) {
        int ac = 0;
        bool flg = 0;
        for (int b = 29; b >= 0; b--) {
            int bl = (L[i] >> b) & 1;
            int br = (R[i] >> b) & 1;
            if (bl != br) {
                bit[b][i] = 1;
                L[i] = 0;
            } else {
                ac |= (bl << b);
            }
        }
        always[i] = ac;
    }

    SegTree st;
    st.build(always);

    for (int b = 29; b >= 0; b--) {
        for (int i = 1; i < n; i++) {
            bit[b][i] += bit[b][i - 1];
        }
    }

    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        l--; r--;
        int ans = st.query(l, r);
        debug(l, r, ans);
        for (int b = 29; b >= 0; b--) {
            int cnt = bit[b][r] - (l ? bit[b][l - 1] : 0);
            if (cnt == 0) continue;
            debug(b, cnt);
            if (((ans >> b) & 1) || cnt > 1) {
                ans |= (1 << (b + 1)) - 1;
                break;
            } else {
                ans |= (1 << b);
            }
        }
        cout << ans << " \n"[q == 0];
    }
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
