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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<pair<int, char>> res;
    int cb = 0;
    int i;
    for (i = n - 1; i >= 0; i--) {
        cb += s[i] == 'B';
        if (cb == k) break;
    }
    if (cb == k) {
        for (int j = i - 1; j >= 0; j--) if (s[j] == 'B') {
            res.eb(i, 'A');
            break;
        }
    } else if (cb < k) {
        for (int j = 0; j < n; j++) {
            if (s[j] == 'B') {
                cb--;
            }
            int add = j + 1;
            if (add + cb == k) {
                res.eb(j + 1, 'B');
                break;
            }
        }
    } else {
        for (int j = 0; j < n; j++) {
            if (s[j] == 'B') {
                cb--;
            }
            if (cb == k) {
                res.eb(j + 1, 'A');
                break;
            }
        }
    }
    cout << res.size() << endl;
    for (auto [id, c] : res) cout << id << " " << c << endl;
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
