#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    if(n >= 15){
        int res = 1;
        map<int,int> vis;
        for(int i = 0; i < n; i++){
            vis[v[i]]++;
            if(vis[v[i]] > 2) res = 0;
        }
        cout << res << '\n';
        return;
    }
    v.insert(begin(v), 0);
    int res = INT_MIN;
    for(int i = 0; i < (1 << n); i++){
        auto u = v;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)) u[j+1] = 24 - u[j+1];
        }
        sort(begin(u), end(u));
        u.emplace_back(24);
        int now = INT_MAX;
        for(int j = 1; j < (int)u.size(); j++){
            now = min(now, u[j] - u[j-1]);
        }
        res = max(res, now);
    }
    cout << res << '\n';
}


auto main() -> signed {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC) { cin >> TC;
        while (TC--) solve();
    } else solve();
    return 0;
}
