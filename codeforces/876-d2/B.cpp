#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];

    map<int,multiset<int>> all;

    for(int i = 0; i < n; i++){
        all[a[i]].emplace(b[i]);
    }

    long long res = 0;

    for(auto [ai, sbi] : all){
        auto rb = sbi.rbegin();
        debug(ai);
        debug(sbi);
        for(int i = 0; i < ai && rb != sbi.rend(); rb++, i++){
            res += *rb;
        }
        debug(res);
    }

    cout << res << '\n';

}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
