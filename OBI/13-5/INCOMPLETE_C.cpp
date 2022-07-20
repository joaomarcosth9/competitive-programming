#include <bits/stdc++.h>

// problema das ilhas, achar o menor e maior ping
// precisa de dijkstra

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(m,vector<int>(3));
    for (int i = 0; i < m; i++){
        cin >> A[i][0] >> A[i][1] >> A[i][2];
    }
    int server; cin >> server;
    unordered_map<int, int> dist;
    unordered_map<int, int> C;

    for (int i = 0; i < n; i++){ 
        if (A[i][0] == server){
            C[A[i][1]] = A[i][2];

        } else if (A[i][1] == server){
            C[A[i][0]] = A[i][2];
        }
    }

    int smaller = 0;
    int bigger = 0;

    for (int i=0; i < n; i++){
        if (i != server){
            if ((C[i] < smaller && C[i] != 0) || smaller == 0){
                smaller = C[i];
            }
            if (C[i] > bigger){
                bigger = C[i];
            }
        }
    }
    cout << bigger - smaller << endl;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
