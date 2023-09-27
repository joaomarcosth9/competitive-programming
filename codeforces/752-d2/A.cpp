#include <bits/stdc++.h>

using namespace std;

int testcases = 1;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(auto& a : v) cin >> a;
    int res = 0;
    int ins = 1;
    for(int i = 0; i < n; i++){
        int ri = i + ins;
        if(v[i] > ri){
            ins += v[i] - ri;
        }
    }
    cout << ins-1 << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tsts = 1;
    if(testcases) cin >> tsts;
    while(tsts--) solve();
    return 0;
}
