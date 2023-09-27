#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
    int n, m; cin >> n >> m;
    int num = 1;
    vector<vector<int>> res(n, vector<int>(m));
    cout << n * m << endl;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < m; j++){
            res[i][j] = (j*2)+i;
        }
    }
    for(int i = 2; i < n; i++){
        for(int j = 0; j < m; j++){
            if(j == 0) res[i][j] = (rng() % (int)1e5);
            else res[i][j] = res[i-1][j] ^ res[i-1][j-1] ^ res[i][j-1];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
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
