#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n; cin >> n;
    long long min1 = INT_MAX, min2 = INT_MAX, min12 = INT_MAX;
    for(int i = 0; i < n; i++){
        long long u; cin >> u;
        string s; cin >> s;
        if(s == "00") continue;
        if(s == "11") {
            min1 = min(min1, u);
            min2 = min(min2, u);
            min12 = min(min12, u);
        } else if(s == "01"){
            min2 = min(min2, u);
        } else {
            min1 = min(min1, u);
        }
    }
    long long res = min(min1 + min2, min12);
    cout << (res < 1e9 ? res : -1) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
