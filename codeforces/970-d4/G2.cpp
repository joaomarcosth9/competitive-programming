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

const ll INF = 1e18;

struct SegTreeMn {
    ll merge(ll a, ll b) { return max(a, b); }
    const ll neutral = INF;
    int n;
    vector<ll> t, lazy;
    vector<bool> replace;
    inline int lc(int p) { return p * 2; }
    inline int rc(int p) { return p * 2 + 1; }
    void push(int p, int l, int r) {
        if (replace[p]) {
            t[p] = lazy[p];
            if (l != r) {
                lazy[lc(p)] = lazy[p];
                lazy[rc(p)] = lazy[p];
                replace[lc(p)] = true;
                replace[rc(p)] = true;
            }
        } else if (lazy[p] != 0) {
            t[p] += lazy[p];
            if (l != r) {
                lazy[lc(p)] += lazy[p];
                lazy[rc(p)] += lazy[p];
            }
        }
        replace[p] = false;
        lazy[p] = 0;
    }
    void build(int p, int l, int r, const vector<ll> &v) {
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
        lazy.assign(n * 4, 0);
        replace.assign(n * 4, false);
    }
    void build(const vector<ll> &v) { // pra construir com vector
        n = (int)v.size();
        t.assign(n * 4, neutral);
        lazy.assign(n * 4, 0);
        replace.assign(n * 4, false);
        build(1, 0, n - 1, v);
    }
    void build(ll *bg, ll *en) { // pra construir com array de C
        build(vector<ll>(bg, en));
    }
    ll query(int p, int l, int r, int L, int R) {
        push(p, l, r);
        if (l > R || r < L) return neutral;
        if (l >= L && r <= R) return t[p];
        int mid = (l + r) / 2;
        auto ql = query(lc(p), l, mid, L, R);
        auto qr = query(rc(p), mid + 1, r, L, R);
        return merge(ql, qr);
    }
    ll query(int l, int r) { return query(1, 0, n - 1, l, r); }
    void update(int p, int l, int r, int L, int R, ll val, bool repl = 0) {
        push(p, l, r);
        if (l > R || r < L) return;
        if (l >= L && r <= R) {
            lazy[p] = val;
            replace[p] = repl;
            push(p, l, r);
        } else {
            int mid = (l + r) / 2;
            update(lc(p), l, mid, L, R, val, repl);
            update(rc(p), mid + 1, r, L, R, val, repl);
            t[p] = merge(t[lc(p)], t[rc(p)]);
        }
    }
    int find_first(int p, int l, int r, int L, int R, ll val) {
        push(p, l, r);
        if (t[p] >= val) return n;
        if (l > R || r < L) return n;
        int mid = (l + r) / 2;
        if (l >= L && r <= R) {
            if (l != r) {
                push(lc(p), l, mid);
                if (t[lc(p)] < val) {
                    return find_first(lc(p), l, mid, L, R, val);
                }
                return find_first(rc(p), mid + 1, r, L, R, val);
            } else {
                if (t[p] < val) return l;
                return n;
            }
        }
        auto ql = find_first(lc(p), l, mid, L, R, val);
        if (ql != n) return ql;
        return find_first(rc(p), mid + 1, r, L, R, val);
    }
    int find_first(ll val, int i) { return find_first(1, 0, n - 1, i, n - 1, val); }
    void sumUpdate(int l, int r, ll val) { update(1, 0, n - 1, l, r, val, 0); }
    void assignUpdate(int l, int r, ll val) { update(1, 0, n - 1, l, r, val, 1); }
} segmn;

