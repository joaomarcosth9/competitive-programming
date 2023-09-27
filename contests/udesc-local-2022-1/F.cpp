#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

typedef long long ll;
const ll LINF = 1e18, MAX = 1e5 + 5;
typedef vector<ll> vi;
vector<int> adj[MAX];

#define f first
#define s second

namespace seg {
    struct node {
        int tam;
        ll sum, lazy;    // lazy pra soma
        ll mi1, mi2, mi; // mi = #mi1
        ll ma1, ma2, ma; // ma = #ma1

        node(ll x = 0) {
            sum = mi1 = ma1 = x;
            mi2 = LINF, ma2 = -LINF;
            mi = ma = tam = 1;
            lazy = 0;
        }
        node(const node &l, const node &r) {
            sum = l.sum + r.sum, tam = l.tam + r.tam;
            lazy = 0;
            if (l.mi1 > r.mi1) {
                mi1 = r.mi1, mi = r.mi;
                mi2 = min(l.mi1, r.mi2);
            } else if (l.mi1 < r.mi1) {
                mi1 = l.mi1, mi = l.mi;
                mi2 = min(r.mi1, l.mi2);
            } else {
                mi1 = l.mi1, mi = l.mi + r.mi;
                mi2 = min(l.mi2, r.mi2);
            }
            if (l.ma1 < r.ma1) {
                ma1 = r.ma1, ma = r.ma;
                ma2 = max(l.ma1, r.ma2);
            } else if (l.ma1 > r.ma1) {
                ma1 = l.ma1, ma = l.ma;
                ma2 = max(r.ma1, l.ma2);
            } else {
                ma1 = l.ma1, ma = l.ma + r.ma;
                ma2 = max(l.ma2, r.ma2);
            }
        }
        void setmax(ll x) {
            if (x <= mi1) return;
            sum += (x - mi1) * mi;
            if (ma1 == mi1) ma1 = x;
            if (ma2 == mi1) ma2 = x;
            mi1 = x;
        }
        void setsum(ll x) {
            mi1 += x, mi2 += x, ma1 += x, ma2 += x;
            sum += x * tam;
            lazy += x;
        }
    };

    node t[4 * MAX];
    int n;
    vector<ll> v;
    vector<ll> D;

    node build(int p = 1, int l = 0, int r = n - 1) {
        if (l == r) return t[p] = {v[l]};
        int m = (l + r) / 2;
        return t[p] = {build(2 * p, l, m), build(2 * p + 1, m + 1, r)};
    }
    void build(vector<ll> &v2) {
        n = v2.size(), v = v2;
        D.assign(4 * MAX, 0);
        memset(t, 0, sizeof(t));
        build();
    }
    void prop(int p, int l, int r) {
        if (l == r) return;
        for (int k = 0; k < 2; k++) {
            if (t[p].lazy) t[2 * p + k].setsum(t[p].lazy);
            t[2 * p + k].setmax(t[p].mi1);
        }
        t[p].lazy = 0;
    }
    pair<pair<ll, ll>, ll> query(int a, int b, int p = 1, int l = 0, int r = n - 1) {
        if (b < l or r < a) return {{LINF, -LINF}, 0};
        if (a <= l and r <= b) return {{t[p].mi1, t[p].ma1}, t[p].sum};
        prop(p, l, r);
        int m = (l + r) / 2;
        auto L = query(a, b, 2 * p, l, m), R = query(a, b, 2 * p + 1, m + 1, r);
        return {{min(L.f.f, R.f.f), max(L.f.s, R.f.s)}, L.s + R.s};
    }
    node updatemax(int a, int b, ll x, int p = 1, int l = 0, int r = n - 1) {
        if (b < l or r < a or t[p].mi1 >= x) return t[p];
        if (a <= l and r <= b and t[p].mi2 > x) {
            t[p].setmax(x);
            return t[p];
        }
        prop(p, l, r);
        int m = (l + r) / 2;
        return t[p] = {updatemax(a, b, x, 2 * p, l, m), updatemax(a, b, x, 2 * p + 1, m + 1, r)};
    }
}; // namespace seg

namespace hld {
    int t, sz[MAX], pos[MAX], time[MAX], pai[MAX], head[MAX];
    bool e = 0;
    ll merge(ll a, ll b) { return (a + b); } // how to merge paths
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
        time[t] = u;
        pos[u] = t++;
        for (int v : adj[u])
            if (v != p) {
                pai[v] = u;
                head[v] = (v == adj[u][0] ? head[u] : v);
                dfs_hld(v, u);
            }
    }
    void build(int root) {
        dfs_sz(root);
        t = 0;
        pai[root] = root;
        head[root] = root;
        dfs_hld(root);
    }
    void build(int root, vector<ll> &v) {
        build(root);
        vector<ll> aux(v.size());
        for (int i = 0; i < (int)v.size(); i++) aux[pos[i]] = v[i];
        seg::build(aux);
    }
    ll query(int u, int v) {
        if (pos[u] > pos[v]) swap(u, v);
        if (head[u] == head[v])
            return seg::query(pos[u], pos[v]).second;
        else {
            ll qv = seg::query(pos[head[v]], pos[v]).second;
            ll qu = query(u, pai[head[v]]);
            return merge(qu, qv);
        }
    }
    void update(int u, int v, ll k) {
        if (pos[u] > pos[v]) swap(u, v);
        if (head[u] == head[v])
            seg::updatemax(pos[u], pos[v], k);
        else {
            seg::updatemax(pos[head[v]], pos[v], k);
            update(u, pai[head[v]], k);
        }
    }
    ll query_subtree(int u) { return seg::query(pos[u], pos[u] + sz[u] - 1).second; }
    int kth(int u, int k) {
        if (u == 0) return 0;
        int dis = pos[u] - pos[head[u]];
        if (dis < k) {
            return kth(pai[head[u]], k - dis - 1);
        } else {
            return time[pos[u] - k];
        }
    }
} // namespace hld

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for (int i = 1; i < n; i++) {
        int u;
        cin >> u;
        adj[u - 1].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    hld::build(0, v);
    while (q--) {
        int o;
        cin >> o;
        if (o == 1) {
            int u;
            cin >> u;
            u--;
            cout << hld::query_subtree(u) << endl;
        } else if (o == 0) {
            int u, k, w;
            cin >> u >> k >> w;
            u--, k--;
            int _kth = hld::kth(u, k);
            hld::update(u, _kth, w);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
