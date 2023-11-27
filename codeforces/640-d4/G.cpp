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
    if (n <= 3) {
        cout << -1 << endl;
        return;
    }
    vector<int> res;
    if (n & 1) {
        int num = 1;
        while (num <= n) res.eb(num), num += 2;
        res.eb(n - 3);
        res.eb(n - 1);
        if (n > 5) res.eb(n - 5);
        for (int i = n - 7; i > 1; i -= 2) res.eb(i);
    } else {
        int num = 2;
        while (num <= n) res.eb(num), num += 2;
        res.eb(n - 3);
        res.eb(n - 1);
        if (n > 5) res.eb(n - 5);
        for (int i = n - 7; i > 0; i -= 2) res.eb(i);
    }
    for (auto u : res) cout << u << " ";
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
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
