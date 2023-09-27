#include <bits/stdc++.h>

using namespace std;

int testcases = 1;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(auto& a : v) cin >> a;
    for(int i = 1; i < n; i++){
        if(v[i] > v[i-1]){
            for(int j = i; j < n; j++){
                if(v[j] < v[j-1]){
                    cout << "NO" << endl;
                    return;
                }
            }
            break;
        }
    }
    cout << "YES" << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tsts = 1;
    if(testcases) cin >> tsts;
    while(tsts--) solve();
    return 0;
}
