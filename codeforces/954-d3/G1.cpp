#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
using ll = long long;

const int N = 5e5 + 5;
vector<int> d[N];
int cnt[N];

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    ll res = 0;
    vector<map<int, int>> freq(n + 1);
    for (int i = 1; i <= n; i++) {
        int g = gcd(i, p[i]);
        int ni = i / g;
        int npi = p[i] / g;
        auto &dnpi = d[npi];
        for (int x : dnpi) {
            freq[x][ni]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        int g = gcd(i, p[i]);
        int ni = i / g;
        int npi = p[i] / g;
        auto &dnpi = d[npi];
        for (int x : dnpi) {
            res += freq[ni][x];
        }
    }
    cout << res << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC;
    cin >> TC;
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i) cnt[j]++;
    for (int i = 1; i < N; i++) d[i].reserve(cnt[i]);
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i) d[j].push_back(i);
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}
