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
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

const int maxn = 2e5 + 5;
vector<int> adj[maxn];
int n, sz[maxn];

void dfs_sz(int u) {
    sz[u] = 1;
    for (int v : adj[u]) {
        dfs_sz(v);
        sz[u] += sz[v];
    }
}

int dfs(int u, ll mx) {
    int now = -1, who = -1;
    ll sum = 0, osum = 0;
    for (auto v : adj[u]) {
        sum += sz[v];
        if (sz[v] > now) {
            now = sz[v];
            who = v;
        }
    }

    if (sum == 0) return 0;
    osum = sum - now;
    debug(u, mx, sum, who, now, osum);

    if (now >= osum) {
        return min<ll>(osum + dfs(who, now - osum), mx / 2);
    } else {
        return min<ll>(sz[u] - 1, mx) / 2;
    }

}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int p; cin >> p;
        p--;
        adj[p].eb(i);
    }
    for (int i = 0; i < n; i++) {
        debug(i, adj[i]);
    }
    dfs_sz(0);
    cout << dfs(0, n) << endl;
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
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
