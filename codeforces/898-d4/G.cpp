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
    string s; cin >> s;
    int n = size(s);
    vector<int> pb;
    pb.eb(0);
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') pb.eb(i);
        pref[i + 1] = pref[i] + (s[i] == 'A');
    }
    pb.eb(n - 1);
    auto query = [&] (int l, int r) {
        return pref[r + 1] - pref[l];
    };
    bool pl = 1;
    int res = 0;
    int N = size(pb) - 2;
    vector<int> L(N), R(N);
    for (int i = 1; i < (int)pb.size() - 1; i++) {
        L[i - 1] = query(pb[i - 1], pb[i]);
        R[i - 1] = query(pb[i], pb[i + 1]);
    }
    debug(L);
    debug(R);
    vector<vector<int>> dp(N + 1, vector<int> (2, 2e9));
    dp[0][0] = dp[0][1] = 0;
    for (int i = 0; i < N; i++) {
        dp[i + 1][0] = dp[i][0] + L[i];
        dp[i + 1][1] = max(dp[i][0], dp[i][1]) + R[i];
    }
    cout << max(dp[N][0], dp[N][1]) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
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
