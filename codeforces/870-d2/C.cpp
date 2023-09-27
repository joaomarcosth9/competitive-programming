#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(x...)
#endif

int div(int n){
    for(int i = 2; i * i <= n; i++){
        if(n % i) continue;
        return i;
    }
    return -1;
}

void solve(){
    int n, m; cin >> n >> m;
    if(n == 1 || m == 1){
        cout << "YES" << '\n';
        return;
    }
    if(m >= n || n % m == 0){
        cout << "NO" << '\n';
        return;
    }
    if(n % 2 == 0){
        cout << "NO" << '\n';
        return;
    }
    int sm = div(n);
    cout << (sm != -1 && m >= sm ? "NO" : "YES") << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
