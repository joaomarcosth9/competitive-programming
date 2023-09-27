#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve(){
    int n, k; cin >> n >> k;
    vector<pair<int,int>> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    vector<int> res(n), vis(n);
    debug(k);
    debug(a);
    debug(b);
    for(int i = 0; i < n; i++){
        res[a[i].second] = b[i];
    }
    for(int i = 0; i < n; i++){
        cout << res[i] << ' ';
    }
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
