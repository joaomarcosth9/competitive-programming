#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int MAX = 1e4+10;

double dis[MAX];

void solve(){
    int t, n; cin >> t >> n;
    for(int i = 0; i < n; i++){   
        cin >> dis[i];
    }
    sort(dis, dis+n);
    double res = INT_MAX;
    for(int i = 0; i < n; i++){
        double vis;
        if(i == 0){
            vis = abs(dis[i]) + abs((dis[i]-dis[i+1])/2);
            if(vis < res) res = vis;
            continue;
        } else if (i == n-1){
            vis = abs((dis[i]-dis[i-1])/2) + abs(t-dis[i]);
            if(vis < res) res = vis;
            continue;
        }
        vis = abs((dis[i]-dis[i-1])/2) + abs((dis[i]-dis[i+1])/2);
        if(vis < res) res = vis;
    }
    printf("%.2lf\n", res);
}

int main(){
    solve();
    return 0;
}
