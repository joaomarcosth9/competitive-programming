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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> cnt(n);
    debug(a);
    for (int i = 0; i < n; i++) {
        if ((a[i] % a[0]) == 0) cnt[i]++;
    }
    for (int j = 0; j < n; j++) {
        if (cnt[j] == 0) {
            for (int i = j; i < n; i++) {
                if ((a[i] % a[j]) == 0) cnt[i]++;
            }
            break;
        }
    }
    for (int j = 0; j < n; j++) {
        if (cnt[j] == 0) return 0;
    }
    return 1;
    debug(cnt);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt; cin >> tt;
    while (tt--) {
        cout << (solve() ? "Yes" : "No") << endl;
    }
}
