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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    int res = INT_MAX;
    if (k != 4) for (int i = 0; i < n; i++) {
        res = min(res, (k - (a[i] % k)) % k);
    } else {
        int t = 0, q = 0, qq = 0;
        for (int i = 0; i < n; i++) {
            if ((a[i] % 2) == 0) t++;
            if ((a[i] % 4) == 3) q++;
            if ((a[i] % 4) == 0) qq++;
        }
        if (qq) res = 0;
        else res = min(max(0, 2 - t), (q ? 1 : 10));
    }
    cout << res << endl;
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
