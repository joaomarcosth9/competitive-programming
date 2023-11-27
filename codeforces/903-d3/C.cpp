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

int solve() {
    int n; cin >> n;
    int res = 0;
    vector<string> a(n);
    for (string &i : a) cin >> i;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vector<char> now {a[i][j]};
            now.eb(a[n - j - 1][i]);
            now.eb(a[n - i - 1][n - j - 1]);
            now.eb(a[j][n - i - 1]);
            int need = *max_element(all(now));
            int numop = 0;
            for (char c : now) {
                numop += need - c;
            }
            res += numop;
        }
    }

    return res >> 2;
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
