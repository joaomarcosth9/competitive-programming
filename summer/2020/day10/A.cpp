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

struct point { // point or vector
    ll x, y;
    point(ll x = 0, ll y = 0) : x(x), y(y) {}
    point(point &start, point &end) { *this = end - start; } // vector

    point operator+(point &p) { return point(x + p.x, y + p.y); }
    point operator-(point &p) { return point(x - p.x, y - p.y); }
    point operator*(ll u) { return point(x * u, y * u); }
    bool operator==(point &p) { return x == p.x && y == p.y; }
    ll operator*(point &p) { return x * p.x + y * p.y; } // dot product
    ll operator^(point &p) { return x * p.y - y * p.x; } // cross product
    // cross (u, v) < 0 -> v is on the right of u

    ll dis_2(point &oth) {
        ll dx = (x - oth.x), dy = (y - oth.y);
        return dx * dx + dy * dy;
    }

    friend ostream &operator<<(ostream &out, point &p) { return out << "(" << p.x << "," << p.y << ")"; }
    friend istream &operator>>(istream &in, point &p) { return in >> p.x >> p.y; }
};

ll area_2(point &a, point &b, point &c) {
    auto u = a - b;
    auto v = c - a;
    return abs(u ^ v);
}

bool inside(point &a, vector<point> &pol) {
    debug(a);
    for (int i = 0; i < (int)pol.size(); i++) {
        debug(pol[i]);
    }

    point base = pol[0];
    point u(base, a);

    point test1(base, pol[1]);
    point test2(base, pol.back());

    if ((test1 ^ u) > 0) return 0;
    if ((test2 ^ u) < 0) return 0;

    debug(test1);
    debug(test1 ^ u);
    debug(test2);
    debug(test2 ^ u);

    int n = pol.size();
    int l = 1, r = n - 2;

    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        point &b = pol[mid];
        point v(base, b);
        ll cvu = v ^ u;
        if (cvu <= 0) {
            ans = mid;
            l = mid + 1;
        } else if (cvu > 0) {
            r = mid - 1;
        }
    }
    if (ans == -1) assert(false);
    point b = pol[ans];
    point c = pol[ans + 1];
    return (area_2(base, a, c) + area_2(base, a, b) + area_2(a, b, c)) == area_2(base, b, c);
}

vector<point> convex_hull(vector<point> v) {
    point base = v[0];
    for (auto &u : v) {
        auto [x, y] = u;
        if (x < base.x) {
            swap(v[0], u);
            base = v[0];
        } else if (x == base.x && y < base.y) {
            swap(v[0], u);
            base = v[0];
        }
    }

    auto orientation = [&](point &a, point &b) {
        point u(base, b);
        point v(base, a);
        ll c = u ^ v;
        debug(a, b, u, v);
        debug(c);
        return (c > 0) || (c == 0 && (base.dis_2(a) < base.dis_2(b)));
    };

    sort(begin(v), end(v), orientation);

    vector<point> ch{v[0], v[1]};
    for (int i = 2; i < (int)v.size(); i++) {
        // check if it is not convex anymore
        int last = ch.size() - 1;
        point curr(ch[last - 1], ch[last]);
        point test(ch[last - 1], v[i]);
        ll c = curr ^ test;
        while (c >= 0 && ch.size() > 1) {
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

    for (auto u : ch) {
        debug(u);
    }

    for (int i = 0; i < (int)ch.size() - 2; i++) {
        auto a = ch[i], b = ch[i + 1], c = ch[i + 2];
        point u(a, b);
        point v(a, c);
        ll cp = u ^ v;
        // nao deveria ter colinear
        assert(cp != 0);
    }
    ll res = 0;

    for (auto u : S) {
        bool is = inside(u, ch);
        res += is;
    }
    cout << res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
