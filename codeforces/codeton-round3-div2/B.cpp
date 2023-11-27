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

ll solve() {
    int n; cin >> n;
    string s; cin >> s;
    for (int i = 0; i < n; i++) s[i] -= '0';
    ll cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        cnt1 += !s[i];
        cnt2 += s[i];
    }
    vector<ll> mx(2);
    char curr = s[0];
    ll cnt = 1;
    for (int i = 1; i <= n; i++) {
        if (i < n && s[i] == curr) cnt++;
        else {
            mx[curr] = max(mx[curr], cnt);
            curr = s[i];
            cnt = 1;
        }
    }
    return max({mx[0] * mx[0], mx[1] * mx[1], cnt1 * cnt2});
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        /* solve(); */
        cout << solve() << endl;
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
