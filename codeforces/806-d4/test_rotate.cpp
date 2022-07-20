#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 1e2;

// (i,j) -> (j, n-i-1) -> (n-i-1, n-j-1) -> (n-j-1, i) -> (i,j)
// n = 4; (0,1) -> (1,3) -> (3,2) -> (2,0)

int n, M[MAX][MAX], R[MAX][MAX];

void rotate(int M[MAX][MAX]) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            R[i][j] = M[n-j-1][i];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            M[i][j] = R[i][j];
        }
    }
    memset(R, 0, sizeof(R));
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> M[i][j];
        }
    }
    rotate(M);
    cout << "90" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << M[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    rotate(M);
    cout << "180" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << M[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    rotate(M);
    cout << "270" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << M[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int main(){ _
    int testcases; cin >> testcases;
    for (int i = 0; i < testcases; i++){
        solve();
    }
    return 0;
}
