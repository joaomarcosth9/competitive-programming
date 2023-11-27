#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif
#define endl '\n'
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto& x){ return res; }
#define L2(res...) [&](const auto& x, const auto& y){ return res; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

struct Dsu {
    vector<int> p;
    vector<ll> sz;
    Dsu(int n) : p(n), sz(n, 1) {
        for (int i = 0; i < n; i++) p[i] = i;
    }
    int find(int a) { return a == p[a] ? a : p[a] = find(p[a]); }
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (sz[a] > sz[b]) swap(a, b);
        sz[b] += sz[a];
        p[a] = b;
        sz[a] = 0;
        return true;
    }
    int size(int u) { return sz[find(u)]; }
};

const int maxn = 2e5 + 5;
vector<int> adj[maxn];
int a[maxn], freq[maxn], n, m;
bool vis[maxn];

bool solve() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }

    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }

    for (int i = n, it = 0; i >= 1; i--, it++) {
        if (freq[i] > it) return 0;
    }
    if (freq[0] < 1) return 0;

    set<i3> pq;
    
    Dsu d(n);

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            vis[i] = 1;
            for (auto v : adj[i]) {
                if (vis[v] || a[v] == 0) {
                    vis[v] = 1;
                    d.unite(i, v);
                } else {
                    pq.emplace(a[v], v, i);
                }
            }
        }
    }

    vector<vector<int>> pending(n);

    while (pq.size()) {
        auto [qt, u, p] = *begin(pq);
        pq.erase(begin(pq));

        if (vis[u]) continue;

        p = d.find(p);

        if (d.size(p) >= qt) {
            vis[u] = 1;
            d.unite(u, p);
            for (auto v : adj[u]) {
                if (vis[v]) {
                    for (auto w : pending[d.find(v)]) pq.emplace(a[w], w, p);
                    pending[d.find(v)].clear();
                    d.unite(v, p);
                }
            }
            for (auto v : adj[u]) {
                if (!vis[v]) {
                    pq.emplace(a[v], v, p);
                }
            }
        } else {
            p = d.find(p);
            if (p != d.find(p)) {
                for (auto w : pending[p]) pending[d.find(p)].eb(w);
                pending[p].clear();
                p = d.find(p);
            }
            pending[p].eb(u);
        }

    }

    return d.size(d.find(0)) == n;

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        /* solve(); */
        /* cout << solve() << endl; */
        cout << (solve() ? "Yes" : "No") << endl;
        for (int i = 0; i <= n; i++) {
            adj[i].clear();
            vis[i] = freq[i] = a[i] = 0;
        }
        TEST += 1;
    }
}

