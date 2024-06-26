#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

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
    friend m operator*(m a, m b) { return (T)((ll)a.v * b.v % MOD); }
    friend m operator/(m a, m b) { return a * b.pwr(b, MOD - 2); }
    friend m operator^(m a, ll e) { return a.pwr(a, e); }
};

const int MOD1 = 998244353;
const int MOD2 = (int)(1e9) + 7;
const int MOD3 = (int)(1e9) + 9;
using mint1 = Mint<MOD1>;
using mint2 = Mint<MOD2>;
using mint3 = Mint<MOD3>;

struct Hash {
    mint1 h1;
    mint2 h2;
    mint3 h3;
    Hash(mint1 _h1 = 0, mint2 _h2 = 0, mint3 _h3 = 0) : h1(_h1), h2(_h2), h3(_h3) { }
    bool operator==(Hash o) const { return h1 == o.h1 && h2 == o.h2 && h3 == o.h3; }
    bool operator!=(Hash o) const { return h1 != o.h1 || h2 != o.h2 || h3 != o.h3; }
    bool operator<(Hash o) const { return h1 == o.h1 ? (h2 == o.h2 ? h3 < o.h3 : h2 < o.h2) : h1 < o.h1; }
    Hash operator+(Hash o) const { return {h1 + o.h1, h2 + o.h2, h3 + o.h3}; }
    Hash operator-(Hash o) const { return {h1 - o.h1, h2 - o.h2, h3 - o.h3}; }
    Hash operator*(Hash o) const { return {h1 * o.h1, h2 * o.h2, h3 * o.h3}; }
    Hash operator/(Hash o) const { return {h1 / o.h1, h2 / o.h2, h3 / o.h3}; }
    friend ostream& operator<<(ostream &os, Hash a) {
        return os << a.h1.v;
    }
};

const int PRIME = (int)1e6 + (rng() % ((int)1e6));
const int MAXN = 5e5 + 5;
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
    Hash operator()(int l, int r) const {
        return (hsh[r + 1] - hsh[l]) * invpot[l];
    }
};

const int N = 5e5 + 5;

int n, m;
string s, text;
int a[N], it;
Hash texth[N];

void solve() {
    cin >> n >> m >> s;

    for (int i = 0; i < m; i++) {
        string a; cin >> a;
        text += a + "#";
    }

    s += s;

    int l = 1, r = n;

    m = (int)text.size();

    Hashing ht(text), hs(s);

    int ans = 0;

    while (l <= r) {
        int mid = midpoint(l, r);

        it = 0;

        for (int i = 0; i + mid - 1 < m; i++) {
            texth[it++] = ht(i, i + mid - 1);
        }

        sort(texth, texth + it);

        memset(a, 0, (2 * n + 2) * sizeof *a);

        for (int i = 0; i < n; i++) {
            Hash now = hs(i, i + mid - 1);
            int j = i + mid - 1;
            if (binary_search(texth, texth + it, now)) {
                if (j < n) {
                    a[0]++;
                    a[i + 1]--;
                    a[j + 1]++;
                } else {
                    a[(j + 1) % n]++;
                    a[i + 1]--;
                }
            }
        }

        int db = 0;

        for (int i = 1; i < 2 * n; i++) {
            a[i] += a[i - 1];
        }

        for (int i = 0; i < n; i++) {
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

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    precalc();
    solve();
}
