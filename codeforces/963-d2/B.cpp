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
    bool odd = 1;
    int cnt_even = 0;
    for (int &i : a) {
        cin >> i;
        odd &= (i % 2) == 1;
        cnt_even += (i % 2) == 0;
    }

    sort(rbegin(a), rend(a));

    int first = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] & 1) { 
            first = i;
            break;
        }
    }

    if (first == -1 || odd) {
        cout << 0 << endl;
    } else {
        if (first == 0) {
            cout << cnt_even << endl;
        } else {
            ll mx_odd = a[first];
            int res = 0;
            for (int i = first + 1; i < n; i++) {
                if (a[i] % 2 == 0) {
                    mx_odd += a[i];
                    res++;
                }
            }
            for (int i = first - 1; i >= 0; i--) {
                if (a[i] % 2 == 0) {
                    if (mx_odd > a[i]) {
                        mx_odd += a[i];
                        res++;
                    } else {
                        mx_odd += a[0];
                        res += 2;
                    }
                }
            }
            cout << res << endl;
        }
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