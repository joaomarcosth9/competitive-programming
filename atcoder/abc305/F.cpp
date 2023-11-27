#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif
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

const int maxn = 105;
vector<int> adj[maxn];
int n, m;
bool vis[maxn];

void ask(int u, bool first) {
    if (!first) cout << u << endl;
    string K; cin >> K;
    if (K == "OK") {
        exit(0);
    }
    int k = stoi(K);
    if (k == -1) {
        exit(0);
    }
    vector<int> adj_curr;
    for (int i = 0; i < k; i++) {
        int v; cin >> v;
        adj_curr.eb(v);
    }
    adj[u] = adj_curr;
}

void dfs(int u, bool first = 1) {
    ask(u, first);
    first = 0;
    vis[u] = 1;
    for (auto v : adj[u]) {
        if (!vis[v]) {
            dfs(v, 0);
            ask(u, first);
        }
    }
}

void solve() {
    cin >> n >> m;
    dfs(1);
}

signed main() {
    /* ios_base::sync_with_stdio(0); cin.tie(0); */
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

