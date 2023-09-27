#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve(){
    int n; cin >> n;
    vector<int> b(n-1), done(n); for(auto& u : b) cin >> u;

    vector<int> a;
    bool f = 0;

    for(int i = 0; i < n; i++){
        if(i == 0){
            a.push_back(b[i]);
        } else if(i == n-1){
            a.push_back(b.back());
        } else {
            a.push_back(min(b[i], b[i-1]));
        }
    }

    for(auto u : a) cout << u << " ";
    cout << endl;
} 

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
