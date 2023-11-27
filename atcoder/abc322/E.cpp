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

const ll INF = 1e14;
const int maxn = 105;
ll c[maxn];
vector<ll> a[maxn];
map<vector<ll>, ll> dp;

vector<ll> sub(vector<ll> u, vector<ll> v) {
    for (int i = 0; i < (int)u.size(); i++) u[i] -= v[i];
    return u;
}

vector<ll> add(vector<ll> u, vector<ll> v) {
    for (int i = 0; i < (int)u.size(); i++) u[i] += v[i];
    return u;
}

bool all_greater(vector<ll> u, int p) {
    for (auto x : u) if (x < p) return false;
    return true;
}

void solve() {
    int n, k, p; cin >> n >> k >> p;

    for (int i = 1; i <= n; i++) {
        a[i].assign(k, 0);
        cin >> c[i];
        for (int j = 0; j < k; j++) cin >> a[i][j];
    }

    dp[vector<ll>(k, 0)] = 0;

    ll res = INF;

    for (int i = 1; i <= n; i++) {
        auto now = a[i];
        auto new_dp = dp;
        for (auto [u, v] : dp) {
            auto nxt = add(u, now);
            for (auto &x : nxt) x = min(x, (ll)p);
            if (dp.count(nxt)) new_dp[nxt] = min(new_dp[nxt], v + c[i]);
            else new_dp[nxt] = v + c[i];
            if (all_greater(nxt, p)) res = min(res, new_dp[nxt]);
        }
        dp = new_dp;
    }

    cout << (res == INF ? -1 : res) << endl;

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
