#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 15;
pair<int,int> D[MAX];

pair<int,int> diff_time(pair<int,int> A, pair<int,int> B){
    pair<int,int> dff;
    auto [h,m] = A;
    auto [H,M] = B;
    int dm = M-m;
    if(H < h) H+=24;
    dff.first = (H-h)%24;
    if(dm >= 0){
        dff.second = dm;
    } else {
        dff.second = 60+dm;
        if (dff.first){
            dff.first--;
        } else {
            dff.first = 23;
        }
    }
    //cout << dff.first << ' ' << dff.second << endl;
    return dff;
}

void solve(){
    pair<int,int> res;
    vector<pair<int,int>> diffs;
    int n, h, m; cin >> n >> h >> m;
    pair<int,int> sl = {h,m};
    pair<int,int> next;
    for(int i = 0; i < n; i++){
        cin >> D[i].first >> D[i].second;
    }
    for(int i = 0; i < n; i++){
        diffs.push_back(diff_time(sl, D[i]));
    }
    sort(begin(diffs),end(diffs));
    cout << diffs[0].first << ' ' << diffs[0].second << endl;
}

int main(){ _
    int tscf; cin >> tscf;
    while(tscf--) solve();
    return 0;
}
