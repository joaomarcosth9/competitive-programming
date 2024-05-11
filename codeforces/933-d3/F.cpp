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

ll solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<ll> a(n), d(m), f(k);
    for (ll &i : a) cin >> i;
    for (ll &i : d) cin >> i;
    for (ll &i : f) cin >> i;

    sort(a.begin(), a.end());
    sort(d.begin(), d.end());
    sort(f.begin(), f.end());

    ll mx = 0;
    int where = -1;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] > mx) {
            mx = a[i] - a[i - 1];
            where = i;
        }
    }

    for (int i = 1; i < n; i++) if (i != where) {
        if (a[i] - a[i - 1] == mx) {
            return mx;
        }
    }

    multiset<ll> A;
    for (int i = 1; i < n; i++) if (i != where) {
        A.insert(a[i] - a[i - 1]);
    }

    ll L = a[where - 1];
    ll R = a[where];

    ll value1 = L + (R - L) / 2;
    ll value2 = value1 + ((R - L) & 1);

    ll ans = mx;

    for (int i = 0; i < m; i++) {
        auto test = [&] (ll value) {
            ll need = value - d[i];
            ll res = LLONG_MAX;
            int where2 = (int)(lower_bound(f.begin(), f.end(), need) - f.begin());
            if (where2 >= 0 && where2 < k) {
                ll done = d[i] + f[where2];
                A.insert(R - done);
                A.insert(done - L);
                res = min(res, *A.rbegin());
                A.erase(A.find(R - done));
                A.erase(A.find(done - L));
            }
            where2 = (int)(upper_bound(f.begin(), f.end(), need) - f.begin());
            where2--;
            if (where2 >= 0 && where2 < k) {
                ll done = d[i] + f[where2];
                A.insert(R - done);
                A.insert(done - L);
                res = min(res, *A.rbegin());
                A.erase(A.find(R - done));
                A.erase(A.find(done - L));
            }
            return res;
        };
        ans = min(ans, test(value1));
        ans = min(ans, test(value2));
    }

    return ans;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        /* solve(); */
        cout << solve() << endl;
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
