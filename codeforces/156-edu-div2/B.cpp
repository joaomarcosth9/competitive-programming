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

const ld eps = 1e-9;

struct pt {
    ld x, y;
    pt() : x(0), y(0) {}
    pt(ld _x, ld _y) : x(_x), y(_y) {}

    pt operator*(const ld &b) { return pt(b * x, b * y); }
    pt operator-(const pt &b) { return pt(x - b.x, y - b.y); }
    pt operator+(const pt &b) { return pt(x + b.x, y + b.y); }
    ld operator*(const pt &b) { return x * b.x + y * b.y; }
    ld operator^(const pt &b) { return x * b.y - y * b.x; }

    bool operator<(const pt &p) const {
        if (abs(x - p.x) <= eps) return y < p.y;
        return x < p.x;
    }
    ld dist(const pt &p) {
        ld dx = x - p.x;
        ld dy = y - p.y;
        return sqrt(dx * dx + dy * dy);
    }

    friend ostream &operator<<(ostream &out, const pt &a) { return out << "(" << a.x << "," << a.y << ")"; }
    friend istream &operator>>(istream &in, pt &a) {
        ll u, v;
        in >> u >> v;
        a.x = u; a.y = v;
        return in;
    }
};

void solve() {
    pt a, b, c; cin >> a >> b >> c;
    pt home(0, 0);
    ld l = 0.1, r = 1e4;
    int it = 0, MAX = 1e3;
    ld ans = -1;
    while (it++ < MAX && l <= r) {
        ld mid = (l + r) / 2;
        bool db = 0;
        if (b.dist(home) <= mid && b.dist(a) <= mid) db = 1;
        if (c.dist(home) <= mid && c.dist(a) <= mid) db = 1;
        if (b.dist(home) <= mid && c.dist(a) <= mid && (b.dist(c)) <= 2 * mid) db = 1;
        if (c.dist(home) <= mid && b.dist(a) <= mid && (b.dist(c)) <= 2 * mid) db = 1;
        if (db) {
            r = mid - eps;
            ans = mid;
        } else l = mid + eps;
    }
    cout << setprecision(10) << fixed << ans << endl;
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
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}

