#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define endl '\n'
#define cerr if (false) cerr
#endif
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto& x){ return res; }
#define L2(res...) [&](const auto& x, const auto& y){ return res; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef __int128_t ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

void solve() {
    long long A;
    cin >> A;
    if (A == 1) {
        cout << 2 << endl;
        return;
    }
    ll a = A;
    ll l = 1, r = (ll) 1e12;
    ll ans = -1;
    ll delta = -1;
    while (l <= r) {
        ll mid = (l + r) / 2;
        ll choose = mid * (mid - 1) / 2;
        if (choose <= a) {
            ans = mid;
            delta = a - choose;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    assert(ans != (ll)-1);
    long long res = ans;
    cout << res + (long long) delta << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) { cin >> TC;
        int TEST = 1;
        while (TEST <= TC) {
            cerr << "[Testcase " << TEST << "]" << endl;
            solve();
            ++TEST;
        }
    } else solve();
}
