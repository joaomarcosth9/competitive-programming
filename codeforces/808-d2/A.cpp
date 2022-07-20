#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 2e2;
int arr[MAX], n;

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 1; i < n; i++){
        if(arr[i] % arr[i-1] == 0){
            arr[i] = arr[i-1];
        } else {
            arr[i] = (arr[i] % arr[i-1]);
        }
    }
    for(int i = 1; i < n; i++){
        if(arr[i] != arr[i-1]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(){ _
    int testcases; cin >> testcases;
    for (int i = 0; i < testcases; i++){
        solve();
    }
    return 0;
}
