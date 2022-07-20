#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 1e3;

int n, p, x, arr[MAX], vis[MAX];

void solve(){
    cin >> n >> x;
    p = 2*n;
    int res = 1;
    for(int i = 0; i < p; i++){
        cin >> arr[i];
    }
    memset(vis, 0, sizeof(vis));
    sort(arr, arr+p);
    for(int i = 0; i < n; i++){
        int j = i + n;
        if(arr[j] - arr[i] < x) res = 0;
    }
    cout << (res?"YES":"NO") << endl;
}

int main(){ _
    int testcases; cin >> testcases;
    for (int i = 0; i < testcases; i++){
        solve();
    }
    return 0;
}
