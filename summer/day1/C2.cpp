#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef __int128_t ll; typedef pair<int,int> ii;
int testcases = 0;
const int INF = 1.05e9; const ll INFLL = 4.5e18;
#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#define dbarr(x...)
#endif

const ll mod = 1e9+7;

void solve(){
    int n, k; cin >> n >> k;
    int size = max(k+1, n+1);
    vector<ll> dp(size), p(size, (((ll)1) << 120)), pref(size);
    ll tot = 0;
    for(int i = 1; i <= n; i++){
        long long a; cin >> a;
        p[i] = a;
    }
    tot = dp[1] = pref[1] = p[1];
    for(int i = 2; i <= k; i++){
        dp[i] = min(p[i], tot);
        db((long long) i, (long long) dp[i]);
        pref[i] = pref[i-1] + dp[i];
        /* db(i, dp[i], tot); */
        tot += pref[i];
    }
    dp[k] %= mod;
    long long res = dp[k];
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
