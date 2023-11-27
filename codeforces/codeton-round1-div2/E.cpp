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

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    vector<int> deg(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        deg[u]++;
        deg[v]++;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    vector<int> c(n);
    queue<ii> q;
    q.emplace(1, 1);
    while (q.size()) {
        auto [u, cc] = q.front();
        q.pop();
        c[u] = cc;
        for (auto v : adj[u]) if (!c[v]) {
            q.emplace(v, cc ^ 3);
        }
    }
    for (int i = 0; i < n; i++) cout << deg[i] * (c[i] == 1 ? 1 : -1) << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
