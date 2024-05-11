#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
#define int ll

void solve() {
    int n; cin >> n;
    int t; cin >> t;
    map<int, int> f;
    vector<int> a(n);
    f[0] = n;

    for (int i = 0; i < t; i++) {
        int p, d; cin >> p >> d;
        p--;
        f[a[p]]--;
        if (f[a[p]] == 0) {
            f.erase(a[p]);
        }
        a[p] += d;
        f[a[p]]++;
        cout << f.size() << endl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
