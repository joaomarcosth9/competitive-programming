#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

int n, m; 
const int maxn = 1e3+5, mod = 1e9 + 7;
int mat[maxn][maxn];
long long dp[maxn][maxn];

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c; cin >> c;
            if(c == '.') mat[i][j] = 1;
            else mat[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++) {
        if(mat[i][0] == 0) break;
        dp[i][0] = 1;
    }
    for(int i = 0; i < m; i++) {
        if(mat[0][i] == 0) break;
        dp[0][i] = 1;
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(mat[i][j]) dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
        }
    }
    cout << dp[n-1][m-1] << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
