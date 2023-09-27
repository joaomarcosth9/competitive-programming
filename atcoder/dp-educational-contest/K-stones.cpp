#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
const int maxn = 1e2 + 5, maxa = 1e5 + 5;
int a[maxn], mex[maxa];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    mex[0] = 0;
    int last = 0;
    debug(vec(a, n));
    for (int i = 1; i <= k; i++) {
        set<int> st;
        for (int j = 0; j < n; j++) {
            if (a[j] > i) continue;
            st.emplace(mex[i - a[j]]);
        }
        int search = 0;
        int cmex = 0;
        for (auto u : st) {
            if (u == cmex) {
                cmex += 1;
            } else {
                break;
            }
        }
        mex[i] = cmex;
    }
    cout << (mex[k] ? "First" : "Second") << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
