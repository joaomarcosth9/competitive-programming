#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

const int MAX = 2e5+50;
int arr[MAX], pref[MAX], res;
map<int,int> freq;

void solve(){
    int n, s; cin >> n >> s;
    memset(arr, 0, arr+n);
    memset(pref, 0, pref+n);
    freq.clear();
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        pref[i+1] = pref[i] + arr[i];
    }

    int res = 0;

    cout << res << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
