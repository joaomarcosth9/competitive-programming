#include <bits/stdc++.h>

using namespace std;

int temtestcase = 1;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;
typedef long long ll;

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(auto& a : v) cin >> a;

    sort(v.rbegin(), v.rend());

    int pref = 0;
    int idx = 0;

    for(int i = 30; i >= 0; i--){
        if(pref & (1 << i)) continue;
        int mx = 0;
        int midx = 0;
        for(int j = idx; j < (int)v.size(); j++){
            if((1 << i) & v[j]){
                if((v[j]|pref) > (mx|pref)){
                    mx = v[j];
                    midx = j;
                }
            }
        }
        if(mx > 0){
            pref |= v[midx];
            swap(v[midx], v[idx]);
            idx++;
        }
    }
    for(auto a : v) cout << a << ' ';
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tsts = 1;
    if(temtestcase) cin >> tsts;
    while(tsts--) solve();
    return 0;
}

