#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve(){
    int n, k; cin >> n >> k;
    vector<int> v(n);
    long long sum = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(begin(v), end(v));
    for(int i = 0; i < n-k; i++){
        sum += v[i];
    }
    long long res = sum;
    int pl = 0;
    int pr = n-k;
    debug(sum);
    for(int i = 0; i < k; i++){
        sum -= v[pl] + v[pl+1];
        pl += 2;
        sum += v[pr];
        pr++;
        res = max(res, sum);
    }
    debug(v, sum);
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
