#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

const int mod = 1e9 + 7, maxn = 3e3+5, INF = 2e9;
long long pot2[maxn];

void solve(){
    int n; cin >> n;
    pot2[0] = 1;
    for(int i = 1; i <= n; i++){
        pot2[i] = (pot2[i-1] * 2) % mod;
    }
    vector<int> v(n+2), v2(n+2);
    for(int i = 1; i <= n; i++) cin >> v[i];
    v[0] = -INF, v[n+1] = INF;
    for(int i = 0; i < n+2; i++) v2[i] = -v[n+1-i];
    long long res = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            int diff = v[j] - v[i], exc = 1+j-i;
            int pos = lower_bound(v.begin(), v.end(), v[j]+diff) - v.begin();
            int rev_i = n+1-i;
            int pre = upper_bound(v2.begin(), v2.end(), v2[rev_i]+diff) - v2.begin();
            exc += (pos - j - 1);
            exc += (pre - rev_i - 1);
            res = (res + pot2[n-exc]) % mod;
        }
    }
    cout << res << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
