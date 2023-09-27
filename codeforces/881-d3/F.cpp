#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define int long long
const int maxn = 2e5 + 5;
vector<int> adj[maxn];
typedef long long ll;

struct node {
    ll pref, suff, sum, best;
};

namespace seg {
    const int MAX = maxn;
    node new_node(ll v) { return node{v, v, v, v}; }
    const node NEUTRAL = {0, 0, 0, 0};
    node tree[4 * MAX];
    node merge(node a, node b) {
        ll pref = max(a.pref, a.sum + b.pref);
        ll suff = max(b.suff, b.sum + a.suff);
        ll sum = a.sum + b.sum;
        ll best = max(a.suff + b.pref, max(a.best, b.best));
        return node{pref, suff, sum, best};
    }
    int nn;
    void clear() {
        for (int i = 0; i <= 4 * nn; i++) {
            tree[i] = new_node(0);
        }
        nn = 0;
    }
    int le(int n) { return 2 * n + 1; }
    int ri(int n) { return 2 * n + 2; }
    void build(int n, int esq, int dir, const vector<ll> &v) {
        if (esq == dir)
            tree[n] = new_node(v[esq]);
        else {
            int mid = (esq + dir) / 2;
            build(le(n), esq, mid, v);
            build(ri(n), mid + 1, dir, v);
            tree[n] = merge(tree[le(n)], tree[ri(n)]);
        }
    }
    void build(const vector<ll> &v) {
        nn = v.size();
        build(0, 0, nn - 1, v);
    }
    node query(int n, int esq, int dir, int l, int r) {
        if (esq > r || dir < l) return NEUTRAL;
        if (l <= esq && dir <= r) return tree[n];
        int mid = (esq + dir) / 2;
        return merge(query(le(n), esq, mid, l, r), query(ri(n), mid + 1, dir, l, r));
    }
    node query(int l, int r) {
        assert(l <= r);
        return query(0, 0, nn - 1, l, r);
    }
    void update(int n, int esq, int dir, int x, ll v) {
        if (esq > x || dir < x) return;
        if (esq == dir)
            tree[n] = new_node(v);
        else {
            int mid = (esq + dir) / 2;
            if (x <= mid)
                update(le(n), esq, mid, x, v);
            else
                update(ri(n), mid + 1, dir, x, v);
            tree[n] = merge(tree[le(n)], tree[ri(n)]);
        }
    }
    void update(int x, ll v) { update(0, 0, nn - 1, x, v); }
} // namespace seg

namespace seg2 {
    const int MAX = maxn;
    node new_node(ll v) { return node{v, v, v, v}; }
    const node NEUTRAL = {0, 0, 0, 0};
    node tree[4 * MAX];
    node merge(node a, node b) {
        ll pref = max(a.pref, a.sum + b.pref);
        ll suff = max(b.suff, b.sum + a.suff);
        ll sum = a.sum + b.sum;
        ll best = max(a.suff + b.pref, max(a.best, b.best));
        return node{pref, suff, sum, best};
    }
    int nn;
    void clear() {
        for (int i = 0; i <= 4 * nn; i++) {
            tree[i] = new_node(0);
        }
        nn = 0;
    }
    int le(int n) { return 2 * n + 1; }
    int ri(int n) { return 2 * n + 2; }
    void build(int n, int esq, int dir, const vector<ll> &v) {
        if (esq == dir)
            tree[n] = new_node(v[esq]);
        else {
            int mid = (esq + dir) / 2;
            build(le(n), esq, mid, v);
            build(ri(n), mid + 1, dir, v);
            tree[n] = merge(tree[le(n)], tree[ri(n)]);
        }
    }
    void build(const vector<ll> &v) {
        nn = v.size();
        build(0, 0, nn - 1, v);
    }
    node query(int n, int esq, int dir, int l, int r) {
        if (esq > r || dir < l) return NEUTRAL;
        if (l <= esq && dir <= r) return tree[n];
        int mid = (esq + dir) / 2;
        return merge(query(le(n), esq, mid, l, r), query(ri(n), mid + 1, dir, l, r));
    }
    node query(int l, int r) {
        assert(l <= r);
        return query(0, 0, nn - 1, l, r);
    }
    void update(int n, int esq, int dir, int x, ll v) {
        if (esq > x || dir < x) return;
        if (esq == dir)
            tree[n] = new_node(v);
        else {
            int mid = (esq + dir) / 2;
            if (x <= mid)
                update(le(n), esq, mid, x, v);
            else
                update(ri(n), mid + 1, dir, x, v);
            tree[n] = merge(tree[le(n)], tree[ri(n)]);
        }
    }
    void update(int x, ll v) { update(0, 0, nn - 1, x, v); }
} // namespace seg2

