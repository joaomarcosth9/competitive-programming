#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

struct DSU {
    vector<int> par, sz;
    int number_of_sets;
    DSU() {}
    DSU(int n) : par(n), sz(n, 1), number_of_sets(n) {
        iota(par.begin(), par.end(), 0);
    }
    int find(int a) { return a == par[a] ? a : par[a] = find(par[a]); }
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) {
            return false;
        }
        number_of_sets--;
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        par[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

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
    friend m operator/(m a, m b) { return a * b.pwr(b, MOD - 2); }
    friend m operator^(m a, ll e) { return a.pwr(a, e); }
};

const int MOD = (int)(1e9) + 7;
using mint = Mint<MOD>;

void solve() {
    int n, m; cin >> n >> m;
    string s;
    cin >> s;

    string rs(s.rbegin(), s.rend());

    s += rs;

    int LG = 31 - __builtin_clz(n);

    auto rev = [&] (int i) {
        return 2 * n - 1 - i;
    };

    vector<DSU> d(LG + 1);

    auto unite = [&] (int l1, int r1, int l2, int r2) {
        if (l1 > r1) {
            swap(l1, r1);
        }
        if (l2 > r2) {
            swap(l2, r2);
        }
        int level = 31 - __builtin_clz(r1 - l1 + 1);
        d[level].unite(l1, l2);
    };

    for (int i = 0; i <= LG; i++) {
        d[i] = DSU(2 * n);
    }
    for (int i = 0; i < n; i++) {
        d[0].unite(i, 2 * n - 1 - i);
    }

    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        l--, r--;
        int level = 31 - __builtin_clz(r - l + 1);
        int l1 = l, r1 = l + (1 << level) - 1;
        int l2 = r - (1 << level) + 1, r2 = r;

        unite(l1, r1, rev(l2), rev(r2));

        if (r1 != r2) {
            unite(l2, r2, rev(l1), rev(r1));
        }
    }

    for (int level = LG; level > 0; level--) {
        for (int j = 0; j < 2 * n; j++) {
            int p = d[level].find(j);
            int p1 = p, p2 = p + (1 << (level - 1));
            int j1 = j, j2 = j + (1 << (level - 1));
            if (p2 >= 2 * n || j2 >= 2 * n) {
                continue;
            }
            d[level - 1].unite(p1, j1);
            d[level - 1].unite(p2, j2);
        }
    }

    map<int, int> know;

    for (int i = 0; i < 2 * n; i++) {
        int p = d[0].find(i);
        debug(p, know, s[i], know.count(p));
        if (know.count(p)) {
            if (s[i] == '1' && know[p] == 0) {
                cout << 0 << endl;
                return;
            }
            if (s[i] == '0' && know[p] == 1) {
                cout << 0 << endl;
                return;
            }
            if (s[i] == '1') {
                know[p] = 1;
            } else if (s[i] == '0') {
                know[p] = 0;
            }
        } else {
            if (s[i] == '1') {
                know[p] = 1;
            } else if (s[i] == '0') {
                know[p] = 0;
            } else {
                know[p] = -1;
            }
        }
    }

    debug(know);

    int cnt = 0;

    for (auto [k, v] : know) {
        cnt += (v == -1);
    }

    mint p2 = mint(2) ^ cnt;

    cout << p2.v << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}
