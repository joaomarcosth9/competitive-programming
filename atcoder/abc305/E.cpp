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

const int maxn = 2e5 + 5;
int n, m, k;
vector<int> adj[maxn];
bool vis[maxn];

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    priority_queue<ii> q;
    // stamina, node
    for (int i = 0; i < k; i++) {
        int u, h; cin >> u >> h;
        u--;
        q.emplace(h, u);
    }
    while (!q.empty()) {
        auto [H, u] = q.top();
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto v : adj[u]) {
            if (H && !vis[v]) {
                q.emplace(H - 1, v);
            }
        }
    }
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (vis[i]) res.eb(i);
    }
    cout << size(res) << endl;
    for (auto u : res) cout << u + 1 << " ";
    cout << endl;
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
