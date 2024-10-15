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
    int n, c; cin >> n >> c;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a[0] += c;

    auto f = [&] (auto &l, auto &r) {
        if (l.first > r.first) return true;
        if (l.first < r.first) return false;
        return l.second < r.second;
    };

    vector<int> res(n, -1);

    set<pair<ll, int>, decltype(f)> votes(f);

    for (int i = 0; i < n; i++) {
        votes.insert({a[i], i});
    }
    res[votes.begin()->second] = 0;

    debug(res, votes);

    int erased = 0;
    for (int i = 0; i < n; i++) {
        bool need = 0;
        if (a[i] < votes.begin()->first) {
            assert(i != votes.begin()->second);
            need = 1;
        }
        debug(i, erased, need, votes);
        if (res[i] == -1) {
            res[i] = erased + need;
        }
        if (i < n - 1) {
            votes.erase({a[i], i});
            votes.erase({a[i + 1], i + 1});
            a[i + 1] += a[i];
            votes.insert({a[i + 1], i + 1});
            erased++;
        }
    }

    for (int i = 0; i < n; i++) {
        assert(res[i] != -1 && res[i] < n);
        cout << res[i] << " ";
    }
    cout << endl;
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
