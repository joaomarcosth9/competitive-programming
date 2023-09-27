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
void out(bool ans) { cout << (ans ? "YES" : "NO") << endl; }

void solve() {
    int res = 0;
    string s; cin >> s;
    int n = size(s);
    for (int i = 0; i < n; i++) {
        int cres = 0;
        for (int j = 0; j <= n; j++) {
            if (i + j >= n || i - j < 0) break;
            if (s[i - j] != s[i + j]) break;
            cres += (j == 0 ? 1 : 2);
            res = max(res, cres);
        }
    }
    for (int i = 0; i < n; i++) {
        int cres = 0;
        for (int j = 0; j <= n; j++) {
            int k = j + 1;
            if (i + j >= n || i - k < 0) break;
            if (s[i + j] != s[i - k]) break;
            cres += 2;
            res = max(res, cres);
        }
    }
    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
    if (TC) { cin >> TC;
        int TEST = 1;
        while (TEST <= TC) {
            cerr << "[Testcase " << TEST << "]" << endl;
            solve();
            /* cout << solve() << endl; */
            /* cout << (solve() ? "YES" : "NO") << endl; */
            ++TEST;
        }
    } else solve();
}
