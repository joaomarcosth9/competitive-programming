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
    int n, m; cin >> n >> m;

    vector<int> a(n), b(m);
    for (int &i : a) {
        cin >> i;
    }
    for (int &i : b) {
        cin >> i;
    }

    map<int, bool> inA;

    for (int i = 0; i < n; i++) {
        inA[a[i]] = 1;
    }

    vector<int> c(n + m);

    for (int i = 0; i < n; i++) {
        c[i] = a[i];
    }
    for (int i = 0; i < m; i++) {
        c[i + n] = b[i];
    }

    sort(c.begin(), c.end());

    for (int i = 0; i < n + m - 1; i++) {
        if (inA[c[i]] && inA[c[i + 1]]) {
            return 1;
        }
    }

    return 0;

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    // solve();
    /* cout << solve() << endl; */
    cout << (solve() ? "Yes" : "No") << endl;
}
