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
    int n, k; cin >> n >> k;

    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // auto f = [&] (pair<int, int> l, pair<int, int> r) -> bool {
    //     if (l.first > r.first) return true;
    //     if (l.first < r.first) return false;
    //     return l.second < r.second;
    // };

    // multiset<pair<int, int>, decltype(f)> st(f);

    // for (int i = 0; i < n; i++) {
    //     st.insert({a[i], b[i]});
    // }

    // ll res = 0;

    // while (k--) { 
    //     auto [add, rem] = *st.begin();
    //     res += add;
    //     add = max(0, add - rem);
    //     st.erase(st.begin());
    //     st.insert({add, rem});
    // }

    // funciona mas k eh mt grande

    auto gauss = [&] (int x) {
        return (ll)(x) * (x + 1) / 2;
    };

    int l = 0, r = 2e9;
    ll ans = 0;

    while (l <= r) {
        int mid = (l + r) / 2;
        ll used = 0, now = 0;
        vector<int> na = a;
        for (int i = 0; i < n; i++) {
            int diff = a[i] - mid;
            if (diff <= 0) continue;
            int qnt = diff / b[i];
            debug(a[i], mid, qnt, diff);
            used += qnt;
            now += (ll)a[i] * qnt - (b[i] * gauss(qnt - 1));
            if (diff % b[i] != 0) {
                // vou usar uma vez a mais
                int n_ai = a[i] - b[i] * qnt;
                now += n_ai;
                used++;
                na[i] = max(0LL, n_ai - b[i]);
            } else {
                na[i] = mid;
            }
        }
        sort(na.rbegin(), na.rend());
        for (int i = 0; i < n; i++) {
            if (used < k) {
                used++;
                now += na[i];
            }
        }
        if (used <= k) {
            ans = max(ans, now);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;
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