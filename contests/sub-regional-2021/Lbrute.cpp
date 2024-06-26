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
    DSU(int n = 0) : par(n), sz(n, 1), number_of_sets(n) {
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
    // se quiser otimizar constante, ao inves de (__int128) use (ll) se o T for `int`
    friend m operator/(m a, m b) { return a * b.pwr(b, MOD - 2); }
    friend m operator^(m a, ll e) { return a.pwr(a, e); }
};

const int MOD1 = 998244353;
const int MOD2 = (int)(1e9) + 7;
using mint1 = Mint<MOD1>;
using mint2 = Mint<MOD2>;

void solve() {
    int n, m; cin >> n >> m;
    string s;
    cin >> s;

    DSU d(n);

    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        l--, r--;
        int mid = (l + r + 1) / 2;
        for (int j = l, k = r; j < mid; j++, k--) {
            d.unite(j, k);
        }
    }

    map<int, char> know;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (know.count(d.find(i))) {
                if (know[d.find(i)] == '0') {
                    cout << 0 << endl;
                    return;
                } else {
                    know[d.find(i)] = '1';
                }
            } else {
                know[d.find(i)] = '1';
            }
        } else if (s[i] == '0') {
            if (know.count(d.find(i))) {
                if (know[d.find(i)] == '1') {
                    cout << 0 << endl;
                    return;
                } else {
                    know[d.find(i)] = '0';
                }
            } else {
                know[d.find(i)] = '0';
            }
        } else {
            if (know.count(d.find(i))) {
                continue;
            } else {
                know[d.find(i)] = -1;
            }
        }
    }

    int cnt = 0;
    for (auto [k, v] : know) {
        cnt += (v == -1);
    }

    mint2 p2 = mint2(2) ^ cnt;

    cout << p2.v << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}
