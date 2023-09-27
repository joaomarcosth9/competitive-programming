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
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    vector<int> freqa(2 * n + 1), freqb(2 * n + 1);
    int curr = a[0];
    freqa[curr] = 1;
    int hm = 1;
    for(int i = 1; i < n; i++){
        if(a[i] == curr){
            hm++;
        } else {
            curr = a[i];
            hm = 1;
        }
        freqa[curr] = max(freqa[curr], hm);
    }
    curr = b[0];
    freqb[curr] = 1;
    hm = 1;
    for(int i = 1; i < n; i++){
        if(b[i] == curr){
            hm++;
        } else {
            curr = b[i];
            hm = 1;
        }
        freqb[curr] = max(freqb[curr], hm);
    }
    int res = 1;
    for(int i = 0; i <= 2 * n; i++){
        res = max(res, freqa[i] + freqb[i]);
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
