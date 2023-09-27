#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

const int MAX = 1e7 + 10;
int lp[MAX + 1], factor[MAX + 1];
vector<int> pr;
void build() {
    for (int i = 2; i <= MAX; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= MAX; ++j) {
            lp[i * pr[j]] = pr[j];
            factor[i * pr[j]] = i;
            if (pr[j] == lp[i]) break;
        }
    }
}
vector<int> factorize(int x) {
    if (x < 2) return {};
    vector<int> v;
    for (int lpx = lp[x]; x >= lpx; x = factor[x]) v.emplace_back(lp[x]);
    return v;
}

void solve() {
    int n, kk;
    cin >> n >> kk;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int res = 1;
    map<long long, bool> m;
    for (int i = 0; i < n; i++) {
        auto u = factorize(v[i]);
        map<int, int> f;
        for (auto a : u) {
            f[a]++;
        }
        long long h = 1;
        for (auto [k, v] : f) {
            if (v & 1) {
                h *= k;
            }
        }
        if (m[h]) {
            res++;
            m.clear();
        }
        m[h] = 1;
    }
    cout << res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    build();
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
