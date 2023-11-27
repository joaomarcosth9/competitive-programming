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

const int MAX = 1e6 + 5;
int lp[MAX + 1], factor[MAX + 1];

namespace sieve {
    vector<int> pr;
    void build() {
        for (int i = 2; i <= MAX; i++) {
            if (lp[i] == 0) {
                lp[i] = i;
                pr.push_back(i);
            }
            for (int j = 0; i * pr[j] <= MAX; j++) {
                lp[i * pr[j]] = pr[j];
                factor[i * pr[j]] = i;
                if (pr[j] == lp[i]) break;
            }
        }
    }
    vector<int> factorize(int x) {
        if (x < 2) return {};
        vector<int> v;
        for (int lpx = lp[x]; x >= lpx; x = factor[x]) v.emplace_back(lp[x]);
        return v;
    }
}

vector<int> get_divs(ll n) {
    vector<int> facts = sieve::factorize(n);
    vector<pair<ll, int>> facts2;
    for (ll x : facts) {
        if (facts2.empty() || facts2.back().first != x) {
            facts2.emplace_back(x, 1);
        } else {
            facts2.back().second++;
        }
    }
    vector<int> divs;
    function<void(int, ll)> dfs = [&](int i, ll cur) {
        if (i == (int)facts2.size()) {
            divs.push_back(cur);
            return;
        }
        ll p = 1;
        for (int j = 0; j <= facts2[i].second; j++) {
            dfs(i + 1, cur * p);
            p *= facts2[i].first;
        }
    };
    dfs(0, 1);
    return divs;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> vis(n + 1);
    for (int i = 0; i < n; i++) vis[a[i]] = 1;

#ifdef LOCAL_DEBUG
    sort(all(a));
    debug(a);
#endif

    vector<int> has(n + 1), freq(n + 1);

    for (int i = 0; i < n; i++) {
        auto u = get_divs(a[i]);
        for (auto x : u) freq[x]++;
        for (auto x : u) has[x] = 1;
    }

    ll res = 0;

    vector<ll> dp(n + 1);
    for (int i = n; i >= 1; i--) if (has[i]) {
        dp[i] = (ll)(freq[i]) * (freq[i] - 1) / 2;
        for (int j = 2 * i; j <= n; j += i) if (has[j]) dp[i] -= dp[j];
    }

    debug(dp);

    for (int i = 1; i <= n; i++) if (vis[i]) {
        for (int j = 2 * i; j <= n; j += i) {
            dp[i] += dp[j];
            dp[j] = 0;
        }
    }

    debug(dp);

    for (int i = 1; i <= n; i++) if (vis[i]) res += dp[i];

    cout << (ll)(n) * (n - 1) / 2 - res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    sieve::build();
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
