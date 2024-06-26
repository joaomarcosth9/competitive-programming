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
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto &x) { return res; }
#define L2(res...) [&](const auto &x, const auto &y) { return res; }
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

template <auto MOD, typename T = decltype(MOD)>
struct Mint {
    using m = Mint<MOD, T>;
    T v;
    Mint(T val = 0) : v(val) { }
    bool operator==(m o) const { return v == o.v; }
    bool operator!=(m o) const { return v != o.v; }
    bool operator<(m o) const { return v < o.v; }
    m pwr(m b, ll e) {
        m res = 1;
        while (e > 0) {
            if (e & 1) res = res * b;
            b = b * b, e >>= 1;
        }
        return res;
    }
    friend m operator-(m a, m b) { return (a.v -= b.v) < 0 ? a.v + MOD : a.v; }
    friend m operator+(m a, m b) { return a - (MOD - b.v); }
    friend m operator*(m a, m b) { return (T)((__int128)a.v * b.v % MOD); }
    // se quiser otimizar constante, ao inves de (__int128) use (ll) se o T for `int`
    friend m operator/(m a, m b) { return a * b.pwr(b, MOD - 2); }
    friend m operator^(m a, ll e) { return a.pwr(a, e); }
};

const int MOD1 = 998244353;
const int MOD2 = (int)(1e9) + 7;
using mint1 = Mint<MOD1>;
using mint2 = Mint<MOD2>;

struct Hash {
    mint1 h1;
    mint2 h2;
    Hash(mint1 _h1 = 0, mint2 _h2 = 0) : h1(_h1), h2(_h2) { }
    bool operator==(Hash o) const { return h1 == o.h1 && h2 == o.h2; }
    bool operator!=(Hash o) const { return h1 != o.h1 || h2 != o.h2; }
    bool operator<(Hash o) const { return h1 == o.h1 ? h2 < o.h2 : h1 < o.h1; }
    Hash operator+(Hash o) const { return {h1 + o.h1, h2 + o.h2}; }
    Hash operator-(Hash o) const { return {h1 - o.h1, h2 - o.h2}; }
    Hash operator*(Hash o) const { return {h1 * o.h1, h2 * o.h2}; }
    Hash operator/(Hash o) const { return {h1 / o.h1, h2 / o.h2}; }
    friend ostream& operator<<(ostream &os, Hash a) {
        return os << a.h1.v;
    }
};

const int PRIME = 33333331; // qualquer primo na ordem do alfabeto
const int MAXN = 1e6 + 5;
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
    Hashing(string s) : N((int)s.size()), hsh(N + 1) {
        for (int i = 0; i < N; i++) {
            int c = (int)(s[i] - '#' + 1);
            hsh[i + 1] = hsh[i] + (pot[i + 1] * Hash(c, c));
        }
    }
    Hash operator()(int l = 0, int r = -1) const {
        // se ja chamou o precalc() pode apagar essa linha de cima
        if (r == -1) r = N - 1;
        return (hsh[r + 1] - hsh[l]) * invpot[l];
    }
};

void solve() {
    int n, m; string s;
    cin >> n >> m >> s;

    string text;

    for (int i = 0; i < m; i++) {
        string a; cin >> a;
        text += a + "#";
    }

    s = s + s + s;

    int l = 1, r = n;

    m = (int)text.size();

    Hashing ht(text), hs(s);

    int ans = 0;

    debug(s);
    debug(text);

    while (l <= r) {
        int mid = midpoint(l, r);

        set<Hash> texth;
        debug(mid);

        for (int i = 0; i + mid - 1 < m; i++) {
            debug(i, ht(i, i + mid - 1));
            texth.insert(ht(i, i + mid - 1));
        }

        debug(texth);

        vector<int> a(3 * n + 1);

        for (int i = 0; i + mid - 1 < 3 * n; i++) {
            debug(i, hs(i, i + mid - 1));
            Hash now = hs(i, i + mid - 1);
            int j = i + mid - 1;
            if (texth.count(now)) {
                int min_index = max(0, j - n);
                int max_index = i;
                a[min_index]++;
                a[max_index + 1]--;
            }
        }

        debug(a);

        int db = 0;

        for (int i = 1; i < 3 * n; i++) {
            a[i] += a[i - 1];
        }

        debug(a);

        for (int i = 0; i + mid - 1 < 3 * n; i++) {
            if (a[i] == 0) {
                db = 1;
            }
        }

        if (db) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }

    }

    cout << ans - 1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    precalc();
    int TC = 0;
    if (TC) {
        cin >> TC;
        int TEST = 1;
        while (TEST <= TC) {
            cerr << "[Testcase " << TEST << "]" << endl;
            solve();
            ++TEST;
        }
    } else
        solve();
}

