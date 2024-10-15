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

void solve() {
    int n, c; cin >> n >> c;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a[0] += c;

    vector<int> res(n, -1);

    int mx = -1, who = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] > mx) {
            mx = a[i];
            who = i;
        } else if (a[i] == mx) {
            who = min(i, who);
        }
    }

    res[who] = 0;

    int erased = 0;
    for (int i = 0; i < n; i++) {
        bool need = 0;
        if (a[i] < mx) {
            need = 1;
        }
        if (res[i] == -1) {
            res[i] = erased + need;
        }
        if (i < n - 1) {
            a[i + 1] += a[i];
            erased++;
        }
    }

    for (int i = 0; i < n; i++) {
        assert(res[i] != -1 && res[i] < n);
        cout << res[i] << " ";
    }
    cout << endl;
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