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

const ll maxn = 3e5 + 5, mod = 998244353;
ll fat[maxn];
int n;

void solve() {
    string s; cin >> s;
    n = size(s);
    ll r1 = 0, r2 = 1;
    int curr = s[0];
    int len = 1;
    s += "$";
    for (int i = 1; i <= n; i++) {
        if (s[i] == curr) len++;
        else {
            r1 += len - 1;
            r2 = r2 * len % mod;
            len = 1;
            curr = s[i];
        }
    }
    cout << r1 << " " << r2 * fat[r1] % mod << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    fat[0] = 1;
    for (int i = 1; i < maxn; i++) fat[i] = fat[i - 1] * i % mod;
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
