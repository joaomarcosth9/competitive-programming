#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 1e5;
int n, arr[MAX];

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    while(n>0){
        sort(arr, arr+n);
        for(int i = 0; i < n-1; i++){
            arr[i] = arr[i+1] - arr[i];
        }
        n--;
    }
    cout << arr[0] << endl;
}

int main(){ _
    int testcases; cin >> testcases;
    for (int i = 0; i < testcases; i++){
        solve();
    }
    return 0;
}
