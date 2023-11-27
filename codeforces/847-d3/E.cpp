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

bool b(int bit, int num) { return (num & (1 << bit)); }

void solve() {
    ll x; cin >> x;
    ll sum = x << 1;

    bool dr = x & 1;
    for (int i = 1; i < 32; i++) if (b(i, sum) && b(i - 1, sum)) dr = 1;

    if (dr) {
        cout << -1 << endl;
        return;
    }

    ll lsb = (sum & -sum);

    int ans1 = 0;
    int ans2 = 0;

    for (int i = 0; i < 32; i++) {
        if (b(i, x)) {
            ans1 |= (1 << (i - 1));
            ans2 |= (1 << (i - 1));
            ans1 |= (1 << i);
        }
    }

    assert((ans1 ^ ans2) * 2 == (ans1 + ans2));

    cout << ans1 << " " << ans2 << endl;
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
