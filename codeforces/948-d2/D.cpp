#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long uniform(long long l, long long r) {
    uniform_int_distribution<long long> uid(l, r);
    return uid(rng);
}

void solve() {
    int n, m; cin >> n >> m;

    vector a(n, vector<int> (m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            a[i][j] = c - '0';
        }
    }

    vector<ll> id(n);

    for (int i = 0; i < n; i++) {
        id[i] = (rng() % (ll)1e18);
        // id[i] = 1 << i;
    }

    map<ll, int> score;
    vector h(n, vector<ll> (m));

    for (int j = 0; j < m; j++) {
        vector<ll> pref(n), suff(n);

        for (int i = 0; i < n; i++) {
            if (a[i][j] == 1) {
                pref[i] = (i > 0 ? pref[i - 1] : 0) ^ id[i];
            } else {
                pref[i] = (i > 0 ? pref[i - 1] : 0);
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (a[i][j] == 1) {
                suff[i] = (i < n - 1 ? suff[i + 1] : 0) ^ id[i];
            } else {
                suff[i] = (i < n - 1 ? suff[i + 1] : 0);
            }
        }

        for (int i = 0; i < n; i++) {
            ll now = 0;
            if (a[i][j] == 0) {
                now = id[i];
            }
            if (i > 0) now ^= pref[i - 1];
            if (i < n - 1) now ^= suff[i + 1];
            score[now]++;
            // para a coluna j, o hash now acendeu a linha i
            h[i][j] = now;
        }

    }

    pair<ll, int> res = {0, -1};

    for (auto u : score) {
        if (u.second > res.second) {
            res = u;
        }
    }

    assert(res.second != -1);

    cout << res.second << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (h[i][j] != res.first) continue;
            // i aceso, resto apagado

            vector<int> on(n);

            for (int k = 0; k < n; k++) {
                if (k == i) {
                    if (a[k][j] == 0) {
                        on[k] = 1;
                    }
                } else {
                    if (a[k][j] == 1) {
                        on[k] = 1;
                    }
                }
            }

            for (auto u : on)
                cout << u;
            cout << endl;

            return;
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