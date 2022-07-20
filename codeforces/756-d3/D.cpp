#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5+50;

int b[MAX];
int p[MAX];
int ans[MAX];
int res[MAX];
int len;
int root;

void dfs(vector<vector<int>>& Vei, int node, int line, int father){
    res[node-1] = ans[node-1] - ans[father-1];
    for (int i = 0; i < Vei[node].size(); i++){
        dfs(Vei, Vei[node][i], line + 1, node);
    }
}

void solve(){
    cin >> len; 
    vector<vector<int>> V(len+1);
    for (int i = 0; i < len; i++){
        cin >> b[i];
    }
    for (int i = 0; i < len; i++){
        cin >> p[i];
    }
    for (int i = 1; i <= len; i++){ 
        if(b[i-1] == i){
            root = i;
            continue;
        }
        V[b[i-1]].push_back(i);
    }

    for(int i = 0; i < len; i++){
        ans[p[i]-1] = i;
    }

    dfs(V, root, 1, root);

    for(int i = 0; i < len; i++){
        if (res[i] <= 0 && (i+1) != root){
            cout << -1 << '\n';
            return;
        }
    }

    for (int i = 0; i < len; i++){
        cout << res[i] << ' ';
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        solve();
    }
    return 0;
}
