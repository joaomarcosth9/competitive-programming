#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

int v;
vector<int> A, B;

struct SparseTable {
    int n, LG;
    vector<vector<int>> st;
    int merge(int a, int b) { return max(a, b); }
    const int neutral = (int)2e9;
    void build(const vector<int> &a) {
        n = (int)a.size();
        LG = 32 - __builtin_clz(n);
        st = vector<vector<int>>(LG, vector<int>(n));
        for (int i = 0; i < n; i++) {
            st[0][i] = a[i];
        }
        for (int i = 0; i < LG - 1; i++) {
            for (int j = 0; j + (1 << i) < n; j++) {
                st[i + 1][j] = merge(st[i][j], st[i][j + (1 << i)]);
            }
        }
    }
    int query(int l, int r) {
        if (l > r)
            return neutral;
        int i = 31 - __builtin_clz(r - l + 1);
        return merge(st[i][l], st[i][r - (1 << i) + 1]);
    }
} st;

const int neutral = 2e9;

struct SegTree {
    struct node {
        array<array<int, 2>, 30> L, R;
        int szl, szr;
        int best;
        node() : L({ }), R({ }) {
            szl = szr = 0;
            best = neutral;
        } 
        node(int x, int i) : L({ }), R({ }) {
            if (x == neutral) {
                best = neutral;
                return;
            }
            szl = szr = 0;
            L[szl][0] = i;
            L[szl][1] = B[i];
            R[szr][0] = i;
            R[szr][1] = B[i];
            szr++;
            szl++;
            if (x >= v) {
                best = A[i];
            } else best = neutral;
        }
    };

    node merge(const node& a, const node& b) {
        if (a.szl == 0) {
            return b;
        }
        if (b.szl == 0) {
            return a;
        }

        node res;

        int &best = res.best;
        auto &L = res.L;
        auto &R = res.R;

        best = min(a.best, b.best);

        for (int i = a.szl - 1, j = 0; j < b.szr; j++) {
            while ((i > 0) && (a.L[i - 1][1] | b.R[j][1]) >= v) {
                i--;
            }
            if ((a.L[i][1] | b.R[j][1]) >= v) {
                best = min(best, st.query(a.L[i][0], b.R[j][0]));
            }
        }

        int cor = 0;
        for (int j = 0; j < a.szr; j++) {
            int i = a.R[j][0];
            if ((cor | B[i]) != cor) {
                cor |= B[i];
                R[res.szr][0] = i;
                R[res.szr][1] = cor;
                res.szr++;
            }
        }
        for (int j = 0; j < b.szr; j++) {
            int i = b.R[j][0];
            if ((cor | B[i]) != cor) {
                cor |= B[i];
                R[res.szr][0] = i;
                R[res.szr][1] = cor;
                res.szr++;
            }
        }

        cor = 0;
        for (int j = 0; j < b.szl; j++) {
            int i = b.L[j][0];
            if ((cor | B[i]) != cor) {
                cor |= B[i];
                L[res.szl][0] = i;
                L[res.szl][1] = cor;
                res.szl++;
            }
        }
        for (int j = 0; j < a.szl; j++) {
            int i = a.L[j][0];
            if ((cor | B[i]) != cor) {
                cor |= B[i];
                L[res.szl][0] = i;
                L[res.szl][1] = cor;
                res.szl++;
            }
        }
        return res;
    }

    int n;
    vector<node> t;

    void build(const vector<int> &a) { // pra construir com vector
        n = int(a.size());
        t.resize(n << 1);
        for (int i = 0; i < n; i++) {
            t[i + n] = node(a[i], i);
        }
        for (int i = n - 1; i > 0; i--) {
            t[i] = merge(t[i << 1], t[i << 1 | 1]);
        }
    }

    int query(int l, int r) {
        node ansl, ansr;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ansl = merge(ansl, t[l++]);
            if (r & 1) ansr = merge(t[--r], ansr);
        }
        return merge(ansl, ansr).best;
    }

    void update(int i, int x) {
        B[i] = x;
        t[i + n] = node(B[i], i);
        i += n;
        for (i >>= 1; i > 0; i >>= 1) {
            t[i] = merge(t[i << 1], t[i << 1 | 1]);
        }
    }
} seg;

void solve() {
    int n; cin >> n >> v;
    A.resize(n);
    B.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    st.build(A);
    seg.build(B);

    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int i, x; cin >> i >> x;
            i--;
            seg.update(i, x);
        } else {
            int l, r; cin >> l >> r;
            l--; r--;
            int res = seg.query(l, r);
            cout << (res == neutral ? -1 : res) << " ";
        }
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
