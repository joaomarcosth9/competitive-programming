#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void _pr() { cout << "]\n"; }
template <typename T, typename... V> void _pr(T x, V... v) {
    cout << x;
    if (sizeof...(v)) cout << ", ";
    _pr(v...);
}
#define debug(x...)                                                                                                    \
    cout << "[" << #x << "] = [";                                                                                      \
    _pr(x)

typedef long long ll;
const double EPS = 1e-9;

struct point { // point or vector
    double x, y;
    point(double x = 0, double y = 0) : x(x), y(y) {}
    point(point &start, point &end) { *this = end - start; } // vector

    point operator+(point &p) { return point(x + p.x, y + p.y); }
    point operator-(point &p) { return point(x - p.x, y - p.y); }
    point operator*(double u) { return point(x * u, y * u); }
    /* bool operator == (point& p) { return x == p.x && y == p.y; } */
    double operator*(point &p) { return x * p.x + y * p.y; } // dot product
    double operator^(point &p) { return x * p.y - y * p.x; } // cross product
    // cross (u, v) < 0 -> v is on the right of u

    double dis_2(point &oth) {
        double dx = (x - oth.x), dy = (y - oth.y);
        return dx * dx + dy * dy;
    }

    friend ostream &operator<<(ostream &out, point &p) { return out << "(" << p.x << "," << p.y << ")"; }
    friend istream &operator>>(istream &in, point &p) { return in >> p.x >> p.y; }
};

double area_2(point &a, point &b, point &c) {
    auto u = a - b;
    auto v = c - a;
    return abs(u ^ v);
}

bool inside(point &a, vector<point> &pol) {
    if (pol.size() == 1) {
        auto u = pol[0];
        return abs(u.x - a.x) <= EPS && abs(u.y - a.y) <= EPS;
    } else if (pol.size() == 2) {
        auto u = pol[0];
        auto v = pol[1];
        auto vu = a - u;
        auto vv = a - v;
        return abs(vv ^ vu) <= EPS;
    }
    /* debug(a); */
    /* for(int i = 0; i < (int)pol.size(); i++){ */
    /*     debug(pol[i]); */
    /* } */
    point base = pol[0];
    point u(base, a);

    point test1(base, pol[1]);
    point test2(base, pol.back());

    /* debug(test1); */
    /* debug(test1 ^ u); */
    /* debug(test2); */
    /* debug(test2 ^ u); */

    if ((test1 ^ u) > EPS) return 0;
    if ((test2 ^ u) < -EPS) return 0;

    int n = pol.size();
    int l = 1, r = n - 2;

    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        point &b = pol[mid];
        point v(base, b);
        double cvu = v ^ u;
        if (cvu <= EPS) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if (ans == -1) {
        assert(false);
    }
    point b = pol[ans];
    point c = pol[ans + 1];
    return abs((area_2(base, a, c) + area_2(base, a, b) + area_2(a, b, c)) - area_2(base, b, c)) <= EPS;
}

vector<point> convex_hull(vector<point> v) {
    point base = v[0];
    for (auto &u : v) {
        auto [x, y] = u;
        if (x + EPS < base.x) {
            swap(v[0], u);
            base = v[0];
        } else if (abs(x - base.x) <= EPS && y + EPS < base.y) {
            swap(v[0], u);
            base = v[0];
        }
    }
    auto orientation = [&](point &a, point &b) {
        point u(base, b);
        point v(base, a);
        double c = u ^ v;
        // c > 0 || c == 0 && bomba
        return c > EPS || (abs(c) <= EPS && (base.dis_2(a) + EPS < base.dis_2(b)));
    };

    sort(begin(v), end(v), orientation);

    if (v.size() <= 3) {
        return v;
    }

    vector<point> ch{v[0], v[1]};
    for (int i = 2; i < (int)v.size(); i++) {
        // check if it is not convex anymore
        int last = ch.size() - 1;
        point curr(ch[last - 1], ch[last]);
        point test(ch[last - 1], v[i]);
        double c = curr ^ test;
        while (c >= -EPS && ch.size() > 1) {
            ch.pop_back();
            if (ch.size() > 2) {
                last = ch.size() - 1;
                curr = point(ch[last - 1], ch[last]);
                test = point(ch[last - 1], v[i]);
                c = curr ^ test;
            } else
                break;
        }
        ch.emplace_back(v[i]);
    }
    if (ch.size() >= 3) {
        auto u = ch[ch.size() - 1];
        auto v = ch[ch.size() - 2];
        point curr(v, u);
        point test(u, base);
        double c = curr ^ test;
        if (c >= -EPS) {
            ch.pop_back();
        }
    }
    return ch;
}

void solve() {
    int n;
    cin >> n;
    vector<point> L(n);
    for (int i = 0; i < n; i++) {
        cin >> L[i];
    }

    int m;
    cin >> m;
    vector<point> S(m);
    for (int i = 0; i < m; i++) {
        cin >> S[i];
    }

    auto ch = convex_hull(L);

    for (auto u : S) {
        bool is = inside(u, ch);
        cout << (is ? "Yes" : "No") << '\n';
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        while (TC--) {
            solve();
        }
    } else
        solve();
    return 0;
}
