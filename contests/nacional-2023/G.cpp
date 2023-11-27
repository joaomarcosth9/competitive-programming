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

// Geometria inteiro
//
// Tudo que temos de geometria pra pontos inteiros

// Ponto com coordenadas inteiras e alguns metodos

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

bool ccw(pt &p, pt &a, pt &b, bool collinear = 0) {
    pt p1 = a - p;
    pt p2 = b - p;
    return collinear ? (p2 ^ p1) <= 0 : (p2 ^ p1) < 0;
}

pt transformx(pt &p) {
    /* matriz = {
       {1, -1}
       {1, 1}
    } */
    return {p.x - p.y, p.x + p.y};
}

pt detransform(pt &p) {
    /* matriz = {
       {1, 1}
       {-1, 1}
    } */
    return {p.x + p.y, p.y - p.x};
}

void solve() {
    int n; cin >> n;
    vector<int> d(n);
    vector<pt> pts(n);
    for (int i = 0; i < n; i++) cin >> pts[i] >> d[i];
    vector<pair<pt, pt>> segx, segy;
    for (int i = 0; i < n; i++) {
        auto [x, y] = pts[i];
        segx.eb(pt(x + d[i], y), pt(x, y - d[i]));
        segy.eb(pt(x - d[i], y), pt(x, y + d[i]));
    }
    for (auto &[u, v] : segx) {
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
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
