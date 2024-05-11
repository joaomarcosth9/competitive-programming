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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    vector<vector<int>> opref(n, vector<int>(32)), osuff(n, vector<int>(32));
    vector<vector<int>> epref(n, vector<int>(32)), esuff(n, vector<int>(32));
    vector<vector<int>> zpref(n, vector<int>(32)), zsuff(n, vector<int>(32));

    for (int bit = 0; bit < 31; bit++) {
        if (a[0] & (1 << bit)) {
            opref[0][bit] = 1;
        } else {
            epref[0][bit] = 1;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int bit = 0; bit < 31; bit++) {
            if (a[i] & (1 << bit)) {
                opref[i][bit] = epref[i - 1][bit] + 1;
                epref[i][bit] = opref[i - 1][bit];
            } else {
                epref[i][bit] = epref[i - 1][bit] + 1;
                opref[i][bit] = opref[i - 1][bit];
            }
        }
    }

    for (int bit = 0; bit < 31; bit++) {
        if (a[n - 1] & (1 << bit)) {
            osuff[n - 1][bit] = 1;
        } else {
            esuff[n - 1][bit] = 1;
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int bit = 0; bit < 31; bit++) {
            if (a[i] & (1 << bit)) {
                osuff[i][bit] = esuff[i + 1][bit] + 1;
                esuff[i][bit] = osuff[i + 1][bit];
            } else {
                esuff[i][bit] = esuff[i + 1][bit] + 1;
                osuff[i][bit] = osuff[i + 1][bit];
            }
        }
    }

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        int msb = 31 - __builtin_clz(a[i]);
        if (i == 0) {
            ans += osuff[i + 1][msb];
        } else if (i == n - 1) {
            ans += opref[i - 1][msb];
        } else {
            ans += (ll)opref[i - 1][msb] * (ll)(esuff[i + 1][msb] + 1);
            ans += (ll)(epref[i - 1][msb] + 1) * (ll)osuff[i + 1][msb];
        }
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
