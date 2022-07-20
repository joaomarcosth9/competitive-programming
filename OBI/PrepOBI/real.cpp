#include <bits/stdc++.h>

using namespace std;

const int MAX = 10060;

int n, m;

int part[MAX];
double levels[MAX];
double foram[MAX];
int max_level = 0;
vector<vector<int>> V(MAX);

void dfs(int node, int level){
    for(int i = 0; i < V[node].size(); i++){
        //cout << "Pai " << node << ": " << " - Filho " << V[node][i] << ' ' << " - Level " << level << " - Foi: " << part[V[node][i]] << endl;
        levels[level]++;
        if(max_level < level){
            max_level = level;
        }
        if (part[V[node][i]]){
            foram[level]++;
        }
        dfs(V[node][i], level+1);
    }
}

void solve(){
    cin >> n >> m;
    for (int filho = 1; filho <= n; filho++){
        int pai; cin >> pai;
        V[pai].push_back(filho);
    } 
    for (int i = 1; i <= m; i++){
        int filho; cin >> filho;
        part[filho]++;
    } 
    dfs(0, 0);
    for(int i = 0; i <= max_level; i++){
        printf("%.2f ", foram[i]/levels[i]*100);
    }
    cout << '\n';
}

int main(){
    solve();
    return 0;
}
