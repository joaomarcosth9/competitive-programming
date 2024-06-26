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
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int res = -1;
    for (int i = 0; i < n - 1; i++) {
        int aa = a[i], bb = a[i + 1];
        if (aa > bb) swap(aa, bb);
        res = max(res, aa);
    }
    for (int i = 0; i < n - 2; i++) {
        int aa = a[i], bb = a[i + 1], cc = a[i + 2];
        vector<int> tmp = {aa, bb, cc};
        sort(tmp.begin(), tmp.end());
        res = max(res, tmp[1]);
    }
    cout << res << endl;
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
