#include <bits/stdc++.h>

using namespace std;

int testcases = 0;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;

void solve(){
    int n; cin >> n;
    vector<pair<int,int>> points(n);
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        points[i] = {a,b};
    }
    int maxx[4];
    for(auto& a : maxx) a = INT_MIN;
    for(auto [x,y] : points){
        maxx[0] = max(maxx[0], x+y);
        maxx[1] = max(maxx[1], x-y);
        maxx[2] = max(maxx[2], -x+y);
        maxx[3] = max(maxx[3], -x-y);
    }
    int ress = INT_MIN;
    ress = max(ress, maxx[0] + maxx[3]);
    ress = max(ress, maxx[1] + maxx[2]);
    cout << ress << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tsts = 1;
    if(testcases) cin >> tsts;
    while(tsts--) solve();
    return 0;
}
