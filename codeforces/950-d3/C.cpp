#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

bool solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int m; cin >> m;
    vector<int> d(m);

    for (int i = 0; i < m; i++) {
        cin >> d[i];
    }

    map<int, int> freq, ofreq;
    for (int i = 0; i < n; i++) {
        if (b[i] != a[i]) {
            freq[b[i]]++;
        }
        ofreq[b[i]]++;
    }

    bool trash = 0;

    for (int i = 0; i < m; i++) {
        // ou eu usei o valor no array final, ou eu descartei ele
        if (ofreq.count(d[i])) {
            trash = 0;
            if (freq[d[i]] > 0) {
                freq[d[i]]--;
            }
        } else {
            trash = 1;
        }
    }

    if (trash)
        return 0;

    for (int i = 0; i < n; i++) {
        if (freq[b[i]]) {
            return 0;
        }
    }

    return 1;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        // solve();
        // cout << solve() << endl;
        cout << (solve() ? "Yes" : "No") << endl;
    }
}