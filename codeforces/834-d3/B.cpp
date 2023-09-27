#include <bits/stdc++.h>

using namespace std;

int temtestcase = 1;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;
typedef long long ll;

void solve(){
    int m, s; cin >> m >> s;
    const int MAX = 3e3;
    vector<int> freq(MAX);
    vector<int> v(m);
    int mx = INT_MIN;
    for(int i = 0; i < m; i++){
        cin >> v[i];
        freq[v[i]]++;
        mx = max(mx, v[i]);
    }
    int sum = 0;
    for(int i = 1; i < MAX; i++){
        if(!freq[i]){
            sum += i;
        }
        if(sum == s && i >= mx){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tsts = 1;
    if(temtestcase) cin >> tsts;
    while(tsts--) solve();
    return 0;
}
