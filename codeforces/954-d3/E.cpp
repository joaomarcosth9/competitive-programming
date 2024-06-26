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

const ll INF = 1e18;

ll cost0(vector<pair<int, int>> a, int k) {
    int n = (int)a.size();
    int res = 0;

    int last_one = 0;

    for (int i = 0; i < n; i++) {
        if (a[i].second) {
            if (last_one) {
                res += a[i].first - last_one;
                last_one = 0;
            } else {
                last_one = a[i].first;
            }
        }
    }

    if (last_one) {
        return INF;
    }

    return res / k;
}

ll cost1(vector<pair<int, int>> a, int k) {
    int n = (int)a.size();
    int res = 0;

    int last_one = 0, cnt_one = 0;

    for (int i = 0; i < n; i++) {
        if (a[i].second) {
            cnt_one++;
        }
    }

    if (cnt_one % 2 == 0) {
        return INF;
    }

    vector<int> pref(n + 2);
    vector<int> suff(n + 2);

    for (int i = 0; i < n; i++) {
        if (a[i].second) {
            if (last_one) {
                res += a[i].first - last_one;
                last_one = 0;
            } else {
                last_one = a[i].first;
            }
        }
        pref[i + 1] = res;
    }

    res = 0, last_one = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (a[i].second) {
            if (last_one) {
                res += abs(a[i].first - last_one);
                last_one = 0;
            } else {
                last_one = a[i].first;
            }
        }
        suff[i] = res;
    }

    res = LLONG_MAX;

    int now_can = 1;
    for (int i = 0; i < n; i++) {
        if (a[i].second) {
            if (now_can) res = min(res, pref[i] + suff[i + 1]);
            now_can ^= 1;
        }
    }

    return res / k;
}

void solve() {
    int n, k; cin >> n >> k;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    sort(a.begin(), a.end());
    map<int, int> f;

    for (auto u : a) {
        f[u]++;
    }

    ll res = 0;

    if (n & 1) {
        map<int, vector<pair<int, int>>> fk;

        for (auto [u, v] : f) {
            fk[u % k].push_back({u, v & 1});
        }

        int m = (int)fk.size();

        vector<ll> pref0(m + 1), db_pref(m + 1);
        vector<ll> suff0(m + 2), db_suff(m + 2);

        db_pref[0] = 1;
        db_suff[m] = 1;

        auto it = fk.begin();
        for (int i = 0; i < m; i++) {
            int x = cost0(it->second, k);
            pref0[i + 1] = pref0[i] + x;
            db_pref[i + 1] = db_pref[i] && (x < INF);
            if (db_pref[i] == 0) {
                pref0[i + 1] = INF;
            }
            it++;
        }

        it = --fk.end();
        for (int i = m - 1; i >= 0; i--) {
            int x = cost0(it->second, k);
            suff0[i] = suff0[i + 1] + x;
            db_suff[i] = db_suff[i + 1] && (x < INF);
            if (db_suff[i + 1] == 0) {
                suff0[i] = INF;
            }
            if (it == fk.begin()) break;
            it--;
        }

        debug(fk);
        debug(pref0);
        debug(suff0);
        debug(db_pref);
        debug(db_suff);

        int i = 0;

        res = INF;

        for (it = fk.begin(); it != fk.end(); it++, i++) {
            if (db_pref[i] && db_suff[i + 1]) {
                debug(i, it->second, cost1(it->second, k), pref0[i], suff0[i + 1]);
                res = min(res, pref0[i] + suff0[i + 1] + cost1(it->second, k));
            }
        }

        if (res >= INF) {
            res = -1;
        }

    } else {
        map<int, vector<pair<int, int>>> fk;

        for (auto [u, v] : f) {
            fk[u % k].push_back({u, v & 1});
        }

        for (auto [mk, v] : fk) {
            debug(mk, v);
            int x = cost0(v, k);
            if (x == INF) {
                res = -1;
                break;
            } else {
                res += x;
            }
        }

    }

    cout << res << endl;
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