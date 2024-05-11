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
    for (int &i : a) cin >> i;
    if (count(a.begin(), a.end(), 0) == 0) {
        cout << n << endl;
        for (int i = 1; i <= n; i++) {
            cout << i << " " << i << endl;
        }
        return;
    }
    map<int, int> f;
    for (auto u : a) f[u]++;
    debug(f);
    for (int i = 0; i < n; i++) {
        if (f[i]) continue;
        map<int, int> f2;
        int cnt = 0;
        debug(i);
        for (int j = 0; j < n; j++) {
            f2[a[j]]++;
            if (f2[a[j]] == 1 && a[j] < i) {
                cnt++;
            }
            f[a[j]]--;
            debug(f2);
            debug(f);
            if (a[j] < i && f[a[j]] == 0) {
                cout << -1 << endl;
                return;
            }
            if (cnt == i) {
                cout << 2 << endl;
                cout << "1 " << j + 1 << endl;
                cout << j + 2 << " " << n << endl;
                return;
            }
        }
        break;
    }
    cout << -1 << endl;
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
