#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long ll;
#define int ll

int gtr(pair<int, int> b, pair<int, int> a) {
    a.first *= b.second;
    b.first *= a.second;
    if (b.first > a.first) return 1;
    if (b.first == a.first) return -1;
    return 0;
}

void solve() {
    int n;
    cin >> n;

    if (n <= 8) {
        cout << n - 1 << '\n';
    } else if (n <= 20) {
        cout << n - 4 << '\n';
    } else {
        if (n % 4 == 0) {
            cout << (n - 4) / 4 << '\n';
        } else {
            int best = n - 4;
            pair<int, int> res{1, 2};
            for (int i = 5; i * i <= n; i++) {
                int nn = n;
                int qt = 0, nd = 0;
                while (nn) {
                    int dig = nn % i;
                    qt += dig == 4;
                    nd++;
                    nn /= i;
                }
                pair<int, int> curr{qt, nd};
                int resp = gtr(curr, res);
                if (resp == 1 || (resp == -1 && res != make_pair(1ll, 2ll))) {
                    res = curr;
                    best = i;
                }
            }
            cout << best << '\n';
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
