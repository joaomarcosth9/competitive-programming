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
    struct node {
        int qt;
        ll val;
        node() { }
        node(ll x, int t) {
            if (t == 0) {
                qt = 0;
                val = 0;
            } else {
                qt = 1;
                val = x;
            }
        }
    };
    node merge(node a, node b) {
        if (a.qt == 0) return b;
        if (b.qt == 0) return a;
        node res;
        res.qt = a.qt + b.qt;
        res.val = min(a.val, b.val);
        return res;
    }

    const node neutral = node(0, 0);

    int n;
    vector<node> t;

    void build(int _n) { // pra construir com tamanho, mas vazia
        n = _n;
        t.assign(n << 2, neutral);
    }

    ll query(int u, int l, int r, int qt) {
        if (l == r) {
            return t[u].val;
        }
        int mid = (l + r) >> 1;
        if (t[u << 1 | 1].qt >= qt) {
            return query(u << 1 | 1, mid + 1, r, qt);
        } else {
            return query(u << 1, l, mid, qt - t[u << 1 | 1].qt);
        }
    }
    ll query(int qt) { return query(1, 0, n - 1, qt); }

    void update(int u, int l, int r, int i, ll x, int k) {
        if (l == r) {
            if (k != 0) t[u] = node(x, k);
            else t[u] = neutral;
        } else {
            int mid = (l + r) >> 1;
            if (i <= mid) {
                update(u << 1, l, mid, i, x, k);
            } else {
                update(u << 1 | 1, mid + 1, r, i, x, k);
            }
            t[u] = merge(t[u << 1], t[u << 1 | 1]);
        }
    }
    void update(int i, ll x, int k) { update(1, 0, n - 1, i, x, k); }
};

const int N = 2e5 + 5;
int n;
int a[N], p[N], conv[N];
pair<int, int> b[N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i].first = a[i];
        b[i].second = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    SegTree seg;
    seg.build(n + 1);

    sort(b, b + n);

    for (int i = 0; i < n; i++) {
        conv[b[i].second] = i;
    }

    for (int i = 0; i < n; i++) {
        seg.update(i, b[i].first, 1);
    }

    ll best = 0;
    ll qt = 0;

    for (ll i = 1; i <= (n + 1) / 2; i++) {
        ll now = seg.query(i);
        debug(i, now);
        ll res = now * i;
        if (best < res) {
            best = res;
            qt = i;
        }
        int id = conv[p[i - 1]];
        seg.update(id, 0, 0);
    }

    cout << best << " " << qt << endl;
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
