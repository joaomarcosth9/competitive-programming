#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> segs(n);
    for (int i = 0; i < n; i++) {
        cin >> segs[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> segs[i].second;
    }

    long long total = 0;

    sort(begin(segs), end(segs));

    for (auto [l, r] : segs) total += r - l + 1;

    if (total < k) {
        cout << -1 << '\n';
        return;
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    long long sum = 0;

    long long res = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        auto [l, r] = segs[i];
        auto len = r - l + 1;
        pq.emplace(len);
        sum += len;
        while (sum >= k) {
            long long cost = pq.size() * 2 + r - (sum - k);
            res = min(res, cost);
            auto _len = pq.top();
            sum -= _len;
            pq.pop();
        }
    }

    cout << res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
