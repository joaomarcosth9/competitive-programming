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
    string s; cin >> s;
    int n = size(s);

    priority_queue<pair<int, char>> uc, lc;
    set<pair<int, char>> res;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == 'b') {
            if (lc.size()) lc.pop();
        } else if (s[i] == 'B') {
            if (uc.size()) uc.pop();
        } else if (s[i] <= 'z' && s[i] >= 'a') {
            lc.emplace(i, s[i]);
        } else {
            uc.emplace(i, s[i]);
        }
    }
    while (lc.size()) {
        res.emplace(lc.top());
        lc.pop();
    }
    while (uc.size()) {
        res.emplace(uc.top());
        uc.pop();
    }
    for (auto x : res) cout << x.second;
    cout << endl;
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
