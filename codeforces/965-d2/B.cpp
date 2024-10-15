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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;

#ifdef LOCAL
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
    }
    ll best = 1e18;
    do {
        ll res = 0;
        for (int i = 0; i < n; i++) {
            ll sum1 = 0, sum2 = 0;
            for (int j = i; j < n; j++) {
                sum1 += a[j];
                sum2 += p[j];
                if (sum1 == sum2) {
                    res++;
                }
            }
        }
        best = min(best, res);
    } while (next_permutation(p.begin(), p.end()));
    cout << "Optimal: " << best << endl;
#endif

    if (n == 1) {
        cout << 1 << endl;
    } else {
        auto b = a;
        rotate(b.begin(), b.begin() + n - 1, b.end());
        for (auto u : b) {
            cout << u << " ";
        }
        cout << endl;
#ifdef LOCAL
        ll best = 1e18;
        do {
            ll res = 0;
            for (int i = 0; i < n; i++) {
                ll sum1 = 0, sum2 = 0;
                for (int j = i; j < n; j++) {
                    sum1 += a[j];
                    sum2 += b[j];
                    if (sum1 == sum2) {
                        res++;
                    }
                }
            }
            best = min(best, res);
        } while (next_permutation(b.begin(), b.end()));
        cout << "Achieved: " << best << endl;
#endif
    }
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