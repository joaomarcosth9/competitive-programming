#include <bits/stdc++.h>

// BINGO QUE DA TIMELIMIT

using namespace std;

void print_vector(vector<int>& vector){
    for (int i = 0; i < vector.size(); i++){
        cout << vector[i] << ' ';
    }
    cout << endl;
}

void solve(){
    int n, k, u;    
    cin >> n >> k >> u;
    vector<vector<int>> A(n+1);
    for (int i = 1; i <= n; i++){
        A[i].push_back(0);
        for (int j = 0; j < k; j++){
            int input; cin >> input;
            A[i].push_back(input);
        }
    }

    vector<int> Winners;

    vector<int> U(u+1);

    int somewin = 0;

    for (int i = 0; i < u; i++){
        cin >> U[i];
        for (int j = 1; j <= n; j++){
            for (int l = 1; l <= k; l++){
                if (A[j][l] == U[i]){
                    A[j][0]++;
                    if (A[j][0] == k){
                        Winners.push_back(j);
                        somewin++;
                    }
                }
            }
        }
        if (somewin)
            break;
    }
    for (int i = 0; i < Winners.size(); i++){
        cout << Winners[i] << ' ';
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
