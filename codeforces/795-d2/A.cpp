#include <bits/stdc++.h>

using namespace std;

int arr[112345];
int npar;
int nimp;

void solve(){
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];        
    }
    npar = 0;
    nimp = 0;
    for (int i = 0; i < n; i++){
        if(arr[i] % 2 == 0){
            npar++;
        } else {
            nimp++;
        }
    }
    cout << min(npar, nimp) << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        solve();
    }
    return 0;
}
