#include <bits/stdc++.h> 

using namespace std; 

const int MAX = 105;
int m[MAX][MAX];
bool vis[1050];

void faz_matriz(){
    for(int i = 0; i < 103; i++){
        for(int j = 0; j < 103; j++){
            if(i == 0 || j == 0 || i == j){
                m[i][j] = 1000;
            }
        }
    }
    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= 100; j++){
            if(i == j) continue;
            memset(vis, false, sizeof(vis));
            for(int k = i-1; k >= 0; k--){
                vis[m[k][j]] = true;
            }
            for(int k = j-1; k >= 0; k--){
                vis[m[i][k]] = true;
            }
            for(int k = i-1, l = j-1; k >= 0 && l >= 0; k--, l--){
                vis[m[k][l]] = true;
            }
            for(int ii = 0; ii < 1000; ii++){
                if(!vis[ii]){
                    m[i][j] = ii;
                    break;
                }
            }
        }
    }
}

void solve() {
    int n; cin >> n;
    faz_matriz();
    int win = 0;
    for(int i = 0; i < n; i++){
        int x,y; cin >> x >> y;
        if(m[x][y] == 1000){
            cout << "Y\n";
            return;
        }
        win ^= m[x][y];
    }
    cout << (win ? "Y" : "N") << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    solve(); 
} 

