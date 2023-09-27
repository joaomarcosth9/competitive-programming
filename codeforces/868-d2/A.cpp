#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve(){
    int n, k; cin >> n >> k;
    auto sum = [] (int i){
        return max((i * (i-1) / 2), 0);
    };
    for(int i = 0; i < n; i++){
        if(sum(i) + sum(n-i) == k){
            cout << "YES\n";
            for(int j = 0; j < i; j++) cout << -1 << " ";
            for(int j = i; j < n; j++) cout << 1 << " ";
            cout << '\n';
            return;
        }
    }
    cout << "NO\n";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
