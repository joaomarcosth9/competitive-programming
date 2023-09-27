#include <bits/stdc++.h>

using namespace std;

int testcases = 1;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;
#define MAXN 200005
int n, a, l, r;
int arr[MAXN];

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    map<int,vector<int>> idx;
    for(int i = 0; i < n; i++){
        idx[arr[i]].push_back(i);
    }
    int res[4] {0, arr[0], 1, 1};
    for(auto [c,v] : idx){
        int s = v.size();
        int u = 1;
        int lv = v[0];
        for(int i = 1; i < s; i++){
            u -= v[i] - v[i-1] - 2;
            if(u < 1){
                u = 1;
                lv = v[i];
            }
            if(u > res[0]){
                res[0] = u;
                res[1] = c;
                res[2] = lv+1;
                res[3] = v[i]+1;
            }
        }
    }
    for(int i = 1; i < 4; i++){
        cout << res[i] << ' ';
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
