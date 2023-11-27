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
typedef tuple<ll, ll, ll> i3;
typedef tuple<ll, ll, ll, ll> i4;
typedef tuple<ll, ll, ll, ll, ll> i5;

i5 fix_x(ll x, ll y, ll xa, ll ya, ll dx) {
    if (dx == 0) return {x, y, xa, ya, 0};
    ll mh = 0;
    ll xt = 0, yt = 0;
    if (dx < 0) {
        xt = xa + 1, yt = ya;
        if (y == ya && x < xa) mh++, y--;
    } else {
        xt = xa - 1, yt = ya;
        if (y == ya && x > xa) mh++, y--;
    }
    mh += abs(x - xt) + abs(y - yt);
    mh += abs(dx);
    return {xt + dx, yt, xa + dx, ya, mh};
}

i5 fix_y(ll x, ll y, ll xa, ll ya, ll dy) {
    if (dy == 0) return {x, y, xa, ya, 0};
    ll mh = 0;
    ll xt = 0, yt = 0;
    if (dy < 0) {
        xt = xa, yt = ya + 1;
        if (x == xa && y < ya) mh++, x--;
    } else {
        xt = xa, yt = ya - 1;
        if (x == xa && y > ya) mh++, x--;
    }
    mh += abs(x - xt) + abs(y - yt);
    mh += abs(dy);
    return {xt, yt + dy, xa, ya + dy, mh};
}

ll solve() {
    ll x, y, xa, ya, xc, yc; cin >> x >> y >> xa >> ya >> xc >> yc;

    ll dx = xc - xa;
    ll dy = yc - ya;
    ll res = LLONG_MAX;;

    {
        ll res1 = 0;
        auto [nx, ny, nxa, nya, cost] = fix_x(x, y, xa, ya, dx);
        auto [_, __, ___, ____, cost2] = fix_y(nx, ny, nxa, nya, dy);
        debug(cost, cost2);
        res1 = cost + cost2;
        res = min(res, res1);
    }

    {
        ll res1 = 0;
        auto [nx, ny, nxa, nya, cost] = fix_y(x, y, xa, ya, dy);
        auto [_, __, ___, ____, cost2] = fix_x(nx, ny, nxa, nya, dx);
        debug(cost, cost2);
        res1 = cost + cost2;
        res = min(res, res1);
    }

    return res;
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
        cout << solve() << endl;
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
