#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int res = INT_MIN;
    int res1 = 0, res2 = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '>'){
            res1++;
            res = max(res, res1);
            res2 = 0;
        } else {
            res2++;
            res = max(res, res2);
            res1 = 0;
        }
    }
    cout << res+1 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
