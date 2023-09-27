#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define endl '\n'
#define cerr                                                                                                           \
    if (false) cerr
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

const int maxn = 1e5 + 5, mod = 1e9 + 7;
int n;
vector<int> adj[maxn];
int dp[maxn][2];

void mul(int &a, int b) {
    ll A = a;
    A *= b;
    A %= mod;
    a = A;
}

void dfs(int u = 0, int p = -1) {
    dp[u][0] = dp[u][1] = 1;
    for (int v : adj[u])
        if (v != p) {
            dfs(v, u);

            mul(dp[u][0], dp[v][1] + dp[v][0]);

            mul(dp[u][1], dp[v][0]);
        }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs();
    cout << (dp[0][0] + dp[0][1]) % mod << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    auto start = chrono::steady_clock::now();
    if (TC) {
        cin >> TC;
        start = chrono::steady_clock::now();
        int TEST = 0;
        while (TEST < TC) {
            cerr << "[Testcase " << TEST + 1 << "]" << endl;
            solve();
            ++TEST;
            cerr << endl;
        }
    } else
        solve();
#ifdef LOCAL_DEBUG
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "\nTime taken: ";
    cerr << chrono::duration<double, milli>(diff).count() << " ms" << endl;
#endif
}
