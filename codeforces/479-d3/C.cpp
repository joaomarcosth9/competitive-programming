#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 2e5+10;
int n, k, arr[MAX];

void solve(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    int res = -1;
    if (k == 0){
        if(arr[0] > 1) res = arr[0]-1;
    } else if(arr[k-1] != arr[k]) res = arr[k-1];
    cout << res << endl;
}

int main(){ _
    solve();
    return 0;
}
