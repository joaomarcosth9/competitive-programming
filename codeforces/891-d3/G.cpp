#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define endl '\n'
#define cerr                                                                                                           \
    if (false) cerr
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;
const int maxn = 2e5 + 5, mod = 998244353;

template <typename T = int, T mod = 1'000'000'007, typename U = long long> struct umod {
    T val;
    umod() : val(0){};
    umod(U x) {
        x %= mod;
        if (x < 0) x += mod;
        val = x;
    }
    umod &operator+=(umod oth) {
        val += oth.val;
        if (val >= mod) val -= mod;
        return *this;
    }
    umod &operator-=(umod oth) {
        val -= oth.val;
        if (val < 0) val += mod;
        return *this;
    }
    umod &operator*=(umod oth) {
        val = ((U)val) * oth.val % mod;
        return *this;
    }
    umod &operator/=(umod oth) { return *this *= oth.inverse(); }
    umod &operator^=(U oth) { return *this = pwr(*this, oth); }
    umod operator+(umod oth) const { return umod(*this) += oth; }
    umod operator-(umod oth) const { return umod(*this) -= oth; }
    umod operator*(umod oth) const { return umod(*this) *= oth; }
    umod operator/(umod oth) const { return umod(*this) /= oth; }
    umod operator^(long long oth) const { return umod(*this) ^= oth; }
    bool operator<(umod oth) const { return val < oth.val; }
    bool operator>(umod oth) const { return val > oth.val; }
    bool operator<=(umod oth) const { return val <= oth.val; }
    bool operator>=(umod oth) const { return val >= oth.val; }
    bool operator==(umod oth) const { return val == oth.val; }
    bool operator!=(umod oth) const { return val != oth.val; }
    umod pwr(umod a, U b) const {
        umod r = 1;
        for (; b; a *= a, b >>= 1)
            if (b & 1) r *= a;
        return r;
    }
    umod inverse() const {
        U a = val, b = mod, u = 1, v = 0;
        while (b) {
            U t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        if (u < 0) u += mod;
        return u;
    }
};

using Mint = umod<int, 998244353>;
ostream &operator<<(ostream &os, Mint oth) {
    os << oth.val;
    return os;
}

struct Dsu {
    vector<int> p;
    vector<ll> sz;
    Dsu(int n) : p(n), sz(n, 1) {
        for (int i = 0; i < n; i++) p[i] = i;
    }
    int find(int a) { return a == p[a] ? a : p[a] = find(p[a]); }
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (sz[a] > sz[b]) swap(a, b);
        sz[b] += sz[a];
        p[a] = b;
        sz[a] = 0;
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges(n - 1);
    for (auto &[u, v, w] : edges) {
        cin >> u >> v >> w;
        u--;
        v--;
    }
    sort(begin(edges), end(edges), [&](auto &a, auto &b) { return a[2] < b[2]; });

    Dsu dsu(n);

    Mint res = 1;

    for (auto &[u, v, w] : edges) {
        u = dsu.find(u), v = dsu.find(v);
        assert(u != v);
        res *= Mint(m - w + 1) ^ (dsu.sz[u] * dsu.sz[v] - 1);
        assert(dsu.unite(u, v));
    }

    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    auto start = chrono::steady_clock::now();
    if (TC) {
        cin >> TC;
        start = chrono::steady_clock::now();
        int TEST = 0;
        while (TEST < TC) {
            cerr << "[Testcase " << TEST + 1 << "]" << endl;
            solve();
            ++TEST;
            cerr << endl;
        }
    } else
        solve();
#ifdef LOCAL_DEBUG
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "\nTime taken: ";
    cerr << chrono::duration<double, milli>(diff).count() << " ms" << endl;
#endif
}
