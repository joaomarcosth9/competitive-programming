#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
const int maxn = 2e5 + 5;
int a[maxn];

void solve() {
    int n; cin >> n;
    int res = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        res &= a[i];
    }
    debug(res);
    if(res > 0){
        cout << 1 << '\n';
        return;
    } else {
        int g = 0;
        int cand = INT_MAX;
        for (int i = 0; i < n; i++) {
            cand &= a[i];
            if(cand == 0){
                g++;
                cand = INT_MAX;
            }
        }
        cout << g << '\n';
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
