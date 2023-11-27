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
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    int mx = 10;
    for (int i = 0; i < mx; i++) {
        for (int j = 0; j < (int)s.size(); j++) {
            int cnt = 0;
            for (int k = 0; (j + k) < (int)s.size() && k < (int)t.size(); k++) {
                if (s[j + k] == t[k]) {
                    cnt++;
                }
            }
            if (cnt == (int)t.size()) {
                cout << i << endl;
                return;
            }
        }
        s += s;
    }
    cout << -1 << endl;
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
