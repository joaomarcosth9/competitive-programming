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
    int n = 3;
    int m; cin >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) for (auto &c : a[i]) c -= '0';

    int best = INT_MAX;
    for (int i = 0; i <= 9; i++) {
        bool find = 0;
        vector<vector<int>> res(n);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (a[j][k] == i) res[j].eb(k);
            }
        }

        if (res[0].size() && res[1].size() && res[2].size()) find = 1;

        if (!find) continue;

        for (int j = 0; j < n; j++) {
            while (res[j].size() < 3) {
                auto u = res[j];
                for (auto x : u) res[j].eb(x + m);
            }
            debug(res[j]);
        }
        int Res = INT_MAX;
        for (int j = 0; j < (int)res[0].size(); j++) {
            for (int k = 0; k < (int)res[1].size(); k++) {
                if (res[0][j] == res[1][k]) continue;
                for (int l = 0; l < (int)res[2].size(); l++) {
                    if (res[0][j] == res[2][l]) continue;
                    if (res[1][k] == res[2][l]) continue;

                    int mx = max({res[0][j], res[1][k], res[2][l]});
                    Res = min(Res, mx);

                }
            }
        }
        best = min(best, Res);
    }
    cout << (best == INT_MAX ? -1 : best) << endl;
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