namespace hld {
    const int MAX = maxn;
    int n;
    int nu;
    int t, sz[MAX], pos[MAX], pai[MAX], head[MAX], who[MAX];
    bool e = 0;
    node merge(node a, node b) {
        ll pref = max(a.pref, a.sum + b.pref);
        ll suff = max(b.suff, b.sum + a.suff);
        ll sum = a.sum + b.sum;
        ll best = max(a.suff + b.pref, max(a.best, b.best));
        return node{pref, suff, sum, best};
    }
    node merge2(node a, node b) {
        ll best = max(a.pref + b.pref, max(a.best, b.best));
        return node{best, best, best, best};
    }
    void dfs_sz(int u, int p = -1) {
        sz[u] = 1;
        for (int &v : adj[u])
            if (v != p) {
                dfs_sz(v, u);
                sz[u] += sz[v];
                if (sz[v] > sz[adj[u][0]] || adj[u][0] == p) swap(v, adj[u][0]);
            }
    }
    void dfs_hld(int u, int p = -1) {
        who[t] = u;
        pos[u] = t++;
        for (int v : adj[u])
            if (v != p) {
                pai[v] = u;
                head[v] = (v == adj[u][0] ? head[u] : v);
                dfs_hld(v, u);
            }
    }
    void clear() {
        for (int i = 0; i <= n; i++) {
            sz[i] = pos[i] = who[i] = pai[i] = head[i] = 0;
        }
    }
    void build(int root) {
        dfs_sz(root);
        t = 0;
        pai[root] = root;
        head[root] = root;
        dfs_hld(root);
    }
    void build(int root, vector<int> &v) {
        build(root);
        vector<ll> aux(nu);
        for (int i = 0; i < nu; i++) {
            aux[pos[i]] = v[i];
        }
        seg::build(aux);
    }
    int lca(int u, int v) {
        if (pos[u] > pos[v]) swap(u, v);
        return (head[u] == head[v] ? u : lca(u, pai[head[v]]));
    }
    int desce(int l, int u, int old = -1) {
        if (l == u) {
            return old;
        }
        if (head[l] == head[u]) {
            return who[pos[l] + 1];
        }
        return desce(l, pai[head[u]], u);
    }
    node query(int u, int v) {
        if (pos[u] > pos[v]) swap(u, v);
        if (head[u] == head[v])
            return seg::query(pos[u], pos[v]);
        else {
            node qv = seg::query(pos[head[v]], pos[v]);
            node qu = query(u, pai[head[v]]);
            return merge(qu, qv);
        }
    }
    node queryVAL(int u, int v) {
        if (pos[u] > pos[v]) swap(u, v);
        if (lca(u, v) == u) {
            return query(u, v);
        }
        int l = lca(u, v);
        int l2 = desce(l, u);
        node ul2 = query(u, l2);
        node vl = query(l, v);
        return merge2(ul2, vl);
    }
    void update(int u, ll k) { seg::update(pos[u], k); }
} // namespace hld

