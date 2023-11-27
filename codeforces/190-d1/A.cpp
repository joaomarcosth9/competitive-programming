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
typedef pair<ll, ll> ii;
typedef tuple<int, int, int> i3;

void advance(ll &x, ll &y, char c) {
    if (c == 'U') y++;
    if (c == 'D') y--;
    if (c == 'R') x++;
    if (c == 'L') x--;
}

bool solve() {
    ll a, b; cin >> a >> b;
    ll x = 0, y = 0;
    string s; cin >> s;
    int n = size(s);
    vector<ii> points;
    points.eb(x, y);
    for (int i = 0; i < n; i++) { 
        advance(x, y, s[i]);
        points.eb(x, y);
    }
    auto [dx, dy] = points.back();
    bool db = 0;
    debug(dx, dy);
    for (int i = 0; i <= n; i++) {
        auto [nx, ny] = points[i];
        if (ii(nx, ny) == ii(a, b)) db = 1;
        auto aa = a, bb = b;
        a -= nx, b -= ny;
        debug(a, b, nx, ny);
        if (dx && dy) db |= ((a % dx == 0) && (b % dy == 0) && (a / dx == b / dy) && (a / dx >= 0));
        else if (dx) db |= ((a % dx == 0) && (b == 0) && (a / dx >= 0));
        else if (dy) db |= ((b % dy == 0) && (a == 0) && (b / dy >= 0));
        a = aa, b = bb;
    }
    return db;
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
