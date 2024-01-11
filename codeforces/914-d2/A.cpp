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
    int a, b; cin >> a >> b;
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    ii moves[] = {{a, b}, {-a, b}, {a, -b}, {-a, -b}, {b, a}, {-b, a}, {b, -a}, {-b, -a}};

    set<ii> res;

    pair<int, int> now = {x1, y1};

    for (auto [x, y] : moves) {
        int db = 0;
        auto bkp = now;

        now.first += x;
        now.second += y;

        debug(x, y, now);
        debug(x2, y2);

        if (abs(now.first - x2) == a && abs(now.second - y2) == b) db = 1;
        if (abs(now.first - x2) == b && abs(now.second - y2) == a) db = 1;

        if (db) res.emplace(now);

        now = bkp;
    }
    cout << size(res) << endl;
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
