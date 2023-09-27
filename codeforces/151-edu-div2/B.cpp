#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define int long long

void solve() {
    vector<int> v(6);
    for(int &i : v) cin >> i;
    int dbx = v[2] - v[0];
    int dby = v[3] - v[1];
    int dcx = v[4] - v[0];
    int dcy = v[5] - v[1];
    if(dcx * dbx < 0){
        if(dcy * dby < 0){
            cout << 1 << '\n';
        } else {
            // sinal do x eh diferente
            // y eh igual
            cout << 1 + min(abs(dcy), abs(dby)) << '\n';
        }
    } else {
        if(dcy * dby < 0){
            // sinal do x eh igual, y diferente
            cout << 1 + min(abs(dcx), abs(dbx)) << '\n';
        } else {
            // tudo igual
            cout << 1 + min(abs(dcx), abs(dbx)) + min(abs(dcy), abs(dby)) << '\n';
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if (TC) { cin >> TC;
        while (TC--) solve();
    } else solve();
    return 0;
}
