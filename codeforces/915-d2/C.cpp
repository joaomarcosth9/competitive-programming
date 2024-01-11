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
    string s; cin >> s;
    s = "$" + s;

    vector<vector<int>> next(n + 2, vector<int> (26));

    for (int i = 0; i < 26; i++) next[n + 1][i] = -1;

    debug(n);

    for (int i = n; i >= 0; i--) {
        next[i] = next[i + 1];
        if (i + 1 <= n) next[i][s[i + 1] - 'a'] = i + 1;
    }

    vector<pair<char, int>> t;

    for (int i = 0; i < n; ) {
        for (char j = 25; j >= 0; j--) {
            if (next[i][j] != -1) {
                t.eb(j + 'a', next[i][j]);
                i = next[i][j];
                break;
            }
        }
    }

    auto tt = t;

    for (int i = 0; i < (int)t.size(); i++) {
        tt[i].first = t[(int)t.size() - 1 - i].first;
    }

    t = tt;

    debug(t);

    int cnt = 0;
    char mx = 0;
    for (auto [c, i] : t) mx = max(mx, c);
    for (auto [c, i] : t) cnt += c == mx;

    for (auto [c, i] : t) s[i] = c;

    if (is_sorted(all(s))) {
        cout << size(t) - cnt << endl;
    } else {
        cout << -1 << endl;
    }
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
