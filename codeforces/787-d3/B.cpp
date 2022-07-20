#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 1e2;
int n, arr[MAX];

void solve(){
    cin >> n; for(int i = 0; i < n; i++) cin >> arr[i];
    int op = 0;
    if(n == 1){
        cout << 0 << endl;
        return;
    }
    if(arr[n-1] == 0){
        cout << -1 << endl;
        return;
    }
    for(int i = n-2; i >= 0; i--){
        while(arr[i] >= arr[i+1]){
            arr[i] /= 2;
            op++;
        }
        if(arr[i] == 0 && i != 0){
            cout << -1 << endl;
            return;
        }
    }
    cout << op << endl;
}

int main(){ _
    int tscf; cin >> tscf;
    while(tscf--) solve();
    return 0;
}
