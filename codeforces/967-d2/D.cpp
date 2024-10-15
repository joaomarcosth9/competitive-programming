#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
using ii = pair<int, int>;

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

struct SegTree {
    int merge(int a, int b) { return min(a, b); }
    const int neutral = 1e9;

    int n;
    vector<int> t, lazy;
    vector<bool> replace;

    inline int lc(int p) { return p * 2; }
    inline int rc(int p) { return p * 2 + 1; }

    void push(int p, int l, int r) {
        if (lazy[p] != 0) {
            t[p] += lazy[p];
            if (l != r) {
                lazy[lc(p)] += lazy[p];
                lazy[rc(p)] += lazy[p];
            }
        }
        lazy[p] = 0;
    }

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
        lazy.assign(n * 4, 0);
        replace.assign(n * 4, false);
    }

    void build(const vector<int> &v) { // pra construir com vector
        n = (int)v.size();
        t.assign(n * 4, neutral);
        lazy.assign(n * 4, 0);
        replace.assign(n * 4, false);
        build(1, 0, n - 1, v);
    }
    void build(int *bg, int *en) { // pra construir com array de C
        build(vector<int>(bg, en));
    }

    int query(int p, int l, int r, int L, int R) {
        push(p, l, r);
        if (l > R || r < L) return neutral;
        if (l >= L && r <= R) return t[p];
        int mid = (l + r) / 2;
        auto ql = query(lc(p), l, mid, L, R);
        auto qr = query(rc(p), mid + 1, r, L, R);
        return merge(ql, qr);
    }
    int query(int l, int r) { return query(1, 0, n - 1, l, r); }

    void update(int p, int l, int r, int L, int R, int val, bool repl) {
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
    int find_first(int p, int l, int r, int x) {
        push(p, l, r);
        if (l == r) {
            if (t[p] < x) {
                return l;
            } else {
                return n;
            }
        }
        int mid = (l + r) / 2;
        if (l < r) {
            push(lc(p), l, mid);
            push(rc(p), mid + 1, r);
        }
        if (t[lc(p)] < x) {
            return find_first(lc(p), l, mid, x);
        }
        return find_first(rc(p), mid + 1, r, x);
    }
    int find_first(int x) {
        return find_first(1, 0, n - 1, x);
    }
    void sumUpdate(int l, int r, int val) { update(1, 0, n - 1, l, r, val, 0); }
    void assignUpdate(int l, int r, int val) { update(1, 0, n - 1, l, r, val, 1); }
};

struct node {
    int id_mn, id_mx, mn, mx;
    node (int val = 0, int i = -1) : id_mn(i), id_mx(i), mn(val), mx(val) {}
};

node merge(const node& a, const node& b) {
    node c;
    if (a.id_mn == -1) return b;
    if (b.id_mn == -1) return a;
    if (a.mx > b.mx) {
        c.mx = a.mx;
        c.id_mx = a.id_mx;
    } else if (b.mx > a.mx) {
        c.mx = b.mx;
        c.id_mx = b.id_mx;
    } else {
        c.mx = a.mx;
        c.id_mx = min(a.id_mx, b.id_mx);
    }
    if (a.mn < b.mn) {
        c.mn = a.mn;
        c.id_mn = a.id_mn;
    } else if (b.mn < a.mn) {
        c.mn = b.mn;
        c.id_mn = b.id_mn;
    } else {
        c.mn = a.mn;
        c.id_mn = min(a.id_mn, b.id_mn);
    }
    return c;
}

struct SegTreeMinMax {
    const node neutral = node();

    inline int lc(int p) { return p * 2; }
    inline int rc(int p) { return p * 2 + 1; }

    int n;
    vector<node> t;

    void build(int p, int l, int r, const vector<ii> &v) {
        if (l == r) {
            t[p] = node(v[l].first, v[l].second);
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

    void build(const vector<ii> &v) { // pra construir com vector
        n = int(v.size());
        t.assign(n * 4, neutral);
        build(1, 0, n - 1, v);
    }
    void build(ii *bg, ii *en) { // pra construir com array de C
        build(vector<ii>(bg, en));
    }

    node query(int p, int l, int r, int L, int R) {
        if (l > R || r < L) return neutral;
        if (l >= L && r <= R) return t[p];
        int mid = (l + r) / 2;
        auto ql = query(lc(p), l, mid, L, R);
        auto qr = query(rc(p), mid + 1, r, L, R);
        return merge(ql, qr);
    }
    node query(int l, int r) { return query(1, 0, n - 1, l, r); }

    void update(int p, int l, int r, int i, ii x, bool repl) {
        if (l == r) {
            t[p] = node(x.first, x.second); // substitui
        } else {
            int mid = (l + r) / 2;
            if (i <= mid) update(lc(p), l, mid, i, x, repl);
            else update(rc(p), mid + 1, r, i, x, repl);
            t[p] = merge(t[lc(p)], t[rc(p)]);
        }
    }
    void sumUpdate(int i, ii x) { update(1, 0, n - 1, i, x, 0); }
    void assignUpdate(int i, ii x) { update(1, 0, n - 1, i, x, 1); }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    map<int, int> vis;

    for (int i = 0; i < n; i++) {
        vis[a[i]] = 1;
    }

    int len = (int)vis.size();

    if (len & 1) {
        // -1, 1, -1, 1, -1
    } else {
        // -1, 1, -1, 1
    }

    vector<int> suf_dist(n + 2);
    vis.clear();

    for (int i = n - 1; i >= 0; i--) {
        if (!vis.count(a[i])) {
            vis[a[i]] = i;
        }
        suf_dist[i] = (int)vis.size();
    }

    SegTree seg_suf;
    SegTreeMinMax seg;

    vector<ii> b(n);
    vector<vector<int>> pos(n + 1);

    for (int i = 0; i < n; i++) {
        b[i] = {a[i], i};
        pos[a[i]].push_back(i);
    }

    seg_suf.build(suf_dist);
    seg.build(b);

    int now = 1;

    int olen = len;

    vector<int> res;

    debug(suf_dist);

    int i = 0;
    debug(a);

    vector<int> used(n + 1);

    while (len > 0) {
        debug(len, i);
        assert(suf_dist[i] >= len);
        int ans = seg_suf.find_first(len) - 1;
        debug(i, now, res);
        debug(i, ans);

        if (now == 1) {
            // cara vai ser -1, entao o maximo possivel
            auto [_, j, __, mx] = seg.query(i, ans);
            res.push_back(mx);

            debug(mx);
            // assert(!used[mx]);
            used[mx] = 1;

            // tenho q tirar o mx pq nao posso mais usalo
            // subtraio um de suf_dist[0, vis[mx]]
            seg_suf.sumUpdate(0, vis[mx], -1);

            for (auto u : pos[mx]) {
                seg.assignUpdate(u, {0, -1});
            }

            i = j + 1;
        } else {
            // cara vai ser 1, entao o minimo possivel
            auto [j, _, mn, __] = seg.query(i, ans);
            res.push_back(mn);

            debug(mn);

            // assert(!used[mn]);
            used[mn] = 1;

            // tenho q tirar o mn pq nao posso mais usalo
            // subtraio um de suf_dist[0, vis[mn]]
            seg_suf.sumUpdate(0, vis[mn], -1);

            for (auto u : pos[mn]) {
                seg.assignUpdate(u, {0, -1});
            }

            i = j + 1;
        }
        now ^= 1;
        len--;
    }
    debug(res);

    cout << olen << endl;
    output_vector(res);

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}