#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 1e2;
typedef long long ll;
ll pascal[60][60];

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < 50; i++) for(int j = 0; j < 50; j++){
        if(i == j || j == 0) pascal[i][j] = 1;
        else pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
    }
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            if(j>i) break;
            cout << pascal[i][j] << ' ';
        }
        cout << endl;
    }
    int res = pow(2, n)-1;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
    }
    cout << res << endl;
}

int main(){ _
    solve();
    return 0;
}
