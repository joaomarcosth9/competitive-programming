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
    int merge(int a, int b) { return a + b; }
    const int neutral = 0;

    inline int lc(int p) { return p * 2; }
    inline int rc(int p) { return p * 2 + 1; }

    int n;
    vector<int> t;

    void build(int p, int l, int r, const vector<int> &v) {
        if (l == r) {
            t[p] = v[l];
        } else {
            int mid = (l + r) / 2;
            build(lc(p), l, mid, v);
            build(rc(p), mid + 1, r, v);
            t[p] = merge(t[lc(p)], t[rc(p)]);
        }
    }

    void build(int _n) { // pra construir com tamanho, mas vazia
        n = _n;
        t.assign(n * 4, neutral);
    }

    void build(const vector<int> &v) { // pra construir com vector
        n = int(v.size());
        t.assign(n * 4, neutral);
        build(1, 0, n - 1, v);
    }
    void build(int *bg, int *en) { // pra construir com array de C
        build(vector<int>(bg, en));
    }

    int query(int p, int l, int r, int L, int R) {
        if (l > R || r < L) return neutral;
        if (l >= L && r <= R) return t[p];
        int mid = (l + r) / 2;
        auto ql = query(lc(p), l, mid, L, R);
        auto qr = query(rc(p), mid + 1, r, L, R);
        return merge(ql, qr);
    }
    int query(int l, int r) { return query(1, 0, n - 1, l, r); }

    void update(int p, int l, int r, int i, int x, bool repl) {
        if (l == r) {
            if (repl) t[p] = x; // substitui
            else t[p] += x;     // soma
        } else {
            int mid = (l + r) / 2;
            if (i <= mid) update(lc(p), l, mid, i, x, repl);
            else update(rc(p), mid + 1, r, i, x, repl);
            t[p] = merge(t[lc(p)], t[rc(p)]);
        }
    }
    void sumUpdate(int i, int x) { update(1, 0, n - 1, i, x, 0); }
    void assignUpdate(int i, int x) { update(1, 0, n - 1, i, x, 1); }
} seg;

void solve() {
    int n, q;
    cin >> n >> q;

    seg.build(2 * n + 1);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // se eu luto com um monstro com k = x, pra qualquer k >= x eu luto tb

    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        int L = 0, R = n + 1;
        while (R - L > 1) {
            int M = L + (R - L) / 2;
            int P = (i - seg.query(M + 1, 2 * n)) / M + 1;
            debug(i, M, P);
            if (P > a[i]) {
                L = M;
            } else {
                R = M;
            }
        }
        debug(i, R);
        ans[i] = R;
        seg.sumUpdate(R, 1);
    }

    debug(a);
    debug(ans);

    while (q--) {
        int i, k;
        cin >> i >> k;
        i--;
        cout << (k >= ans[i] ? "YES" : "NO") << endl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}