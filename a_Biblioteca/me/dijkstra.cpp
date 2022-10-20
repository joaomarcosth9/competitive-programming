// dijkstra (int source, int number_of_nodes, vector<vii>& adj);
const int MAXN = 2e5;
int dist[MAXN];
void dijkstra(int source, int n_nodes, vector<vector<pair<int,int>>>& Adj){
    for(int i = 0; i <= n_nodes+3; i++) dist[i] = 2123456789;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,source});
    while(!pq.empty()){
        auto [w,s] = pq.top();
        pq.pop();
        if(dist[s] > w){
            dist[s] = w;
            for(int i = 0; i < (int)Adj[s].size(); i++){
                auto [ww, dest] = Adj[s][i];
                if(ww + w < dist[dest]) pq.push({w+ww, dest});
            }
        }
    }
}

