#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve() {
    long long n, k, q; cin >> n >> k >> q;
    vector<long long> a(n);
    for(auto &i : a) cin >> i;
    vector<vector<long long>> all;
    vector<long long> temp;
    debug(a);
    for(int i = 0; i <= n; i++){
        if(i == n || a[i] > q) {
            if(temp.size()) all.emplace_back(temp);
            temp.clear();
        } else {
            temp.emplace_back(a[i]);
        }
    }
    long long res = 0;
    debug(all);
    for(auto u : all){
        n = u.size();
        if(n < k) continue;
        for(int i = 0; i < n; i++){
            int sz = n - i;
            if(sz < k) continue;
            res += sz - k + 1;
        }
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
