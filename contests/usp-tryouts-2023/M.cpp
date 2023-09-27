#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define endl '\n'
#define cerr if (false) cerr
#endif
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
#define int ll
const ld EPS = 1e-9;

struct circle {
    ld r, x, y;
    circle() : r(0), x(0), y(0) { }
    circle(ld R, ld X, ld Y) : r(R), x(X), y(Y) { }
};

bool intersect(circle a, circle b) {
    ld dx = b.x - a.x;
    ld dy = b.y - a.y;
    ld d = sqrt(dx * dx + dy * dy);
    return d <= a.r + b.r;
}

array<pair<ld, ld>, 2> points(circle a, circle b) {
    assert(intersect(a, b));
    ld dx = b.x - a.x;
    ld dy = b.y - a.y;
    ld d = sqrt(dx * dx + dy * dy);
    ld theta = acos((a.r * a.r + d * d - b.r * b.r) / (2 * a.r * d));
    ld phi = atan2(dy, dx);
    return { { { a.x + a.r * cos(phi + theta), a.y + a.r * sin(phi + theta) },
             { a.x + a.r * cos(phi - theta), a.y + a.r * sin(phi - theta) } } };
    //
    //
    // COMPREENDER ISTO !!!!!!!!!!!!!
    //
    //
}

bool contains (circle a, pair<ld, ld> p) {
    ld dx = a.x - p.first;
    ld dy = a.y - p.second;
    return sqrt(dx * dx + dy * dy) <= a.r;
}

void solve() {
    vector<circle> c;

    ld tr; cin >> tr;
    c.eb(tr, 0, 0);
    for (int i = 0; i < 2; i++) {
        ld x, y; cin >> x >> y;
        c.eb(0, x, y);
        c.back().r = sqrt(x * x + y * y);
    }
    
    auto test = [&] (ld radius) {
        vector<circle> u = c;
        for (auto &circ : u) circ.r -= radius;
        for (auto &circ : u) if (circ.r < 0) circ.r = 0;

        for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) if (i != j) {
            if (!intersect(u[i], u[j])) return false;
        }

        bool db = 0;
        for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) if (i != j) {
            auto [p1, p2] = points(u[i], u[j]);
            for (int k = 0; k < 3; k++) if (k != i && k != j) {
                if (contains(u[k], p1) || contains(u[k], p2)) db = 1;
            }
        }

        return db;
    };

    ld L = 0, R = 1e9;
    int it = 0;
    ld ans = 0;
    while (it++ < 10000) {
        ld mid = (L + R) / 2;
        if (test(mid)) {
            ans = mid;
            L = mid;
        } else R = mid;
    }
    cout << setprecision(10) << fixed << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
    if (TC) { cin >> TC;
        int TEST = 1;
        while (TEST <= TC) {
            cerr << "[Testcase " << TEST << "]" << endl;
            solve();
            ++TEST;
        }
    } else solve();
}
