#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void simplify(pair<long long, long long> &p) {
    int _gcd = gcd(p.first, p.second);
    p.first /= _gcd;
    p.second /= _gcd;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    long long l = b[0], g = a[0] * b[0];
    long long ress = 1;
    db(l, g);
    for (int i = 1; i < n; i++) {
        long long nl = lcm(l, b[i]);
        long long ng = gcd(g, a[i] * b[i]);
        db(i, nl, ng);
        if (ng % nl) {
            ress++;
            l = b[i], g = a[i] * b[i];
        } else {
            l = nl, g = ng;
        }
    }
    cout << ress << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
