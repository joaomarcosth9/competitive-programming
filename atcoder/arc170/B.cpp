#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
#define int ll
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    vector first(11, vector<int> (n + 1));
    for (int i = 1; i <= 10; i++) first[i][n] = n;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j <= 10; j++) first[j][i] = first[j][i + 1];
        first[a[i]][i] = i;
    }

    vector<tuple<int, int, int>> pas;
    for (int i = 1; i <= 10; i++) {
        for (int r = -10; r <= 10; r++) {
            if (i + 2 * r <= 10 && i + r * 2 >= 1) {
                pas.emplace_back(i, i + r, i + 2 * r);
            }
        }
    }

    debug(pas);

    ll res = 0;

    for (int i = 0; i < n; i++) {
        int l = 0, r = i;
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            bool db = 0;
            for (auto [a0, a1, a2] : pas) {
                int nxt = first[a0][mid];
                if (nxt < n) {
                    nxt = first[a1][nxt + 1];
                }
                if (nxt < n) {
                    nxt = first[a2][nxt + 1];
                }
                if (nxt <= i) {
                    db = 1;
                    break;
                }
            }
            if (db) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        debug(i, ans);
        res += ans + 1;
    }

    cout << res << endl;

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
