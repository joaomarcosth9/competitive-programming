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

int res = 0;

void dfs(int u, int r, int p = -1) {
    bool l = 1;
    for (int v : adj[u]) if (v != p) {
        dfs(v, r, u);
        l = 0;
    }
    res += l;
}

void solve() {
    int n; cin >> n;

    vector<int> d(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].eb(v);
        adj[v].eb(u);
        d[u]++;
        d[v]++;
    }

    bool db = 0;
    for (int i = 0; i < n; i++) if (d[i] > 1) {
        debug(i);
        dfs(i, i);
        db = 1;
        break;
    }

    debug(res);

    if (!db) {
        cout << 1 << endl;
    } else {
        cout << (res + 1) / 2 << endl;
    }

    for (int i = 0; i < n; i++) adj[i].clear();
    res = 0;
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
