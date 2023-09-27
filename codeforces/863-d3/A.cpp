#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve() {
    int n, N;
    cin >> n >> N;
    string s;
    cin >> s;
    for (int i = 0; i <= n; i++) {
        if (i == n) {
            if (N != -1) cout << N;
            break;
        }
        int nu = s[i] - '0';
        if (nu < N) {
            cout << N;
            N = -1;
            i--;
        } else
            cout << nu;
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
