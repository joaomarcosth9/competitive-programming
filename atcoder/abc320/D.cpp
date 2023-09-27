#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define cerr                                                                                                           \
    if (false) cerr
#endif
#define endl '\n'
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
void out(bool ans) { cout << (ans ? "YES" : "NO") << endl; }

struct pt {
    ll x, y;
    pt() : x(0), y(0) {}
    pt(ll _x, ll _y) : x(_x), y(_y) {}

    pt operator*(const ll &b) { return pt(b * x, b * y); }
    pt operator-(const pt &b) { return pt(x - b.x, y - b.y); }
    pt operator+(const pt &b) { return pt(x + b.x, y + b.y); }
    ll operator*(const pt &b) { return x * b.x + y * b.y; }
    ll operator^(const pt &b) { return x * b.y - y * b.x; }

    bool operator<(const pt &p) {
        if (x == p.x) return y < p.y;
        return x < p.x;
    }
    ll dist2(const pt &p) {
        ll dx = x - p.x;
        ll dy = y - p.y;
        return dx * dx + dy * dy;
    }

    friend ostream &operator<<(ostream &out, const pt &a) { return out << a.x << " " << a.y; }
    friend istream &operator>>(istream &in, pt &a) { return in >> a.x >> a.y; }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pt> a(n, pt(-1e18, -1e18));
    a[0] = pt(0, 0);
    vector<vector<i3>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        ll dx, dy;
        cin >> dx >> dy;
        adj[u].eb(v, dx, dy);
        adj[v].eb(u, -dx, -dy);
    }

    vector<int> vis(n);
    queue<int> q;
    q.emplace(0);

    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        auto [x, y] = a[u];
        for (auto [v, dx, dy] : adj[u])
            if (!vis[v]) {
                a[v] = pt(x + dx, y + dy);
                q.emplace(v);
            }
    }

    for (int i = 0; i < n; i++) {
        if (a[i].x == (long long)-1e18)
            cout << "undecidable" << endl;
        else
            cout << a[i] << endl;
    }
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
            /* cout << solve() << endl; */
            /* cout << (solve() ? "YES" : "NO") << endl; */
            ++TEST;
        }
    } else
        solve();
}
