#include <bits/stdc++.h>

using namespace std;

int temtestcase = 1;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;
typedef long long ll;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(auto& a : v) cin >> a;

    int e = INT_MAX;

    for(int i = 30; i >= 0; i--){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if((1 << i) & v[j]){
                cnt++;
            }
        }
        if((n-cnt) <= k){
            for(int j = 0; j < n; j++){
                v[j] |= (1 << i);
            }
            k -= (n-cnt);
        }
    }

    for(int i = 0; i < n; i++){
        e &= (v[i]);
    }

    cout << e << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tsts = 1;
    if(temtestcase) cin >> tsts;
    while(tsts--) solve();
    return 0;
}
