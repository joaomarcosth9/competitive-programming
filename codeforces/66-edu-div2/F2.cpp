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

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) a[i]--;

    debug(a);

    vector<ll> conv(n);
    for (int i = 0; i < n; i++) conv[i] = abs((ll)rng()) % (1ll << 60);

    auto calc = [conv] (vector<int> a) {
        int n = size(a);
        vector<pair<ll, int>> poss;

        vector<ll> pref(n);
        pref[0] = conv[a[0]];
        for (int i = 1; i < n; i++) pref[i] = pref[i - 1] ^ conv[a[i]];

        auto query = [&] (int l, int r) {
            if (l == 0) return pref[r];
            return pref[r] ^ pref[l - 1];
        };

        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                int j = i + 1;
                int mx = -1;
                while (j < n && a[j] != 0) {
                    mx = max(mx, a[j]);
                    if (j - mx >= 0 && j - mx <= i) {
                        debug(i, a[i], j, a[j]);
                        poss.eb(query(j - mx, j), mx);
                    }
                    j++;
                }
                i = j - 1;
            }
        }

        return poss;
    };

    vector<ll> perm(n);
    perm[0] = conv[0];
    for (int i = 1; i < n; i++) perm[i] = perm[i - 1] ^ conv[i];

    ll res = 0;

    auto p1 = calc(a);
    for (auto [val, len] : p1) {
        debug(val, len, perm[len]);
        res += val == perm[len];
    }

    reverse(all(a));

    p1 = calc(a);
    for (auto [val, len] : p1) {
        res += val == perm[len];
    }

    cout << res + count(all(a), 0) << endl;

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
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
