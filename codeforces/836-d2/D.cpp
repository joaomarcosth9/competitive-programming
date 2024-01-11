#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif
#define endl '\n'
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto& x){ return res; }
#define L2(res...) [&](const auto& x, const auto& y){ return res; }
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

ll pa(ll l, ll qnt) {
    ll r = l + qnt - 1;
    return (l + r) * (r - l + 1) / 2;
}

void solve() {
    ll n; cin >> n;

    for (ll off = 1; off <= 100000; off *= 10) {

        ll l = 1, r = 1e6;
        ll target = (n + off) * (n + off);
        ll ans = -1;

        while (l <= r) {
            ll mid = midpoint(l, r);
            ll mx = mid + n + off;
            ll minsum = mid + mx + pa(mid + 1, n - 2);
            ll maxsum = mid + mx + pa(mx - (n - 2), n - 2);
            if (target >= minsum && target <= maxsum) {
                ans = mid;
                break;
            } else if (target <= minsum) {
                r = mid - 1;
            } else l = mid + 1;
        }

        debug(ans);

        vector<ll> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = ans + i;
        }
        res.back() += off + 1;

        ll sum = accumulate(all(res), 0ll);

        for (int i = n - 2; i > 0; i--) {
            ll add = target - sum;
            if (res[i] + add < res[i + 1]) {
                res[i] += add;
                sum += add;
                break;
            } else {
                sum -= res[i];
                res[i] = res[i + 1] - 1;
                sum += res[i];
            }
        }

        if (accumulate(all(res), 0ll) != sum) continue;

        if ((res.back() - res[0]) * (res.back() - res[0]) != sum) continue;

        for (auto u : res) cout << u << " ";
        cout << endl;
        return;
    }
    cout << -1 << endl;

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
