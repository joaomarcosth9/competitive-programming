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
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

namespace sieve {
    const int MAX = 2e7;
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
    int l, r;
    cin >> l >> r;
    auto f = sieve::factorize(l);
    debug(l, f);
    for (auto u : f) {
        if (l - u > 0) {
            cout << u << " " << l - u << endl;
            return;
        }
    }
    int fst = l - (l % 2);
    if (fst > 0 && fst + 2 <= r) {
        cout << 2 << " " << fst << endl;
        return;
    }
    if (fst > 2 && (fst - 2) + 2 >= l && (fst - 2) + 2 <= r) {
        cout << 2 << " " << fst - 2 << endl;
        return;
    }
    if ((fst + 2) + 2 >= l && (fst + 2) + 2 <= r) {
        cout << 2 << " " << fst + 2 << endl;
        return;
    }
    cout << -1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    sieve::build();
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
