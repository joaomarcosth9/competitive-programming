#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define cerr                                                                                                           \
    if (false) cerr
#endif
#define endl '\n'
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto &x) { return res; }
#define L2(res...) [&](const auto &x, const auto &y) { return res; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int ll
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> i3;
void out(bool ans) { cout << (ans ? "YES" : "NO") << endl; }

void solve() {
    int n;
    ll k;
    cin >> n;
    vector<ll> a(n + 1), c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    cin >> k;

    for (int i = n - 2; i >= 0; i--) c[i] = min(c[i], c[i + 1]);
    debug(c);

    ll curr = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            curr = k / c[i];
            k -= curr * c[i];
            cout << curr << endl;
        } else {
        }
    }
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
            /* cout << solve() << endl; */
            /* cout << (solve() ? "YES" : "NO") << endl; */
            ++TEST;
        }
    } else
        solve();
}
