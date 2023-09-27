#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define endl '\n'
#define cerr                                                                                                           \
    if (false) cerr
#endif
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

void solve() {
    int n;
    cin >> n;
    const int maxt = 1e6;
    vector<int> a(maxt, 0);
    for (int i = 0; i < n; i++) {
        int u, b;
        cin >> u >> b;
        a[u] = b + 1;
    }

    int cdir = -1;
    int time = 0;
    int wt = 0;
    int res = 0;

    for (int i = 1; i < maxt; i++) {
        if (time) {
            time -= 1;
            if (time == 0) res = max(res, i);
        }
        if (time == 0) {
            if (wt) {
                cdir = wt;
                wt = 0;
                time = 10;
            } else
                cdir = -1;
        }
        if (a[i]) {
            if (cdir == -1) {
                cdir = a[i];
                time = 10;
            } else if (cdir == a[i]) {
                time = 10;
            } else {
                wt = a[i];
            }
        }
    }
    cout << res << endl;
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
            ++TEST;
        }
    } else
        solve();
}
