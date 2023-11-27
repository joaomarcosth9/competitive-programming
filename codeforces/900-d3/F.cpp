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

namespace sieve {
    const int MAX = 2e6;
    int lp[MAX + 1], factor[MAX + 1];
    vector<int> pr;
    void build() {
        for (int i = 2; i <= MAX; ++i) {
            if (lp[i] == 0) {
                lp[i] = i;
                pr.push_back(i);
            }
            for (int j = 0; i * pr[j] <= MAX; ++j) {
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
} // namespace sieve

void solve() {
    ll n; cin >> n;
    ll on = n;
    auto u = sieve::factorize(n);
    map<int, int> f;
    for (auto x : u) f[x]++;

    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            ll x; cin >> x;
            auto v = sieve::factorize(x);
            for (auto i : v) f[i]++;

            ll d = 1;
            for (auto [_, freq] : f) {
                d *= (freq + 1);
            }

            bool dr = 0;
            
            for (auto [fac, freq] : f) {
                int f2 = freq;
                while (d > 1 && ((d % fac) == 0) && f2) {
                    d /= fac;
                    f2--;
                }
                if ((d % fac) == 0) {
                    dr = 1;
                    break;
                }
            }

            if (d > 1) dr = 1;

            cout << (dr ? "NO" : "YES") << endl;


        } else {
            f.clear();
            for (auto x : u) f[x]++;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    sieve::build();
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
