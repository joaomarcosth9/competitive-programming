#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e3+500;
typedef long long ll;

int n, l;
vector<int> adj[MAX];

void count_dfs(int node){
}

void solve(){
    cin >> n >> l;
    for(int i = 0; i < l; i++){
        int a; cin >> a;
        while(a--){
            int nn; cin >> nn;
            adj[i+1].push_back(nn);
        }
    }
}

int main(){
    /* ios_base::sync_with_stdio(0); */
    /* cin.tie(0); */
    solve();
}
