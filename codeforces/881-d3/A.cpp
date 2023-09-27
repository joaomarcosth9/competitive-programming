#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    long long res = 0;
    sort(begin(a), end(a));
    for(int i = 0; n - i - 1 > i; i++){
        res += a[n - 1 - i] - a[i];
    }
    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if (TC) { cin >> TC;
        while (TC--) solve();
    } else solve();
    return 0;
}
