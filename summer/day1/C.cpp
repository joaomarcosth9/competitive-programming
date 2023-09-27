#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/* typedef long long ll; typedef pair<int,int> ii; */
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
    ll tot = 0;
    vector<ll> p(n+1), dp(k+1);
    for(int i = 1; i <= n; i++){
        long long a; cin >> a;
        p[i] = a;
    }
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
