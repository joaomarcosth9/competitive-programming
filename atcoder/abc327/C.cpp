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

bool solve() {
    vector<int> base {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 9;
    vector mat(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> mat[i][j];
    }
    for (int i = 0; i < n; i++) {
        auto now = mat[i];
        sort(all(now));
        if (now != base) return 0;
    }
    for (int i = 0; i < n; i++) {
        vector<int> now;
        for (int j = 0; j < n; j++) now.eb(mat[j][i]);
        sort(all(now));
        if (now != base) return 0;
    }
    vector blocks(n, vector (n, vector<int> ()));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            blocks[i / 3][j / 3].eb(mat[i][j]);
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sort(all(blocks[i][j]));
            if (blocks[i][j] != base) return 0;
        }
    }
    return 1;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        /* solve(); */
        /* cout << solve() << endl; */
        cout << (solve() ? "Yes" : "No") << endl;
        TEST += 1;
    }
}
