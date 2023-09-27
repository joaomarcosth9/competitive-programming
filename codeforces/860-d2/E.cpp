#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif



void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
