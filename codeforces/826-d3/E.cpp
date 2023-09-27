#include <bits/stdc++.h>

using namespace std;

int temtestcase = 1;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;
typedef long long ll;

const int MAX = 2e5 + 5;
int n, arr[MAX];
bool dp[MAX];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        dp[i] = false;
    }
    dp[0] = true;
    for(int i = 1; i <= n; i++){
        if((dp[i-1] == true && i + arr[i] <= n)) dp[i+arr[i]] = true;
        if(i-arr[i]-1 >= 0 && dp[i-arr[i]-1] == true) dp[i] = true;
    }
    cout << (dp[n] ? "YES" : "NO") << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tsts = 1;
    if(temtestcase) cin >> tsts;
    while(tsts--) solve();
    return 0;
}
