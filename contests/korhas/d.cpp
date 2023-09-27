#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int n = gcd(c, a);
    if (n != a) {
        cout << -1 << endl;
        return;
    }
    int f = c / a;
    vector<int> dv;
    for (int i = 1; i * i <= f; i++) {
        if (f % i) continue;
        if (i * i != f) {
            dv.push_back(i);
            dv.push_back(f / i);
        } else
            dv.push_back(i);
    }
    sort(begin(dv), end(dv));
    db(dv);
    int it = 0;
    int nn = n;
    while (1) {
        if ((n % b) && (d % n)) {
            cout << n << endl;
            return;
        }
        if (it == (int)dv.size()) break;
        n = nn * dv[it];
        it++;
    }
    cout << -1 << endl;
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
