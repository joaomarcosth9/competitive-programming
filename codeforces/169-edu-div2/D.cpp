#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> portals(n);

    map<char, int> conv;
    conv['B'] = 1;
    conv['G'] = 2;
    conv['Y'] = 4;
    conv['R'] = 8;
    vector<string> p(n);

    vector<set<int>> where(30);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (auto u : s) {
            portals[i] |= conv[u];
        }
        where[portals[i]].insert(i);
        p[i] = s;
    }

    while (q--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (portals[u] & portals[v]) {
            cout << abs(u - v) << endl;
        } else {
            // tenho q usar alguma cor do u pra ir pro v
            int res = 2e9;
            for (auto c : p[u]) {
                for (auto d : p[v]) {
                    assert(c != d);
                    int need = conv[c] | conv[d];
                    auto it = where[need].lower_bound(u);
                    if (it != end(where[need])) {
                        int j = *it;
                        res = min(res, abs(u - j) + abs(v - j));
                    }
                    it = where[need].upper_bound(u);
                    if (it != begin(where[need])) {
                        int j = *prev(it);
                        res = min(res, abs(u - j) + abs(v - j));
                    }
                }
            }
            if (res == 2e9) cout << -1 << endl;
            else cout << res << endl;
        }
    }

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
