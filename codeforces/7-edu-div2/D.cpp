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
    int n; cin >> n;
    vector<int> res(n * 2);
    int it = 1;
    for (int i = 0; i < n / 2; i++) {
        res[i] = res[n - 1 - i] = it;
        it += 2;
    }
    if (n & 1) res[n / 2] = n;
    it = 2;
    for (int i = 0; i < n / 2; i++) {
        res[n + i] = res[2 * n - 2 - i] = it;
        it += 2;
    }
    res[n * 2 - 1] = n;
    for (int i = 0; i < 2 * n; i++) cout << res[i] << " \n"[i == 2 * n - 1];
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
