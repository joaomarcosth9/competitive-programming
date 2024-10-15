#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

int MOD;

int sub(int a, int b) {
    a -= b;
    if (a < 0) a += MOD;
    return a;
}

int add(int a, int b) {
    if (b < 0) return sub(a, b);
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int mul(int a, int b) {
    return (int)(1LL * a * b % MOD);
}

const int K = 5e3 + 5;

int fat[K], ifat[K];

int nck(int n, int k) {
    if (k > n) return 0;
    return mul(fat[n], mul(ifat[k], ifat[n - k]));
}

int inv(int x) {
    return x <= 1 ? x : sub(MOD, mul(inv(MOD % x), MOD / x));
}

int k;

void solve() {
    cin >> k >> MOD;

    fat[0] = 1;
    for (int i = 1; i < K; i++) {
        fat[i] = mul(fat[i - 1], i);
    }
    ifat[K - 1] = inv(fat[K - 1]);
    for (int i = K - 1; i > 0; i--) {
        ifat[i - 1] = mul(ifat[i], i);
    }

    int ans = 0;

    for (int sx = 0; sx <= k; sx++) {
        int mx = k - sx;
        if (mx & 1) continue;
        for (int sy = 0; sy <= k - sx; sy++) {
            int my = k - sy;
            if (my & 1) continue;
            int tot_x = mul(nck(k, sx), nck(mx, mx / 2));
            int tot_y = mul(nck(k - sx, sy), nck(my, my / 2));
            ans = add(ans, mul(tot_x, tot_y));
        }
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
