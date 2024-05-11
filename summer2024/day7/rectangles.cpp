#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int ll
using ll = long long;

struct pt {
    ll x, y;
    pt() : x(0), y(0) {}
    pt(ll _x, ll _y) : x(_x), y(_y) {}

    pt operator*(const ll &b) { return pt(b * x, b * y); }
    pt operator-(const pt &b) { return pt(x - b.x, y - b.y); }
    pt operator+(const pt &b) { return pt(x + b.x, y + b.y); }
    ll operator*(const pt &b) { return x * b.x + y * b.y; }
    ll operator^(const pt &b) { return x * b.y - y * b.x; }

    bool operator<(const pt &p) const {
        if (x == p.x) return y < p.y;
        return x < p.x;
    }
    ll dist2(const pt &p) {
        ll dx = x - p.x;
        ll dy = y - p.y;
        return dx * dx + dy * dy;
    }

    friend ostream &operator<<(ostream &out, const pt &a) { return out << "(" << a.x << "," << a.y << ")"; }
    friend istream &operator>>(istream &in, pt &a) { return in >> a.x >> a.y; }
};

ll area(pt a, pt b, pt c, pt d) {
    vector<pt> mx, mn;
    ll min_x = min({a.x, b.x, c.x, d.x});
    ll max_x = max({a.x, b.x, c.x, d.x});
    if (min_x == max_x) return 0;
    if (a.x == min_x) mn.push_back(a);
    if (b.x == min_x) mn.push_back(b);
    if (c.x == min_x) mn.push_back(c);
    if (d.x == min_x) mn.push_back(d);
    if (a.x == max_x) mx.push_back(a);
    if (b.x == max_x) mx.push_back(b);
    if (c.x == max_x) mx.push_back(c);
    if (d.x == max_x) mx.push_back(d);
    assert((int)size(mx) == 2);
    assert((int)size(mn) == 2);
    if (mn[0].y > mn[1].y) {
        swap(mn[0], mn[1]);
    }
    if (mx[0].y > mx[1].y) {
        swap(mx[0], mx[1]);
    }
    ll dx = max_x - min_x;
    ll dy = mn[0].y - mn[1].y;
    return abs(dx) * abs(dy);
}

bool inside(pt k, pt a, pt b, pt c, pt d) {
    bool db = 1;
    db &= k.x >= a.x;
    db &= k.x <= b.x;
    db &= k.y <= a.y;
    db &= k.y >= c.y;
    return db;
}

ll solve(pt a1, pt d1, pt a2, pt d2) {

    pt b1 = {d1.x, a1.y};
    pt c1 = {a1.x, d1.y};
    pt b2 = {d2.x, a2.y};
    pt c2 = {a2.x, d2.y};

    ll best = area(a1, b1, c1, d1);
    best = max(best, area(a2, b2, c2, d2));

    auto calc = [&] () {
        ll res = best;
        if (a1.x > b2.x) return res;
        if (b1.x < a2.x) return res;

        if (a1.y < c2.y) return res;
        if (c1.y > a2.y) return res;

        // four points inside

        if (a1.x >= a2.x && b1.x <= b2.x && a1.y <= a2.y && c1.y >= c2.y) {
            return res;
        }

        // two points inside

        if (inside(a1, a2, b2, c2, d2) && inside(b1, a2, b2, c2, d2)) {
            ll dx = d1.x - c1.x;
            ll dy = a2.y - d1.y;
            res = max(res, abs(dx) * abs(dy));
            return res;
        }
        if (inside(a1, a2, b2, c2, d2) && inside(c1, a2, b2, c2, d2)) {
            ll dx = d1.x - c2.x;
            ll dy = a1.y - d1.y;
            res = max(res, abs(dx) * abs(dy));
            return res;
        }
        if (inside(c1, a2, b2, c2, d2) && inside(d1, a2, b2, c2, d2)) {
            ll dx = d1.x - c1.x;
            ll dy = a1.y - d2.y;
            res = max(res, abs(dx) * abs(dy));
            return res;
        }
        if (inside(b1, a2, b2, c2, d2) && inside(d1, a2, b2, c2, d2)) {
            ll dx = d2.x - c1.x;
            ll dy = a1.y - d1.y;
            res = max(res, abs(dx) * abs(dy));
            return res;
        }

        // one point inside

        if (inside(a1, a2, b2, c2, d2)) {
            ll dx = a1.x - b2.x;
            ll dy = a2.y - d1.y;
            res = max(res, abs(dx) * abs(dy));
            dx = a2.x - b1.x;
            dy = a1.y - c2.y;
            res = max(res, abs(dx) * abs(dy));
            return res;
        }

        if (inside(b1, a2, b2, c2, d2)) {
            ll dx = a2.x - b1.x;
            ll dy = a2.y - d1.y;
            res = max(res, abs(dx) * abs(dy));
            dx = a1.x - b2.x;
            dy = a1.y - c2.y;
            res = max(res, abs(dx) * abs(dy));
            return res;
        }

        if (inside(c1, a2, b2, c2, d2)) {
            ll dx = a1.x - b2.x;
            ll dy = a1.y - d2.y;
            res = max(res, abs(dx) * abs(dy));
            dx = a2.x - b1.x;
            dy = a2.y - c1.y;
            res = max(res, abs(dx) * abs(dy));
            return res;
        }

        if (inside(d1, a2, b2, c2, d2)) {
            ll dx = b1.x - a2.x;
            ll dy = b1.y - d2.y;
            res = max(res, abs(dx) * abs(dy));
            dx = c1.x - b2.x;
            dy = c1.y - a2.y;
            res = max(res, abs(dx) * abs(dy));
            return res;
        }
        return res;
    };

    best = max(best, calc());
    swap(a1, a2);
    swap(b1, b2);
    swap(c1, c2);
    swap(d1, d2);
    best = max(best, calc());
    return best;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt; cin >> tt;
    while (tt--) {
        pt a, c, b, d; cin >> a >> b >> c >> d;
        pt top_left1 = {a.x, b.y};
        pt bottom_right1 = {b.x, a.y};
        pt top_left2 = {c.x, d.y};
        pt bottom_right2 = {d.x, c.y};
        cout << solve(top_left1, bottom_right1, top_left2, bottom_right2) << endl;
    }
}
