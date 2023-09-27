#include <bits/stdc++.h>

using namespace std;

int testcases = 0;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;

void solve(){
    int n; cin >> n;
    int mx = 0;
    int cur = 0;
    for(int i = 0; i < n; i++){
        int out, in; cin >> out >> in;
        cur += in - out;
        mx = max(mx, cur);
    }
    cout << mx << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tsts = 1;
    if(testcases) cin >> tsts;
    while(tsts--) solve();
    return 0;
}
