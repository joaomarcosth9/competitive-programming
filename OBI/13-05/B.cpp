#include <bits/stdc++.h>

using namespace std;

int carimbadas[51];
int compradas[301];

void solve(){
    int n, c, m;
    cin >> n >> c >> m;
    for (int i = 0; i < c; i++){
        cin >> carimbadas[i];
    }
    for (int i = 0; i < m; i++){
        cin >> compradas[i];
    }
    int carimbadas_n_encontradas = 0;
    for (int i = 0; i < c; i++){
        int nao_achou= 1;
        for (int j = 0; j < m; j++){
            if (carimbadas[i] == compradas[j]){
                nao_achou = 0;
            }
        }
        if (nao_achou){
            carimbadas_n_encontradas++;
        }
    } 
    cout << carimbadas_n_encontradas << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
