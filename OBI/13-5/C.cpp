#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int dist[MAXN];
void dijkstra(int a, int n, vector<vector<pair<int,int>>>& Adj){
    for(int i = 0; i <= n+3; i++) dist[i] = 2123456789;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,a});
    while(!pq.empty()){
        auto [w,s] = pq.top();
        pq.pop();
        if(dist[s] > w){
            dist[s] = w;
            for(int i = 0; i < (int)Adj[s].size(); i++){
                pq.push({w+Adj[s][i].first, Adj[s][i].second});
            }
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> Adj(n+1);
    for(int i = 0; i < m; i++){
        int a,b,c; cin >> a >> b >> c;
        Adj[a].push_back({c,b});
        Adj[b].push_back({c,a});
    }
    int u; cin >> u;
    dijkstra(u, n, Adj);
    int minn = INT_MAX;
    int maxx = INT_MIN;
    for(int i = 1; i <= n; i++){
        minn = min(minn, (i != u ? dist[i] : minn));
        maxx = max(maxx, (i != u ? dist[i] : maxx));
    }
    cout << maxx - minn << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
