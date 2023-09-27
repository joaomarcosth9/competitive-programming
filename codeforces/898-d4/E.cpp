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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;
void out(bool ans) { cout << (ans ? "YES" : "NO") << endl; }

ll solve() {
    ll n, x; cin >> n >> x;
    vector<ll> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    h.eb((ll)2e9);
    sort(all(h));
    vector<ll> pref(n + 1);

    for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + h[i];

    auto query = [&] (int l, int r) {
        return pref[r + 1] - pref[l];
    };


    ll L = 1, R = (ll)2e9;
    debug(h);
    ll ans = 1;
    while (L <= R) {
        ll mid = midpoint(L, R);
        int cnt = lower_bound(all(h), mid) - begin(h);
        debug(mid, cnt);
        ll tot = cnt * mid;
        debug(query(0, cnt - 1));
        ll used = tot - query(0, cnt - 1);
        debug(tot, used);
        if (used <= x) {
            ans = mid;
            L = mid + 1;
        } else R = mid - 1;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) { cin >> TC;
        int TEST = 1;
        while (TEST <= TC) {
            cerr << "[Testcase " << TEST << "]" << endl;
            /* solve(); */
            cout << solve() << endl;
            /* cout << (solve() ? "YES" : "NO") << endl; */
            ++TEST;
        }
    } else solve();
}
