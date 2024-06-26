#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

#define int ll

const int MOD = (int)1e9 + 7;

int add(int a, int b) {
    return (a + b + MOD) % MOD;
}

int mul(int a, int b) {
    return (a * b) % MOD;
}

int binpow(int x, int e) {
    int res = 1;
    while (e > 0) {
        if (e & 1) {
            res = mul(res, x);
        }
        x = mul(x, x);
        e >>= 1;
    }
    return res;
}

int inv (int x) {
    return binpow(x, MOD - 2);
}


int sum_powers(int x, int l, int r) {
    if (x == 1) {
        return r - l + 1;
    }
    int xr1 = binpow(x, r + 1);
    int xl = binpow(x, l);
    return mul(add(xr1, -xl), inv(x - 1));
}

void solve() {
    int l, r, k; cin >> l >> r >> k; 

    if (k >= 10) {
        cout << 0 << endl;
        return;
    }

    int min_dig = 0;
    int mx_dig = 9 / k;

    int R = (mx_dig - min_dig) + 1;

    if (r == 1) {
        cout << R - 1 << endl;
        return;
    }

    int res = mul(R - 1, sum_powers(R, max(l, 1LL), r - 1));

    debug(R, res, l, r, sum_powers(R, max(1LL, l), r - 1));

    if (l == 0) {
        res += R - 1;
    }

    cout << res << endl;

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}