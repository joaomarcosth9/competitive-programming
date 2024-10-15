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
    int n; cin >> n;

    vector<int> a(n);
    for (int &i : a) 
        cin >> i;

    if (is_sorted(a.begin(), a.end())) {
        cout << 0 << endl;
        return;
    }

    bool found = a[0] > 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == 1 && found) {
            cout << -1 << endl;
            return;
        }
        found |= a[i] > 1;
    }

    vector<double> b(n);

    for (int i = 0; i < n; i++) {
        b[i] = log2(a[i]) * 10;
    }
    for (int i = 0; i < n; i++) {
        b[i] = log2(b[i]);
    }

    int res = 0;
    const double EPS = 1e-9;

    for (int i = 1; i < n; i++) {
        if (a[i] == 1) {
            continue;
        }
        if (b[i] + EPS < b[i - 1]) {
            double diff = b[i - 1] - b[i];
            b[i] += floor(diff + EPS);
            res += floor(diff + EPS);
        }
        while (b[i] + EPS < b[i - 1]) {
            b[i]++;
            res++;
        }
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