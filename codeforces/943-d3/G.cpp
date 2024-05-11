#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
#define int ll
using ll = long long;

vector<int> get_z(string &s) {
    int n = (int)s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
    return z;
}

struct SegTree {
    ll merge(ll a, ll b) { return max(a, b); }
    const ll neutral = INT_MIN;

    int n;
    vector<ll> t;

    void build(int u, int l, int r, const vector<ll> &v) {
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

    void build(const vector<ll> &v) { // pra construir com vector
        n = int(v.size());
        t.assign(n << 2, neutral);
        build(1, 0, n - 1, v);
    }
    void build(ll *bg, ll *en) { // pra construir com array de C
        build(vector<ll>(bg, en));
    }

    ll query(int u, int l, int r, int L, int R) {
        if (l > R || r < L) {
            return neutral;
        }
        if (l >= L && r <= R) {
            return t[u];
        }
        int mid = (l + r) >> 1;
        ll ql = query(u << 1, l, mid, L, R);
        ll qr = query(u << 1 | 1, mid + 1, r, L, R);
        return merge(ql, qr);
    }
    ll query(int l, int r) { return query(1, 0, n - 1, l, r); }

    void update(int u, int l, int r, int i, ll x) {
        if (l == r) {
            t[u] = x; // substitui
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

    void update(int i, ll x) { update(1, 0, n - 1, i, x); }

    bool found = 0;

    int ffirst(int u, int l, int r, int L, int R, int x) {
        if (l == r) {
            found = 1;
            return l;
        }
        int mid = (l + r) >> 1;
        if (t[u << 1] >= x) return ffirst(u << 1, l, mid, L, R, x);
        return ffirst(u << 1 | 1, mid + 1, r, L, R, x);
    }

    int first(int u, int l, int r, int L, int R, int x) {
        if (found) return n + 5;
        if (l > R || r < L) {
            return n + 5;
        }
        if (l >= L && r <= R) {
            if (t[u] < x || found) return n + 5;
            return ffirst(u, l, r, L, R, x);
        }
        int mid = (l + r) >> 1;
        int ql = first(u << 1, l, mid, L, R, x);
        int qr = first(u << 1 | 1, mid + 1, r, L, R, x);
        return min(ql, qr);
    }

    int first(int x, int i) {
        found = 0;
        if (query(0, n - 1) < x) return n + 5;
        return first(1, 0, n - 1, i, n - 1, x);
    }

};

void solve() {
    int n, L, R; cin >> n >> L >> R;
    string s; cin >> s;
    auto z = get_z(s);
    SegTree seg;
    seg.build(z);
    int k = L;
    int l = 1, r = n;
    vector<int> res(n + 1, 0);
    debug(z);
    vector<int> mx(n + 1, INT_MIN);
    for (int len = 1; len < n; len++) {
        int j = len;
        int qt = 1;
        while (j < n) {
            // j = first gte len after z[j]
            j = seg.first(len, j);
            if (j >= n) break;
            j += len;
            qt++;
        }
        debug(len, qt);
        mx[qt] = max(mx[qt], len);
        // res[f[qt]] = len, so for all j <= qt, res[j] = max(res[j], len)
    }
    debug(mx);
    for (int i = n - 1; i >= 0; i--) {
        mx[i] = max(mx[i], mx[i + 1]);
    }
    debug(mx);
    for (int i = n; i >= 1; i--) {
        res[i] = max(res[i], mx[i]);
    }
    res[1] = n;
    for (int i = L; i <= R; i++) cout << res[i] << " ";
    cout << endl;
}

int32_t main() {
    /* cin.tie(0)->sync_with_stdio(0); */
    int TC; cin >> TC;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
