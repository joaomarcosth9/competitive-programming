#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int MOD = int(1e9) + 7, N = 1e6 + 1;

int phi[N], inv[N], pm[N];
vector<int> d[N];

int solve(int n) {
    int ret = 0;
    for (auto u : d[n]) {
        ret = (ret + int((ll)phi[n / u] * pm[u] % MOD)) % MOD;
    }
    return int((ll)ret * inv[n] % MOD);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m; cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        phi[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        d[i].push_back(i);
        for (int j = i + i; j <= n; j += i) {
            phi[j] -= phi[i];
            d[j].push_back(i);
        }
    }

    pm[0] = 1;
    for (int i = 1; i <= n; i++) {
        pm[i] = int((ll)pm[i - 1] * m % MOD);
    }
    inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        inv[i] = MOD - int((ll)(MOD / i) * inv[MOD % i] % MOD);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + solve(i)) % MOD;
    }
    cout << ans << endl;
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}