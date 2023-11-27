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
#define int ll
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

const int maxn = 105;
const ll INF = (ll)1e18 + 5;
vector<ii> adj[maxn];
bool vis2[maxn];

bool dfs(int u, int t) {
    vis2[u] = 1;
    bool ret = u != t;
    for (auto [v, _] : adj[u]) if (!vis2[v]) {
        ret &= dfs(v, t);
    }
    return ret;
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        adj[u].eb(v, w);
        adj[v].eb(u, w);
    }

    if (dfs(0, n - 1)) {
        cout << "inf" << endl;
        return;
    }

    set<tuple<int, int, int>> pq;
    vector<int> dis(n, INF);
    dis[n - 1] = 0;

    pq.emplace(0, n - 1, -1);
    string res = string(n, '1');
    vector<pair<string, ll>> games;
    map<int, ll> vis;
    vis[0] = 1;

    ll mxv = 0;

    while (!pq.empty()) {
        auto [w, u, ed] = *begin(pq);
        pq.erase(begin(pq));
        if (dis[u] < w) continue;

        if (!vis[w]) {
            games.eb(res, w - mxv);
            vis[w] = 1;
        }

        if (u == 0) break;

        for (int i = 0; i < n; i++) if (dis[i] <= w) res[i] = '0';
        mxv = w;

        debug(u, adj[u]);

        for (auto [v, ww] : adj[u]) {
            debug(v, res[v]);
            if (res[v] == '1') {
                dis[v] = min(dis[v], w + ww);
                pq.emplace(w + ww, v, ww);
            }
        }
    }
    cout << dis[0] << " " << games.size() << endl;

    ll s = 0;
    for (auto u : games) s += u.second;
    assert(s == dis[0]);
    for (auto u : games) cout << u.first << " " << u.second << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
