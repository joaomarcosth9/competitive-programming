#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define endl '\n'
#define cerr                                                                                                           \
    if (false) cerr
#endif
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto &x) { return res; }
#define L2(res...) [&](const auto &x, const auto &y) { return res; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef tuple<int, int, int> i3;

ll dis(ii a, ii b) { return abs(a.first - b.first) + abs(a.second - b.second); }

void solve() {
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    a--;
    b--;
    vector<ii> v(n);
    for (auto &u : v) cin >> u.first >> u.second;
    if (a < k && b < k) {
        cout << 0 << endl;
        return;
    }
    ii closest_to_a = v[0];
    ll best_dis = dis(v[a], v[0]);

    for (ll i = 1; i < k; i++) {
        if (dis(v[a], v[i]) < best_dis) {
            best_dis = dis(v[a], v[i]);
            closest_to_a = v[i];
        }
    }

    ii closest_to_b = v[0];
    best_dis = dis(v[b], v[0]);
    for (ll i = 1; i < k; i++) {
        if (dis(v[b], v[i]) < best_dis) {
            best_dis = dis(v[b], v[i]);
            closest_to_b = v[i];
        }
    }

    debug(v[a], v[b]);

    ll best = min(dis(v[a], v[b]), dis(v[a], closest_to_a) + dis(v[b], closest_to_b));
    cout << best << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        int TEST = 1;
        while (TEST <= TC) {
            cerr << "[Testcase " << TEST << "]" << endl;
            solve();
            ++TEST;
        }
    } else
        solve();
}
