#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(int& a : v) cin >> a;
    vector<int> pref(n+1);
    for(int i = 0; i < n; i++) pref[i+1] = v[i] + pref[i];
    int l = 1, r = n;
    int resp = 1;
    while(l <= r){
        cout << "? ";
        int mid = (l+r) >> 1;
        cout << mid << " ";
        for(int i = 1; i <= mid; i++){
            cout << i << " ";
        }
        cout << endl;
        int res; cin >> res;
        if(pref[mid] < res){
            resp = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    cout << "! " << resp << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
