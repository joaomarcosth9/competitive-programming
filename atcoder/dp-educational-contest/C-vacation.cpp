#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 3e5;

int n;
int arr[MAX];
int dp[MAX];

// recursive
int dpp(int at, int d){
    int idx = 3*d+at;
    if(dp[idx] != -1) return dp[idx];
    else if(at == 0){
        dp[idx] = arr[idx]+max(dpp(1,d-1), dpp(2,d-1));
    }
    else if(at == 1){
        dp[idx] = arr[idx]+max(dpp(0,d-1), dpp(2,d-1));
    }
    else if(at == 2){
        dp[idx] = arr[idx]+max(dpp(0,d-1), dpp(1,d-1));
    }
    return dp[idx];
}

void solve(){
    cin >> n;
    for(int i = 0; i < 3*n; i+=3) cin >> arr[i] >> arr[i+1] >> arr[i+2];
    for(int i = 0; i < 3*n; i++) dp[i] = -1;
    for(int i = 0; i < 3; i++) dp[i] = arr[i];
    for(int i = 3; i < 3*n; i++){
        if(i % 3 == 0){
            // -1 e -2
            dp[i] = arr[i] + max(dp[i-1], dp[i-2]);
        } else if (i % 3 == 1){
            // -2 e -4
            dp[i] = arr[i] + max(dp[i-2], dp[i-4]);
        } else if (i % 3 == 2){
            // -4 e -5
            dp[i] = arr[i] + max(dp[i-4], dp[i-5]);
        }
    }
    cout << max(dp[3*(n-1)+0],max(dp[3*(n-1)+1],dp[3*(n-1)+2])) << endl;
}

int main(){ _
    solve();
    return 0;
}
