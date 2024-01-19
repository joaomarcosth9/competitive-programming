#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

void solve() {
    int n, q; cin >> n >> q;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    ll maxx = sqrt(n) + 1;

    vector<vector<ll>> suff(maxx + 1, vector<ll>(n));
    auto ac = suff;
    auto last = suff;

    for (int j = 0; j <= maxx; j++) {
        for (int i = n - 1; i >= 0; i--) {
            if (i + j >= n) {
                suff[j][i] = a[i];
                ac[j][i] = a[i];
                last[j][i] = i;
            } else {
                suff[j][i] = a[i] + suff[j][i + j];
                ac[j][i] = suff[j][i] + ac[j][i + j];
                last[j][i] = last[j][i + j];
            }
        }
    }

    while (q--) {
        ll s, d, k; cin >> s >> d >> k;
        s--;
        // soma de a[s] + a[s + d]... + a[s + (k - 1) * d]
        if (d <= maxx) {
            ll res = ac[d][s];
            ll mx = s + (k - 1) * d;
            if (mx < last[d][s]) {
                ll qtd = (last[d][s] - mx) / d;
                res -= ac[d][mx + d] + suff[d][mx + d] * (k);
            }
            cout << res << " ";
        } else {
            ll res = 0;
            for (int i = 0; i < k; i++) {
                res += a[s] * (i + 1);
                s += d;
            }
            cout << res << " ";
        }
    }
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
