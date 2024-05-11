#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 10010, LG = 24;
int n;
string s[N];
int dp[2][3][1 << 12];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < (1 << (LG / 2)); i++) {
        for (int bit = 0; bit < (LG / 2); bit++) {
            if ((i >> bit) & 1) {

            }
        }
    }
    for (int i = 0; i < (1 << (LG / 2)); i++) {
        for (int bit = 0; bit < (LG / 2); bit++) {
            if ((i >> bit) & 1) {

            }
        }
    }
    for (int i = 0;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
