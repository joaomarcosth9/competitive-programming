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

int dsum(ll x) {
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

void solve() {
    ll n; cin >> n;
    string s = to_string(n);
    int N = size(s);
    reverse(all(s));
    int p10 = 1;
    ll res = 1;
    for (int p = 0; p < N; p++) {
        int d = s[p] - '0';

        ll pos = 0;
        for (int i = 0; i <= d; i++) {
            for (int j = 0; j <= d; j++) {
                for (int k = 0; k <= d; k++) {
                    if (i + j + k > d) continue;
                    if (i + j + k == d) {
                        pos += 1;
                    }
                }
            }
        }
        res *= pos;

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
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
