#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long;

const int MOD = (int)1e9 + 7, MAX = 1e6 + 5;

ll binpow(ll b, ll e) {
    ll res = 1;
    while (e > 0) {
        if (e & 1) res = res * b % MOD;
        b = b * b % MOD;
        e >>= 1;
    }
    return res;
}
ll inv(ll x) { return binpow(x, MOD - 2); }

ll fat[MAX], ifat[MAX];

ll ncr(ll n, ll r) {
    if (r > n) return 0;
    return (fat[n] * ifat[r] % MOD) * ifat[n - r] % MOD;
}

ll dp[MAX];

void solve() {
    int n, k, m; cin >> n >> m >> k;

    cout << binpow(k, n) << endl;
    cout << binpow(k - 1, n) << endl;
    cout << ncr(k, k - 1) << endl;
    cout << ncr(m, k) << endl;

    cout << (binpow(k, n) - (binpow(k - 1, n) * ncr(k, k - 1) % MOD) + MOD) * ncr(m, k) % MOD << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    fat[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fat[i] = fat[i - 1] * i % MOD;
    }
    ifat[MAX - 1] = inv(fat[MAX - 1]);
    for (int i = MAX - 2; i >= 0; i--) { 
        ifat[i] = ifat[i + 1] * (i + 1) % MOD;
    }
    solve();
}

