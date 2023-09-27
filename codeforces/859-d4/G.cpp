#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif
#define int long long

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(int& i : v) cin >> i;
    if(v.size() == 1 && v[0] != 1 || v.size() == 2 && v[0] != 1 && v[1] != 1){
        cout << "NO" << endl;
        return;
    }
    sort(begin(v), end(v));
    db(v);
    int one = 0;
    for(int i = 0; i < n; i++){
        if(v[i] == 1){
            one++; continue;
        } else {
            if(v[i] > one){
                cout << "NO" << endl;
                return;
            }
            one += v[i];
        }
    }
    cout << "YES" << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
