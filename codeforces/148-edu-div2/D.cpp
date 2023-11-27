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

void solve() {
    int n, q; cin >> n >> q;
    vector<ll> a(n);
    for (ll &i : a) cin >> i;
    sort(all(a));

    auto b1 = a;
    for (int i = 0; i < n; i++) {
        b1[i] += n - i;
    }

    vector<ll> res(n), suffmin(n + 1, 2e9), prefmin(n, 2e9);

    for (int i = n - 1; i >= 0; i--) {
        suffmin[i] = min(suffmin[i + 1], a[i]);
    }
    prefmin[0] = b1[0];
    for (int i = 1; i < n; i++) {
        prefmin[i] = min(prefmin[i - 1], b1[i]);
    }

    for (int i = 0; i < n; i++) {
        res[i] = min(suffmin[i + 1], prefmin[i] - (n - i - 1));
    }

    ll sum = accumulate(all(b1), 0ll);

    while (q--) {
        int k; cin >> k;
        if (k <= n) { // da pra precomputar
            cout << res[k - 1] << " ";
        } else { // ??? 
            int op_add = n - ((n % 2) != (k % 2));
            assert((k - op_add) % 2 == 0);
            int op_sub = (k - op_add) / 2;

            bool last = (n % 2) != (k % 2);

            ll sum_now = sum;
            ll bn = b1[n - 1];

            if (last) {
                sum_now -= 1;
                bn -= 1;
            } else {
                bn += (k - n);
            }

            ll add = 1ll * (k - n) * (n - last);

            sum_now += add;

            ll target = sum_now - op_sub;
            ll each = target / n;

            debug(prefmin[n - 2] + (k - n), bn, each);

            cout << min({prefmin[n - 2] + (k - n), bn, each}) << " ";

        }
    }
    cout << endl;
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
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
