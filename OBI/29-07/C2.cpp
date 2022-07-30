#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 1e5+500;
int n,l,h;
int arr[MAX];
int marc[MAX];
int pref[MAX];
int prefm[MAX];

void solve(){
    cin >> n >> l >> h;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        cin >> marc[i];
    }
    for(int i = 1; i <= n; i++){
        pref[i] = pref[i-1] + arr[i-1];
        prefm[i] = prefm[i-1] + marc[i-1];
    }
    int res = INT_MIN;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            int nm = prefm[j] - prefm[i-1];
            if(nm < l) continue;
            else if(nm > h) continue;
            else {
                res = max(pref[j]-pref[i-1], res);
            }
        }
    }
    cout << res << endl;
}

int main(){ _
    solve();
    return 0;
}
