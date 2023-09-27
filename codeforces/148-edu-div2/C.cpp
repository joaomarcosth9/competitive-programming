#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<int> a(1, v[0]);
    for(int i = 1; i < n; i++){
        if(v[i] != a.back()){
            a.emplace_back(v[i]);
        }
    }
    n = a.size();
    if(n == 1){
        cout << 1 << '\n';
        return;
    }
    int res = 2;
    int desc = a[1] < a[0];
    debug(a, desc);
    for(int i = 1; i < n; i++){
        if(desc){
            if(a[i] > a[i-1]){
                desc = 0;
                res++;
            }
        } else {
            if(a[i] < a[i-1]){
                desc = 1;
                res++;
            }
            // cresc
        }
    }
    cout << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
