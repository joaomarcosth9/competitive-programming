#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

void solve() {
    int n; cin >> n;

    vector<ll> a(n);
    for (ll &i : a) {
        cin >> i;
    }

    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<ll>> dp(n, vector<ll>(21, -1));

    function<ll(int, int, int)> dfs = [&] (int u, int p, int cnt) {
        if (dp[u][cnt] != -1) return dp[u][cnt];
        ll me = a[u] * cnt;
        for (int v : adj[u]) if (v != p) {
            ll other = 8e18;
            for (int j = 1; j < 21; j++) {
                if (j != cnt) {
                    other = min(other, dfs(v, u, j));
                }
            }
            me += other;
        }
        return dp[u][cnt] = me;
    };

    function<void(ll)> print = [&] (ll x) {
        string res;
        if (x == 0) {
            cout << 0 << endl;
            return;
        }
        while (x > 0) {
            res += '0' + x % 10;
            x /= 10;
        }
        reverse(res.begin(), res.end());
        cout << res << endl;
    };

    ll ans = 8e18;
    for (int i = 1; i < 21; i++) {
        ans = min(ans, dfs(0, -1, i));
    }

    cout << ans << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
