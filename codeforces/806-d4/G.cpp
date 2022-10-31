#include <bits/stdc++.h>

using namespace std;

int temtestcase = 1;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;
typedef long long ll;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout << "----------------\n";
    for(int i = 0; i < n; i++){
        /* cout << gk[i] << " \n"[i == n-1]; */
    }
    for(int i = 0; i < n; i++){
        /* cout << bk[i] << " \n"[i == n-1]; */
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tsts = 1;
    if(temtestcase) cin >> tsts;
    while(tsts--) solve();
    return 0;
}
