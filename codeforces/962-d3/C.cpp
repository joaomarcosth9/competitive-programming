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
    int n, q; cin >> n >> q;

    string s, t; cin >> s >> t;
    vector<vector<int>> freq1(n + 1, vector<int> (26));
    vector<vector<int>> freq2(n + 1, vector<int> (26));

    for (int i = 0; i < n; i++) {
        freq1[i + 1] = freq1[i];
        freq2[i + 1] = freq2[i];
        freq1[i + 1][s[i] - 'a']++;
        freq2[i + 1][t[i] - 'a']++;
    }

    while (q--) {
        int l, r; cin >> l >> r;
        vector<int> f1(26), f2(26);
        for (int i = 0; i < 26; i++) {
            f1[i] = freq1[r][i] - freq1[l - 1][i];
            f2[i] = freq2[r][i] - freq2[l - 1][i];
        }
        int diff = 0;
        for (int i = 0; i < 26; i++) {
            diff += abs(f1[i] - f2[i]);
        }
        cout << diff / 2 << endl;
    }

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