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

const int maxn = 5e5 + 5;
int dep[maxn];
vector<int> adj[maxn];
int n;
vector<int> leafs;

void dfs(int u, int p, int d = 0) {
    dep[u] = d;
    bool leaf = 1;
    for (int v : adj[u]) if (v != p) {
        leaf = 0;
        dfs(v, u, d + 1);
    }
    if (leaf) leafs.eb(u);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    int res = 0;
    for (auto v : adj[0]) {
        leafs.clear();
        dfs(v, 0);
        sort(all(leafs), L2(dep[x] < dep[y]));
        int now = dep[leafs[0]];
        for (int i = 1; i < (int)size(leafs); i++) {
            now = max(now + 1, dep[leafs[i]]);
        }
        res = max(res, now + 1);
    }
    cout << res << endl;
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
