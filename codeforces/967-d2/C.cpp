#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> edges;

    int Q = 15 * n;

    auto ask = [&] (int x, int y) {
        Q--;
        assert(Q >= 0);
        cout << "? " << x << " " << y << endl;
        int ans;
        cin >> ans;
        return ans;
    };

    auto guess = [&] () {
        assert((int)edges.size() == n - 1);
        cout << "! ";
        for (auto [u, v] : edges) {
            cout << u << " " << v << " ";
        }
        cout << endl;
    };

    vector<int> known(n + 1);
    known[1] = 1;

    function<void(int, int)> rec = [&] (int u, int v) { 
        auto x = ask(u, v);
        if (x == u) {
            known[v] = 1;
            edges.push_back({u, v});
            return;
        }
        // u ... x ... v
        if (!known[x]) {
            rec(u, x);
        }
        assert(known[x]);
        rec(x, v);
    };

    for (int v = 2; v <= n; v++) {
        rec(1, v);
    }

    guess();

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