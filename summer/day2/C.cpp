#include <bits/stdc++.h>

using namespace std;
#define int long long

int testcases = 0;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    map<int,int> f1;
    map<int,int> f2;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int a : arr){
        for(int b : arr){
            for(int c : arr){
                int res = (a*b) + c;
                f1[res]++;
            }
        }
    }
    for(int a : arr){
        for(int b : arr){
            for(int c : arr){
                if(c == 0) continue;
                int res = (a+b) * c;
                f2[res]++;
            }
        }
    }
    long long res = 0;
    for(auto [k,v] : f1){
        res += v * f2[k];
    }
    cout << res << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tsts = 1;
    if(testcases) cin >> tsts;
    while(tsts--) solve();
    return 0;
}
