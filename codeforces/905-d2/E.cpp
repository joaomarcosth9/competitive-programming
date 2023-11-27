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
    int n, t; cin >> n >> t;
    vector<vector<ii>> adj(n);
    for (int i = 0; i < t; i++) {
        int m; cin >> m;
        for (int j = 0; j < m; j++) {
            int u, v; cin >> u >> v;
            u--; v--;
            adj[u].eb(v, i);
            adj[v].eb(u, i);
        }
    }
    int k; cin >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++) cin >> a[i];
    vector<vector<int>> pos(t);
    for (int i = 0; i < k; i++) pos[a[i] - 1].eb(i);
    set<ii> pq;
    vector<int> dis(n, -1);
    pq.emplace(0, 0);
    while (pq.size()) {
        auto [w, u] = *begin(pq);
        pq.erase(begin(pq));
        if (dis[u] > -1) continue;
        dis[u] = w;
        for (auto [v, id] : adj[u]) {
            auto ub = lower_bound(all(pos[id]), w);
            if (ub != end(pos[id]) && (dis[v] == -1)) {
                pq.emplace(*ub + 1, v);
            }
        }
    }
    cout << dis[n - 1] << endl;
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
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
