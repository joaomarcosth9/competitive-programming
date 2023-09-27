#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

// n, q <= 1000
// n log(n) * q passa

void solve(){
    int n, q; cin >> n >> q;
    vector<long long> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(begin(v), end(v));
    while(q--){
        int k; cin >> k;
        if(n == 1){
            cout << v[0] + (k & 1 ? (k+1) : -k) / 2 << '\n';
            continue;
        }
        vector<long long> a = v;
        long long res = LLONG_MAX;
        for(int i = 0; i < n && k > 0; i++){
            a[i] += k--;
        }
        sort(begin(a), end(a));
        if(!k){
            cout << a[0] << ' ';
            continue;
        }
        debug(a);
        long long cnt = 1;
        for(int i = 1; i < n; i++){
            if(a[i] == a[i-1]){
                cnt++;
            } else if (a[i] > a[i-1]){
                long long op = cnt * (a[i] - a[i-1]);
                if(op <= k){
                    k -= op;
                    cnt++;
                } else {
                    // op > k
                    cout << v[i-1] + (k / cnt) << ' ';
                    break;
                }
            }
        }
    }
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
