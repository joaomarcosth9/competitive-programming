#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
#define int ll
using ll = long long;

void solve() {
    int n, k, pb, ps; cin >> n >> k >> pb >> ps; // Bodya, Sasha
    pb--, ps--;
    vector<int> p(n), a(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    int mx_point = *max_element(a.begin(), a.end());
    int mx_bodya = k * a[pb], mx_sasha = k * a[ps];
    int cur_bodya = a[pb];
    for (int i = 1; i < n && k - i > 0; i++) {
        pb = p[pb] - 1;
        int rm = k - i;
        mx_bodya = max(mx_bodya, cur_bodya + rm * a[pb]);
        cur_bodya += a[pb];
    }
    int cur_sasha = a[ps];
    for (int i = 1; i < n && k - i > 0; i++) {
        ps = p[ps] - 1;
        int rm = k - i;
        mx_sasha = max(mx_sasha, cur_sasha + rm * a[ps]);
        cur_sasha += a[ps];
    }
    debug(mx_bodya, mx_sasha);
    if (mx_sasha > mx_bodya) {
        cout << "Sasha" << endl;
    } else if (mx_sasha < mx_bodya) {
        cout << "Bodya" << endl;
    } else {
        cout << "Draw" << endl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
