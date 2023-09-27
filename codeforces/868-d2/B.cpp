#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve(){
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(int &a : v) cin >> a;
    vector<set<int>> mods(k);
    for(int i = 0; i < n; i++){
        mods[i % k].insert(i+1);
    }
    db(mods);
    int dr = 0;
    for(int i = 0; i < n; i++){
        int pos = i % k;
        if(mods[pos].find(v[i]) == mods[pos].end()) {
            dr++;
        }
    }
    if(!dr){
        cout << 0 << '\n';
    } else if(dr == 2){
        cout << 1 << '\n';
    } else {
        cout << -1 << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
