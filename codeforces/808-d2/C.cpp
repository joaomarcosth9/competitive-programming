#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 1e5+500;
int n, q, arr[MAX], res[MAX];

void solve(){
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int qi = 0;
    for(int i = n-1; i >= 0; i--){
        if(arr[i] <= qi){
            res[i] = 1;
        } else if (qi < q){
            qi++;
            res[i] = 1;
        } else {
            res[i] = 0;
        }
    }
    for(int i = 0; i < n; i++) cout << res[i];
    cout << endl;
}

int main(){ _
    int testcases; cin >> testcases;
    for (int i = 0; i < testcases; i++){
        solve();
    }
    return 0;
}
