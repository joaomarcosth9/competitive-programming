#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int MOD = (int)1e9 + 7, N = 1e6 + 5;

int n, m, k;

int a[2 * N], b[2 * N], diff1[2 * N], diff2[2 * N];

void solve() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i] %= m;
        b[i] = (m - b[i]) % m;
        b[i + n] = b[i];
    }

    if (k >= n) {
        cout << 0 << endl;
        return;
    }

    for (int i = 0; i < 2 * n; i++) {
        diff1[i] = (a[i] - a[(i + 1) % (2 * n)] + m) % m;
        diff2[i] = (b[i] - b[(i + 1) % (2 * n)] + m) % m;
    }


}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}