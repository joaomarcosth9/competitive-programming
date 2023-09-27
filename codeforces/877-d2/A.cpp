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
    for(int &u : a) cin >> u;
    sort(begin(a), end(a));
    if(a[0] < 0) cout << a[0] << '\n';
    else cout << a.back() << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
