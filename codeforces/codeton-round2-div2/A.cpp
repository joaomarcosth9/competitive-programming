#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

void solve(){
    int n,m; cin >> n >> m;
    string a,b; cin >> a >> b;
    int dr = 0;
    for(int i = n-m+1, j = 1; i < n; i++, j++){
        if(a[i] != b[j]) dr = 1;
    }
    for(int i = 0; i < n-m+1; i++){
        if(a[i] == b[0] && !dr){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main(){ _
    int tscf; cin >> tscf;
    while(tscf--) solve();
    return 0;
}
