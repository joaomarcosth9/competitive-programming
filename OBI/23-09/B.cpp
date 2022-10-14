#include <bits/stdc++.h>

using namespace std;

const int mx = 1e4+500;
const int mod = 1e9+7;
typedef long long ll;
ll dp[mx];

ll dpp(int p){
    if(dp[p]) return dp[p];
    dp[p] = (dpp(p-1)%mod + 4*dpp(p-2)%mod + 2*dpp(p-3)%mod)%mod;
    return dp[p]%mod;
}

int main(){
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 5;
    int n; cin >> n;
    cout << dpp(n) << endl;
}
