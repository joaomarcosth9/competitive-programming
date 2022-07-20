#include <bits/stdc++.h>

using namespace std;

vector<string> M(502);
vector<vector<int>> IsInLava(502, vector<int>(502, 0));

void lava(int i, int j, char f){
    if(IsInLava[i][j]){
        if(M[i][j+1] <= f && !(IsInLava[i][j+1])){
            IsInLava[i][j+1]++;
            lava(i, j+1, f);
        }
        if(M[i][j-1] <= f && !(IsInLava[i][j-1])){
            IsInLava[i][j-1]++;
            lava(i, j-1, f);
        }
        if(M[i+1][j] <= f && !(IsInLava[i+1][j])){
            IsInLava[i+1][j]++;
            lava(i+1, j, f);
        }
        if(M[i-1][j] <= f && !(IsInLava[i-1][j])){
            IsInLava[i-1][j]++;
            lava(i-1, j, f);
        }
    }
}

void solve(){
    int n, fo; cin >> n >> fo;

    char f = fo + 48; 

    string S(n+2, 'A');

    M[0] = S;

    for (int i = 1; i <= n; i++){
        cin >> M[i];
        M[i] = "A" + M[i] + "A";
    }

    M[n+1] = S;

    if (M[1][1] <= f){
        IsInLava[1][1]++;
    }

    lava(1, 1, f);

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if(IsInLava[i][j]){
                cout << '*';
            } else {
                cout << M[i][j];
            }
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
