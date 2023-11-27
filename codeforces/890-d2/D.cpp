#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif
/* #define endl '\n' */
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

int ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int ans; cin >> ans; return ans;
}

void guess(int x) {
    cout << "! " << x << endl;
}

i3 solve(int l, int r) {
    if (l == r) return {l, l, r};
    int mid = (l + r) / 2;
    auto [mxl, ll, rl] = solve(l, mid);
    auto [mxr, lr, rr] = solve(mid + 1, r);

    i3 ret = {-1, l, r};
    int &mx = get<0>(ret);

    debug(l, r, mxl, mxr, ll, rl, lr, rr);

    if (mxl == rl && mxr == lr) {
        mx = ask(mxl, mxr) == 1 ? mxl : mxr;
    } else {
        int num1 = ask(mxl, mxr - 1);
        int num2 = ask(mxl, mxr);
        mx = (num2 > num1 ? mxl : mxr);
    }

    return ret;
}

void solve() {
    int n; cin >> n;
    auto [mx, l, r] = solve(1, n);
    guess(mx);
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
