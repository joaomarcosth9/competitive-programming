#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

bool prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (prime(i ^ j)) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int> best(n + 1, 2e9);
    for (int num_colors = 4; num_colors <= 4; num_colors++) {
        // mask of (num_colors) bits
        vector<int> color(n + 1, -1);
        ll p = pow(num_colors, n);
        for (int i = 1; i <= p; i++) {
            int cur = i;
            for (int j = 1; j <= n; j++) {
                color[j] = cur % num_colors;
                cur /= num_colors;
            }
            bool dr = 0;
            for (int j = 1; j <= n; j++) {
                for (int k : adj[j]) {
                    if (color[j] == color[k]) {
                        dr = 1;
                        break;
                    }
                }
                if (dr) break;
            }
            if (!dr) {
                best = min(best, color);
            }
        }
    }
    cout << 4 << endl;
    for (int i = 1; i <= n; i++) {
        cout << best[i] + 1 << ' ';
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
