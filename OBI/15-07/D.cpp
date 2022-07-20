#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 1e2+5;
    
int n, m, dist[MAX];
typedef pair<int,int> ii;
vector<ii> Adj[MAX];

void dijkstra(int a){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0,a});
    while(!pq.empty()){
        auto [w,s] = pq.top();
        pq.pop();
        if(dist[s] > w){
            dist[s] = w;
            for(int i = 0; i < Adj[s].size(); i++){
                pq.push({w+Adj[s][i].first, Adj[s][i].second});
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        dist[i] = INT_MAX;
    }
    for(int i = 1; i <= m; i++){
        int c1, c2, w;
        cin >> c1 >> c2 >> w;
        Adj[c1].push_back({w,c2});
        Adj[c2].push_back({w,c1});
    }
    dijkstra(1);
    cout << dist[n] << endl;
}

int main(){ _
    solve();
    return 0;
}
