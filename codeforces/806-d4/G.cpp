#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll; typedef pair<int,int> ii;
int testcases = 1;
const int INF = 1.05e9; const ll INFLL = 4.5e18;
#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#define dbarr(x...)
#define cerr if(false) cerr
#endif

void solve(){
    ll n, k; cin >> n >> k;
    vector<vector<ll>> dp(n+1, vector<ll>(40, -INFLL));
    vector<vector<ll>> v(40, vector<ll>(n));
    for(auto& a : v[0]) cin >> a;
    for(int i = 1 ; i < 40; i++){
        for(int j = 0; j < n; j++){
            v[i][j] = (i <= j+1 ? v[i-1][j] >> 1 : -INF);
        }
    }
    /* for(auto a : v){ */
    /*     db(a); */
    /* } */
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        dp[i][0] = dp[i-1][0] + v[0][i-1] - k;
    }
    for(int i = 1; i <= n; i++){
        db(i, dp[i][0]);
    }
    ll res = LLONG_MIN;
    for(int j = 1; j < 40; j++) {
        for(int i = j; i <= n; i++){
            // dp[i][j] = maximo lucro ate o bau [i] usando [j] bad keys;
            dp[i][j] = max(dp[i][j], dp[i-1][j-1] + v[j][i-1]);
            dp[i][j-1] = max(dp[i][j-1], dp[i-1][j-1] + v[j-1][i-1] - k);
            if(i == n){
                db(i, j, dp[i][j], dp[i][j-1]);
            }
            res = max(res, max(dp[i][j], dp[i][j-1]));
        }
    }
    cout << res << endl;
}

signed main(){
#ifndef LOCAL_DEBUG
    ios_base::sync_with_stdio(0);cin.tie(0);
#endif
    int tsts = 1;
    if(testcases) cin >> tsts;
    while(tsts--) solve();
    return 0;
}
