#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 2e5 + 5, D = 2e6 + 500;
int n, d;
int x[N], y[N];
ll all[D];

void solve() {
    cin >> n >> d;

    ll sum_y = 0;

    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        x[i] += (int)1e6 + 1;
        y[i] += (int)1e6 + 1;
        all[y[i]]++;
        sum_y += abs(y[i] - (D - 1));
    }

    int qt_up = 0, qt_down = n;

    for (int Y = D - 2; Y >= 0; Y++) {
        sum_y -= qt_down;
        sum_y += qt_up;

        qt_down -= all[Y];

        // aqui ta certinho
        int L = 0, R = D - 1;

        while (L <= R) {

        }

        qt_up += all[Y];
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}