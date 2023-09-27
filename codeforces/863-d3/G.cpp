#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif
#define int long long

const int maxn = 5e3+5, mod = 1e9+7;
int arr[maxn];

int b(int i, int k){
    if(i > 11) return 0;
    if(k == 8) return 1;
    return b(i+1, k+1) + b(i+2, k+1) + b(i+3, k+1) + b(i+4, k+1) + b(i+5, k+1) + b(i+6, k+1) + b(i+7, k+1) + b(i+8, k+1) + b(i+9, k+1) + b(i+10, k+1) + b(i+11, k+1);
}

void solve(){
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int brute = 0;
    for(int i = 1; i <= 11; i++){
        brute += b(i, 1);
    }
    db(brute);
    return;
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n; j++){
            int m = k*j;
            if(i + m == n) break;

            // test if [i, i+m-1] is nice;

            /* res += check(i, i+m-1); */

        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
