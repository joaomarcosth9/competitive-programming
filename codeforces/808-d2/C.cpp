#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 1e5+500;
int n, q, arr[MAX], res[MAX];

void solve(){
    cin >> n >> q;
    memset(res, 0, sizeof(res));
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] <= q) res[i] = 1;
    }
    for(int i = n-1; i >= 0; i--){
        if(q){
            res[i] = 1;
            q--;
        }
    }
    for(int i = 0; i < n; i++){
        cout << res[i];
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
