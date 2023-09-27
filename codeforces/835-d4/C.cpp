#include <bits/stdc++.h>

using namespace std;

int testcases = 1;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(auto& a : v) cin >> a;
    int maxx = -1, smaxx = -1;
    for(int i = 0; i < n; i++){
        smaxx = max(smaxx, v[i]);
        if(smaxx > maxx) swap(smaxx, maxx);
    }
    for(int i = 0; i < n; i++){
        if(v[i] != maxx){
            cout << v[i] - maxx << ' ';
        } else {
            cout << v[i] - smaxx << ' ';
        }
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tsts = 1;
    if(testcases) cin >> tsts;
    while(tsts--) solve();
    return 0;
}
