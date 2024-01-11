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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, ll> ii;
typedef tuple<ll, int, ll> i3;

const int maxn = 1100;
const ll inf = 1e10;
int n, m;
ll s[maxn];
vector<ii> adj[maxn];
ll dis[maxn][maxn];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < maxn; j++) dis[i][j] = inf;

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        adj[u].eb(v, w);
        adj[v].eb(u, w);
    }
    for (int i = 0; i < n; i++) cin >> s[i];

    set<i3> pq;

    pq.emplace(0, 0, 1e3 + 5);

    while (pq.size()) {
        auto [w, u, b] = *begin(pq);
        pq.erase(begin(pq));

        if (dis[u][b] < w) continue;

        dis[u][b] = w;

        b = min(b, s[u]);

        for (auto [v, ww] : adj[u]) {
            if (dis[v][b] > w + (ww * b)) {
                pq.emplace(w + (ww * b), v, b);
            }
        }
    }

    cout << *min_element(dis[n - 1], dis[n - 1] + 1001) << endl;

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
        for (int i = 0; i < n; i++) adj[i].clear();
        for (int i = 0; i < n; i++) s[i] = 0;
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
