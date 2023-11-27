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
    vector<ll> a(n), b(q);
    for (ll &i : a) cin >> i;
    for (ll &i : b) cin >> i;
    vector<int> vis(31);
    for (int i = 0; i < q; i++) {
        auto u = b[i];
        if (vis[u]) continue;
        vis[u] = 1;
        ll pot = (1ll << u);
        for (int j = 0; j < n; j++) {
            if (a[j] % pot) continue;
            a[j] += pot / 2;
        }
    }
    for (auto u : a) cout << u << " ";
    cout << endl;
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
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
