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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    map<int, int> f;

    for (auto &x : a) {
        cin >> x;
        f[x]++;
    }

    sort(a.begin(), a.end());

    a.erase(unique(a.begin(), a.end()), a.end());

    n = int(a.size());

    vector<int> pref(n);
    pref[0] = f[a[0]];
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + f[a[i]];
    }

    auto query = [&] (int l, int r) {
        if (l == 0) return pref[r];
        return pref[r] - pref[l - 1];
    };

    int res = 0;

    for (int i = 0; i < n; i++) {
        int j = i;
        while (j + 1 < n && j + 1 < i + k && a[j + 1] == a[j] + 1) {
            j++;
        }

        // [i, j]
        res = max(res, query(i, j));

        while (j + 1 < n && a[j + 1] == a[j] + 1) {
            j++;
            res = max(res, query(j - k + 1, j));
        }

        i = j;
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