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
vector<int> adj[maxn];
int color[maxn];
bool db = 1;

void dfs(int u, int c) {
    color[u] = c;
    for (int v : adj[u]) {
        if (!color[v]) dfs(v, c ^ 2 ^ 1);
        else if (color[v] == color[u]) db = 0;
    }
}

bool solve() {
    int n, m; cin >> n >> m;
    vector<int> a(m), b(m);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;
    for (int i = 0; i < m; i++) {
        adj[a[i]].eb(b[i]);
        adj[b[i]].eb(a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (color[i]) continue;
        dfs(i, 1);
    }
    return db;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        /* solve(); */
        /* cout << solve() << endl; */
        cout << (solve() ? "Yes" : "No") << endl;
        TEST += 1;
    }
}
