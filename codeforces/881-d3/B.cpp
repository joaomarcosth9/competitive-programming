
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
    for(int &i : a) cin >> i;
    long long res = 0;
    for(int &i : a) res += abs(i);
    int mn = 0;
    bool isneg = 0;
    for(int &i : a) {
        if(isneg && i <= 0) continue;
        if(!isneg && i < 0){
            isneg = 1;
        } else if(isneg && i > 0) {
            mn++;
            isneg = 0;
        }
    }
    if(isneg) mn++;
    cout << res << " " << mn << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if (TC) { cin >> TC;
        while (TC--) solve();
    } else solve();
    return 0;
}
