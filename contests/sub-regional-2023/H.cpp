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
    int n, s;
    cin >> n >> s;

    vector<tuple<int, int, int>> events;

    vector<int> cost(n), L(n), R(n);

    for (int i = 0; i < n; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        tie(L[i], R[i], cost[i]) = {l, r, c};
        events.push_back({l, 1, i});
        events.push_back({r, 2, i});
    }

    sort(begin(events), end(events));

    set<pair<int, int>> active;

    vector<int> val_active(n);

    ll max_out = 0;

    for (auto [t, type, id] : events) {
        if (type == 2) {
            assert(active.count({val_active[id], id}));
            active.erase({val_active[id], id});

            ll quit_now = val_active[id] + (t + 1) * s;
            max_out = max(max_out, quit_now);

        } else if (type == 1) {
            ll quit_now = -1;

            if (active.size()) {
                auto [value, id] = *active.rbegin();
                value += t * s;
                quit_now = value;
            }

            max_out = max(max_out, quit_now);

            active.insert({-t * s + max_out - cost[id], id});
            val_active[id] = -t * s + max_out - cost[id];
        }
    }

    cout << max_out << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}