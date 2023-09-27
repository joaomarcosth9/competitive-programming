#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define cerr                                                                                                           \
    if (false) cerr
#endif
#define endl '\n'
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto &x) { return res; }
#define L2(res...) [&](const auto &x, const auto &y) { return res; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;
void out(bool ans) { cout << (ans ? "YES" : "NO") << endl; }

void solve() {
    int n = 9;
    vector<int> v(n);
    for (int &i : v) cin >> i;

    vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int &i : a) i--;
    debug(v);
    debug(a);

    ld total = 0;
    ld dr = 0;

    do {
        bool drr = 0;
        vector<vector<int>> lin(3), col(3), diag(3);
        for (int i = 0; i < 9; i++) {
            int l = a[i] / 3;
            int c = a[i] % 3;
            bool diag1 = (a[i] == 0 || a[i] == 4 || a[i] == 8);
            bool diag2 = (a[i] == 2 || a[i] == 4 || a[i] == 6);
            lin[l].eb(v[a[i]]);
            if (lin[l].size() == 3) {
                if (lin[l][0] == lin[l][1] && lin[l][0] != lin[l][2]) drr = 1;
            }
            col[c].eb(v[a[i]]);
            if (col[c].size() == 3) {
                if (col[c][0] == col[c][1] && col[c][0] != col[c][2]) drr = 1;
            }
            if (diag1) {
                diag[1].eb(v[a[i]]);
                if (diag[1].size() == 3)
                    if (diag[1][0] == diag[1][1] && diag[1][0] != diag[1][2]) drr = 1;
            }
            if (diag2) {
                diag[2].eb(v[a[i]]);
                if (diag[2].size() == 3)
                    if (diag[2][0] == diag[2][1] && diag[2][0] != diag[2][2]) drr = 1;
            }
        }
        dr += drr;
        total += 1;
    } while (next_permutation(begin(a), end(a)));

    debug(dr);
    debug(total);
    cout << setprecision(20) << fixed << (1.0 - dr / total) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    if (TC) {
        cin >> TC;
        int TEST = 1;
        while (TEST <= TC) {
            cerr << "[Testcase " << TEST << "]" << endl;
            solve();
            /* cout << solve() << endl; */
            /* cout << (solve() ? "YES" : "NO") << endl; */
            ++TEST;
        }
    } else
        solve();
}
