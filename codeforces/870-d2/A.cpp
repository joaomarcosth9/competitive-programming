#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(x...)
#endif

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(begin(v), end(v));
    
    for(int mentirosos = 0; mentirosos <= n; mentirosos++){
        int vdd = n - mentirosos;
        int mt = 0;
        for(int i = 0; i < n; i++){
            if(v[i] > mentirosos){
                // falou que tem mais mentirosos do que realmente tem, entao tem que estar mentindo
                mt++;
            }
        }
        debug(vdd, mt, mentirosos);
        if(vdd + mt == n){
            cout << mt << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

signed main(){
    /* ios_base::sync_with_stdio(0);cin.tie(0); */
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
