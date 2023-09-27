#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<map<int, int>> m(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        m[a[i]][b[i]]++;
    }
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n && i * j <= 2 * n; j++) {
            int val = i * j;
            for (auto [bi, fq] : m[i]) {
                int bj = val - bi;
                auto u = m[j].find(bj);
                if (bj <= 0 || u == m[j].end()) continue;
                if (i != j || bi != bj)
                    res += 1ll * fq * u->second;
                else
                    res += 1ll * fq * u->second - fq;
            }
        }
    }
    cout << res / 2 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
