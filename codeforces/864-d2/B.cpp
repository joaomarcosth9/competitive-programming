#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

// (i,j) -> (n-i-1, n-j-1)

void solve(){
    int n, k; cin >> n >> k;
    vector<vector<int>> v(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }
    long long res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            res += v[i][j] != v[n-i-1][n-j-1];
        }
    }
    assert((res % 2) == 0);
    res /= 2;
    db(res, k);
    bool db = 1;
    if(res > k){
        db = 0;
    } else if (res == k){
        db = 1;
    } else {
        // res < k
        k -= res;
        if(n & 1){
            db = 1;
        } else {
            db = (k % 2) == 0;
        }
    }
    cout << (db ? "YES" : "NO") << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
