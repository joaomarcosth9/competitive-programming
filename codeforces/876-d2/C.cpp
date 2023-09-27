#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif



void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &e : a) cin >> e;
    if(a.back() == 1){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    int o = 0;
    for(int i = n - 2; i >= 0; i--){
        if(a[i] == 0){
            cout << o << " ";
            o = 0;
        } else {
            cout << 0 << " ";
            o++;
        }
    }
    cout << o << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