namespace hld2 {
    const int MAX = maxn;
    int n;
    int nu;
    int t, sz[MAX], pos[MAX], pai[MAX], head[MAX], who[MAX];
    bool e = 0;
    node merge(node a, node b) {
        ll pref = max(a.pref, a.sum + b.pref);
        ll suff = max(b.suff, b.sum + a.suff);
        ll sum = a.sum + b.sum;
        ll best = max(a.suff + b.pref, max(a.best, b.best));
        return node{pref, suff, sum, best};
    }
    node merge2(node a, node b) {
        ll best = max(a.pref + b.pref, max(a.best, b.best));
        return node{best, best, best, best};
    }
    void dfs_sz(int u, int p = -1) {
        sz[u] = 1;
        for (int &v : adj[u])
            if (v != p) {
                dfs_sz(v, u);
                sz[u] += sz[v];
                if (sz[v] > sz[adj[u][0]] || adj[u][0] == p) swap(v, adj[u][0]);
            }
    }
    void dfs_hld(int u, int p = -1) {
        who[t] = u;
        pos[u] = t++;
        for (int v : adj[u])
            if (v != p) {
                pai[v] = u;
                head[v] = (v == adj[u][0] ? head[u] : v);
                dfs_hld(v, u);
            }
    }
    void clear() {
        for (int i = 0; i <= n; i++) {
            sz[i] = pos[i] = who[i] = pai[i] = head[i] = 0;
        }
    }
    void build(int root) {
        dfs_sz(root);
        t = 0;
        pai[root] = root;
        head[root] = root;
        dfs_hld(root);
    }
    void build(int root, vector<int> &v) {
        build(root);
        vector<ll> aux(nu);
        for (int i = 0; i < nu; i++) {
            aux[pos[i]] = -v[i];
        }
        seg2::build(aux);
    }
    int lca(int u, int v) {
        if (pos[u] > pos[v]) swap(u, v);
        return (head[u] == head[v] ? u : lca(u, pai[head[v]]));
    }
    int desce(int l, int u, int old = -1) {
        if (l == u) {
            return old;
        }
        if (head[l] == head[u]) {
            return who[pos[l] + 1];
        }
        return desce(l, pai[head[u]], u);
    }
    node query(int u, int v) {
        if (pos[u] > pos[v]) swap(u, v);
        if (head[u] == head[v])
            return seg2::query(pos[u], pos[v]);
        else {
            node qv = seg2::query(pos[head[v]], pos[v]);
            node qu = query(u, pai[head[v]]);
            return merge(qu, qv);
        }
    }
    node queryVAL(int u, int v) {
        if (pos[u] > pos[v]) swap(u, v);
        if (lca(u, v) == u) {
            return query(u, v);
        }
        int l = lca(u, v);
        int l2 = desce(l, u);
        node ul2 = query(u, l2);
        node vl = query(l, v);
        return merge2(ul2, vl);
    }
    void update(int u, ll k) { seg2::update(pos[u], k); }
} // namespace hld2

void solve() {
    int n;
    cin >> n;
    int nxt = 1;
    vector<tuple<char, int, int, int>> queries;
    vector<int> vals(n);
    vals[0] = 1;
    for (int i = 0; i < n; i++) {
        char t;
        cin >> t;
        if (t == '+') {
            int u, val;
            cin >> u >> val;
            u--;
            vals[nxt] = val;
            adj[u].emplace_back(nxt);
            adj[nxt].emplace_back(u);
            nxt++;
        } else {
            int u, v, s;
            cin >> u >> v >> s;
            u--, v--;
            queries.emplace_back(t, u, v, s);
        }
    }
    hld::n = n;
    hld2::n = n;
    hld::nu = nxt;
    hld2::nu = nxt;
    hld::build(0, vals);
    hld2::build(0, vals);
    for (int i = 0; i < (int)queries.size(); i++) {
        auto [t, u, v, s] = queries[i];
        if (s == 0) {
            cout << "YES" << '\n';
            continue;
        }
        if (s > 0) {
            node res = hld::queryVAL(u, v);
            cout << (res.best >= s ? "YES" : "NO") << '\n';
        } else {
            node res = hld2::queryVAL(u, v);
            cout << (-res.best <= s ? "YES" : "NO") << '\n';
        }
    }
    hld::clear();
    hld2::clear();
    seg::clear();
    seg2::clear();
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
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
