#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
using i3 = tuple<int, int, int>;
const int MAX = 1e4 + 5;

void solve() {
    int n;
    cin >> n;

    vector<i3> a(n);

    for (int i = 0; i < n; i++) {
        int w, s, v;
        cin >> w >> s >> v;
        a[i] = {w, s, v};
    }

    ranges::sort(a, [&] (i3& l, i3&r) {
        // se dois caras tem o mesmo peso, quem vem antes?
        // -> quem aguenta menos
        // se um cara eh mais pesado que o outro, quem vem antes?
        auto &[w1, s1, v1] = l;
        auto &[w2, s2, v2] = r;
        int f1 = s1 - w2, f2 = s2 - w1;
        if (f1 >= f2) {
            return false;
        } else {
            return true;
        }
    });

    for (int i = 1; i < n; i++) {
        auto &[w1, s1, v1] = a[i - 1];
        auto &[w2, s2, v2] = a[i];
        assert(s1 - w2 <= s2 - w1);
    }

    vector<ll> dp(MAX, 0LL);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        auto new_dp = dp;
        auto &[w, s, v] = a[i];

        for (int j = 0; j < MAX; j++) {
            if (j <= s && j + w < MAX) {
                new_dp[j + w] = max(new_dp[j + w], dp[j] + v);
            }
        }

        swap(dp, new_dp);
    }

    cout << *max_element(begin(dp), end(dp)) << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}