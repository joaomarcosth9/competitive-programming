#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

const long long NONE = LLONG_MAX;

#define EPS 1e-9

void solve() {
    long long n, m;
    cin >> n >> m;
    vector<long long> l;
    for (long long i = 0; i < n; i++) {
        long long k;
        cin >> k;
        l.push_back(k);
    }
    vector<int> neg, pos;
    sort(begin(l), end(l));
    vector<pair<bool, long long>> res(m);
    for (long long i = 0; i < m; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        long long ac4 = (a * c) * 4;
        auto lb = lower_bound(begin(l), end(l), b);
        if (lb == end(l)) {
            lb--;
        }
        auto u = b - *lb;
        if (u * u < ac4) {
            res[i] = {1, *lb};
            continue;
        }
        if (lb != begin(l)) {
            lb--;
            u = b - *lb;
            if (u * u < ac4) {
                res[i] = {1, *lb};
                continue;
            }
        }
    }
    for (long long i = 0; i < m; i++) {
        if (res[i].first) {
            cout << "YES" << endl;
            cout << res[i].second << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long TC = 1;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
