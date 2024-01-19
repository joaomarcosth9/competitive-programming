#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

void solve() {
    ll x; cin >> x;
    int len = 0;
    vector<ll> res;
    x--;

    while (x) {
        if (x & 1) {
            res.emplace_back(1);
            x--;
            x /= 2;
        } else {
            res.emplace_back(-1);
            x--;
        }
        if (ssize(res) > 200) {
            cout << -1 << endl;
            return;
        }
    }

    int gt = 1e9;
    int sm = -1e9;
    for (int i = 0; i < ssize(res); i++) {
        if (res[i] == -1) res[i] = sm++;
        else res[i] = gt--;
    }

    reverse(begin(res), end(res));

    if (ssize(res) > 200) {
        cout << -1 << endl;
        return;
    }

    cout << size(res) << endl;
    for (auto u : res) cout << u << " ";
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