struct SegTree {
    ll merge(ll a, ll b) { return a + b; }
    const ll neutral = 0;
    int n;
    vector<ll> t, lazy;
    vector<bool> replace;
    inline int lc(int p) { return p * 2; }
    inline int rc(int p) { return p * 2 + 1; }
    void push(int p, int l, int r) {
        if (replace[p]) {
            t[p] = lazy[p] * (r - l + 1);
            if (l != r) {
                lazy[lc(p)] = lazy[p];
                lazy[rc(p)] = lazy[p];
                replace[lc(p)] = true;
                replace[rc(p)] = true;
            }
        } else if (lazy[p] != 0) {
            t[p] += lazy[p] * (r - l + 1);
            if (l != r) {
                lazy[lc(p)] += lazy[p];
                lazy[rc(p)] += lazy[p];
            }
        }
        replace[p] = false;
        lazy[p] = 0;
    }
    void build(int p, int l, int r, const vector<ll> &v) {
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
        lazy.assign(n * 4, 0);
        replace.assign(n * 4, false);
    }
    void build(const vector<ll> &v) { // pra construir com vector
        n = (int)v.size();
        t.assign(n * 4, neutral);
        lazy.assign(n * 4, 0);
        replace.assign(n * 4, false);
        build(1, 0, n - 1, v);
    }
    void build(ll *bg, ll *en) { // pra construir com array de C
        build(vector<ll>(bg, en));
    }
    ll query(int p, int l, int r, int L, int R) {
        push(p, l, r);
        if (l > R || r < L) return neutral;
        if (l >= L && r <= R) return t[p];
        int mid = (l + r) / 2;
        auto ql = query(lc(p), l, mid, L, R);
        auto qr = query(rc(p), mid + 1, r, L, R);
        return merge(ql, qr);
    }
    ll query(int l, int r) { return query(1, 0, n - 1, l, r); }
    void update(int p, int l, int r, int L, int R, ll val, bool repl = 0) {
        push(p, l, r);
        if (l > R || r < L) return;
        if (l >= L && r <= R) {
            lazy[p] = val;
            replace[p] = repl;
            push(p, l, r);
        } else {
            int mid = (l + r) / 2;
            update(lc(p), l, mid, L, R, val, repl);
            update(rc(p), mid + 1, r, L, R, val, repl);
            t[p] = merge(t[lc(p)], t[rc(p)]);
        }
    }
    void sumUpdate(int l, int r, ll val) { update(1, 0, n - 1, l, r, val, 0); }
    void assignUpdate(int l, int r, ll val) { update(1, 0, n - 1, l, r, val, 1); }
} seg;

void solve() {
    int n, q, k;
    cin >> n >> k >> q;

    vector<ll> a(n);
    for (ll &x : a) {
        cin >> x;
    }

    for (int i = 0; i < n; i++) {
        a[i] -= i;
    }

    vector<ll> ans(n);

    map<ll, ll> f;
    multiset<ll> res;

    for (int i = 0; i < n; i++) {
        res.insert(0LL);
    }

    auto insert = [&] (ll x) {
        res.erase(res.find(f[x]));
        f[x]++;
        res.insert(f[x]);
    };

    auto remove = [&] (ll x) {
        res.erase(res.find(f[x]));
        f[x]--;
        res.insert(f[x]);
    };

    for (int i = 0; i < k; i++) {
        insert(a[i]);
    }

    ans[0] = k - *res.rbegin();

    for (int i = k; i < n; i++) {
        remove(a[i - k]);
        insert(a[i]);
        ans[i - k + 1] = k - *res.rbegin();
    }

    vector<ll> pref(n + 1);

    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + ans[i];
    }

    vector<vector<pair<int, int>>> Q(n);

    vector<ll> ans_q(q);

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        r -= k - 1;
        Q[l].push_back({r, i});
    }

    seg.build(n + 1);
    segmn.build(n + 1);

    for (int i = n - 1; i >= 0; i--) {
        ll val = ans[i];
        int j = segmn.find_first(val, i + 1);
        j = min(j, n);
        debug(i, val, j);
        segmn.assignUpdate(i, j - 1, val);
        seg.assignUpdate(i, j - 1, val);
        for (auto [r, id] : Q[i]) {
            debug(i, r, seg.query(i, r));
            ans_q[id] = seg.query(i, r);
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans_q[i] << endl;
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
