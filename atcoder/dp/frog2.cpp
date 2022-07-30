#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n';

using namespace std;

const int MAX = 1e5+10;

int dp[MAX];
int arr[MAX];
int n, k;

int dpp(int p){ 
    if(p == 1){
        dp[p] = abs(arr[p] - arr[0]);
        return dp[p];
    } else if (p == 0){
        return 0;
    } else if (p < 0) return 1e9;
    if(dp[p] != -1) return dp[p];
    int menor = dpp(p-1)+abs(arr[p] - arr[p-1]);
    for(int i = 2; i <= k; i--){
        if(menor > dpp(p-i)+abs(arr[p] - arr[p-i])){
            menor = dpp(p-i)+abs(arr[p] - arr[p-i]);
        }
    }
    dp[p] = menor;
    return dp[p];
}

void solve(){
    cin >> n >> k;
    for(int i = 0; i < MAX; i++){
        dp[i] = -1;
    }
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << dpp(n-1) << endl;
}

int main(){ _
    solve();
    return 0;
}
