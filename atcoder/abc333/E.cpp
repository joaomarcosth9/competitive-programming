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
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    map<int, int> pending;
    vector<int> need;

    for (int i = n - 1; i >= 0; i--) {
        auto [ti, xi] = a[i];
        if (ti == 1) { // found a potion
            if (pending[xi]) {
                pending[xi]--;
                need.emplace_back(1);
            } else {
                need.emplace_back(0);
            }
        } else { // found a monster
            pending[xi]++;
        }
    }

    for (auto [k, v] : pending) {
        if (v > 0) {
            cout << -1 << endl;
            return;
        }
    }

    reverse(begin(need), end(need));

    int mx = 0, now = 0, it = 0;
    for (int i = 0; i < n; i++) {
        auto [ti, xi] = a[i];
        if (ti == 1) { // found a potion
            if (need[it]) now++;
            it++;
            mx = max(mx, now);
        } else { // found a monster
            now--;
        }
    }

    cout << mx << endl;
    for (auto u : need) cout << u << " ";
    cout << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
