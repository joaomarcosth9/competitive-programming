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
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    string s;
    cin >> s;

    vector<ll> pref(n);

    pref[0] = a[0];
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }

    auto query = [&] (int l, int r) {
        if (l == 0) return pref[r];
        return pref[r] - pref[l - 1];
    };

    ll res = 0;

    int R = n - 1;
    for (int L = 0; L < R; L++) {
        if (s[L] != 'L') {
            continue;
        }
        while (R > L && s[R] == 'L') {
            R--;
        }
        if (R <= L) break;
        res += query(L, R);
        R--;
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