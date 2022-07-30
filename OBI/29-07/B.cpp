#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 1e4;
int n, arr[MAX];

void solve(){
    cin >> n; for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr,arr+n);
    int dr = 0;
    if(arr[0] > 8) dr++;
    for(int i = 1; i < n && !dr; i++){
        if(arr[i] - arr[i-1] > 8){
            dr++;
        }
    }
    if(!dr){
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }
}

int main(){ _
    solve();
    return 0;
}
