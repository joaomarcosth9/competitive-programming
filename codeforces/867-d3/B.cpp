#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve(){
    int n; cin >> n;
    vector<long long> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    long long mx = INT_MIN, mx2 = INT_MIN;
    long long mn = INT_MAX, mn2 = INT_MAX;
    for(int i = 0; i < n; i++){
        mx2 = max(mx2, v[i]);
        mn2 = min(mn2, v[i]);
        if(mx2 > mx) swap(mx, mx2);
        if(mn2 < mn) swap(mn, mn2);
    }
    cout << max(mx * mx2, mn * mn2) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
