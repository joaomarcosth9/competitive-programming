#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> M(502, vector<char> (502));
char w = 'o';
char b = '.';
char p = '#';
int n, m;

void water(int i, int j){
    if(M[i][j] == b){
        M[i][j] = w;
        if (M[i+1][j] == p){
            if (j != (m-1))
                water(i, j+1);
            if(j != 0)
                water(i, j-1);
        } else if (M[i+1][j] == b){
            if (i != (n-1))
                water(i+1, j);
        }
    }
}

void solve(){
    cin >> n >> m;
    int start;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> M[i][j];
        }
    }
    for (int j = 0; j < m; j++){
        if (M[0][j] == w){
            start = j;
        }
    }
    M[0][start] = b;
    water(0, start);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << M[i][j];
    }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
