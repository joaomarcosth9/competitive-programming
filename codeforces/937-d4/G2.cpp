#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
#define int ll

template <int MOD> struct Mint {
    using m = Mint;
    int v;
    Mint() : v(0) { }
    Mint(__int128_t val) {
        val %= MOD;
        if (val < 0) val += MOD;
        v = (int)(val);
    }
    bool operator==(const m &o) const { return v == o.v; }
    bool operator!=(const m &o) const { return v != o.v; }
    bool operator<(const m &o) const { return v < o.v; }
    m pwr(m b, ll e) {
        m res;
        for (res = 1; e > 0; e >>= 1, b *= b) {
            if (e & 1) {
                res *= b;
            }
        }
        return res;
    }
    m &operator+=(const m &o) {
        v += o.v;
        if (v >= MOD) {
            v -= MOD;
        }
        return *this;
    }
    m &operator-=(const m &o) {
        v -= o.v;
        if (v < 0) {
            v += MOD;
        }
        return *this;
    }
    m &operator*=(const m &o) { return *this = int(((__int128_t)v * o.v) % MOD); }
    m &operator/=(const m &o) { return *this *= pwr(o, MOD - 2); }
    m &operator^=(ll e) {
        assert(e >= 0);
        return *this = pwr(*this, e);
    }
    friend m operator+(m a, const m &b) { return a += b; }
    friend m operator-(m a, const m &b) { return a -= b; }
    friend m operator*(m a, const m &b) { return a *= b; }
    friend m operator/(m a, const m &b) { return a /= b; }
    friend m operator^(m a, ll e) { return a ^= e; }
    friend ostream &operator<<(ostream &os, const m &a) { return os << a.v; }
    friend istream &operator>>(istream &is, m &a) {
        ll x;
        is >> x, a = m(x);
        return is;
    }
};

const int MOD1 = 1005599459ll * ll(1e9 + 7) + 3;
const int MOD2 = 1005599461ll * ll(1e9 + 9) + 3;
using mint1 = Mint<MOD1>;
using mint2 = Mint<MOD2>;

struct Hash {
    mint1 h1;
    mint2 h2;
    Hash() { }
    Hash(mint1 _h1, mint2 _h2) : h1(_h1), h2(_h2) { }
    bool operator==(Hash o) const { return h1 == o.h1 && h2 == o.h2; }
    bool operator!=(Hash o) const { return h1 != o.h1 || h2 != o.h2; }
    bool operator<(Hash o) const { return h1 == o.h1 ? h2 < o.h2 : h1 < o.h1; }
    Hash operator+(Hash o) const { return {h1 + o.h1, h2 + o.h2}; }
    Hash operator-(Hash o) const { return {h1 - o.h1, h2 - o.h2}; }
    Hash operator*(Hash o) const { return {h1 * o.h1, h2 * o.h2}; }
    Hash operator/(Hash o) const { return {h1 / o.h1, h2 / o.h2}; }
    friend ostream &operator<<(ostream &os, const Hash &h) { return os << '(' << h.h1 << ", " << h.h2 << ')'; }
};


mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

const int PRIME = uniform(1000000, 2000000);
const int MAXN = 4e5 + 5;
Hash PR = {PRIME, PRIME};
Hash invPR = {mint1(1) / PRIME, mint2(1) / PRIME};
Hash pot[MAXN], invpot[MAXN];
void precalc() {
    pot[0] = invpot[0] = Hash(1, 1);
    for (int i = 1; i < MAXN; i++) {
        pot[i] = pot[i - 1] * PR;
        invpot[i] = invpot[i - 1] * invPR;
    }
}

struct Hashing {
    int N;
    vector<Hash> hsh;
    Hashing() { }
    Hashing(string s) : N(int(s.size())), hsh(N + 1) {
        for (int i = 0; i < N; i++) {
            int c = int(s[i] - 'a' + 1);
            hsh[i + 1] = hsh[i] + (pot[i + 1] * Hash(c, c));
        }
    }
    Hash operator()(int l, int r) const {
        return (hsh[r + 1] - hsh[l]) * invpot[l];
    }
};

void solve() {
    static int t = 1;
    int n; cin >> n;
    vector<pair<string, string>> o(n);
    vector<pair<Hash, Hash>> a(n);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        string t; cin >> t;
        o[i] = {s, t};
        a[i].first = Hashing(s)(0, (int)s.size() - 1);
        a[i].second = Hashing(t)(0, (int)t.size() - 1);
    }

    auto can = [&] (int i, int j) {
        if (a[i].first == a[j].first) return 1;
        if (a[i].second == a[j].second) return 1;
        return 0;
    };

    vector dp(1 << n, vector (n, (int)2e9));

    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = 0;
    }

    for (int i = 1; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (!((i >> j) & 1)) continue;
            for (int k = 0; k < n; k++) {
                if ((i >> k) & 1) continue;
                if (can(k, j)) dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j]);
                dp[i | (1 << k)][j] = min(dp[i | (1 << k)][j], dp[i][j] + 1);
            }
        }
    }

    int res = 2e9;
    for (int i = 0; i < n; i++) {
        res = min(res, dp[(1 << n) - 1][i]);
    }

    cout << res << endl;

    t++;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    precalc();
    int TC; cin >> TC;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
