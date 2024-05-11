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
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int &it : a) cin >> it;
    int l = 0, r = 2e9;
    int ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        ll need = 0;
        for (int i = 0; i < n; i++) {
            need += max(0, (a[i] - mid));
        }
        if (need <= (ll)x) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
