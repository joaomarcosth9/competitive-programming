#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int long long
typedef long long ll;
typedef pair<int, int> ii;
int testcases = 1;
const int INF = 1.05e9;
const ll INFLL = 4.5e18;
#define endl '\n'
#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#define dbarr(x...)
#endif

int n;
vector<ii> rg;
vector<vector<int>> adj;

pair<ii, ii> dfs(int u, int p = -1) {
    auto [l, r] = rg[u];
    pair<ii, ii> my = {ii(0, l), ii(0, r)};
    for (auto v : adj[u])
        if (v != p) {
            auto [p1, p2] = dfs(v, u);
            auto [w1, l1] = p1;
            auto [w2, l2] = p2;
            auto &[my1, my2] = my;
            my1.first += max(w1 + abs(l1 - l), w2 + abs(l2 - l)); // l
            my2.first += max(w1 + abs(l1 - r), w2 + abs(l2 - r)); // r
        }
    return my;
}

void solve() {
    cin >> n;
    rg.resize(n + 1);
    adj.resize(n + 1);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        rg[i + 1] = {l, r};
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto [res1, res2] = dfs(1);
    cout << max(res1.first, res2.first) << endl;
    rg.clear();
    adj.clear();
}

signed main() {
#ifndef LOCAL_DEBUG
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tsts = 1;
    if (testcases) cin >> tsts;
    while (tsts--) solve();
    return 0;
}
