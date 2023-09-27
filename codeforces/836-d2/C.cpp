#include <bits/stdc++.h>

using namespace std;

int testcases = 1;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;

void solve(){
    int n, k; cin >> n >> k;
    if(n % k != 0){
        cout << -1 << endl;
        return;
    }
    vector<int> res(n+1);
    res[1] = k, res[n] = 1;
    for(int i = n-1; i > 1; i--){
        if(i == k) res[i] = n;
        else res[i] = i;
    }
    int idx = k;
    for(int i = k+1; i < n; i++){
        if((res[i] % idx == 0) && (n % i == 0)){
            swap(res[idx], res[i]);
            idx = i;
        }
    }
    res.erase(res.begin());
    for(auto a : res) cout << a << ' ';
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tsts = 1;
    if(testcases) cin >> tsts;
    while(tsts--) solve();
    return 0;
}
