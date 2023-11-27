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

const int inf = 1e9;

void solve() {
    int n, x; cin >> n >> x;
    x--;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    vector<int> dis0(n, inf);
    dis0[0] = 0;
    queue<int> q;
    q.emplace(0);
    while (q.size()) {
        auto u = q.front();
        q.pop();
        for (auto v : adj[u]) if (dis0[v] > dis0[u] + 1) {
            dis0[v] = dis0[u] + 1;
            q.emplace(v);
        }
    }
    vector<int> disx(n, inf);
    disx[x] = 0;
    int res = 0;
    q.emplace(x);
    debug(dis0);
    while (q.size()) {
        auto u = q.front();
        q.pop();
        res = max({res, disx[u], dis0[u]});
        for (auto v : adj[u]) if (disx[v] > disx[u] + 1) {
            disx[v] = disx[u] + 1;
            if (dis0[v] > disx[v]) {
                q.emplace(v);
            }
        }
    }
    debug(disx);
    cout << res * 2 << endl;
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
