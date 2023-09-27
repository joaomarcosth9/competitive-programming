#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

const long long maxn = (1 << 21), mod = 1e9 + 9;
long long n, arr[maxn];

long long solve2(int l, int r){
    if(l == r) return arr[l];
    int mid = (l + r) / 2;
    for(int i = l, j = mid+1; i <= mid; i++, j++){
        arr[i] = (arr[i] - arr[j]) % mod;
    }
    long long u = solve2(mid+1, r);
    long long v = solve2(l, mid);
    return (v * u) % mod;
}

void solve(){
    cin >> n;
    for(int i = 0; i < (1 << n); i++){
        cin >> arr[i];
    }
    cout << (solve2(0, (1 << n) - 1) + mod) % mod << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
