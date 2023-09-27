#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

int dig[] = {0, 1, 2, 3, 5, 6, 7, 8, 9};

void solve() {
    long long n;
    cin >> n;
    string res;
    while (n) {
        res += '0' + dig[n % 9];
        n /= 9;
    }
    reverse(begin(res), end(res));
    cout << res << endl;
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
