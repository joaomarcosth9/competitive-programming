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
    int n, A; cin >> n >> A;
    vector<int> t(n);

    for (int &T : t)
        cin >> T;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    int rmost = 0;

    for (int &T : t) {
        pq.emplace(T, 1);
    }

    while (pq.size()) {
        auto [time, type] = pq.top();
        rmost = max(time, rmost);
        pq.pop();
        if (type == 0) {
            cout << time << endl;
        } else {
            pq.emplace(rmost + A, 0);
            rmost = rmost + A;
        }
    }

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}