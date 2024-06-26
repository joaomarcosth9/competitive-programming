#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    map<char, int> freq;
    for (char c = 'A'; c <= 'G'; c++) {
        freq[c] = m;
    }
    for (char c : s) {
        freq[c]--;
    }
    int res = 0;
    for (char c = 'A'; c <= 'G'; c++) {
        if (freq[c] > 0) {
            res += freq[c];
        }
    }
    cout << res << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}