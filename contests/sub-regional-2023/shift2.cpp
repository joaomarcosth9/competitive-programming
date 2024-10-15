#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

template <auto MOD, typename T = decltype(MOD), typename U = ll>
struct Mint {
    using m = Mint<MOD, T>;
    T v;
    Mint(T val = 0) : v(val) {
        if (v < 0) v += MOD;
    }
    bool operator==(m o) const { return v == o.v; }
    bool operator<(m o) const { return v < o.v; }
    bool operator!=(m o) const { return v != o.v; }
    m pwr(m b, U e) {
        m res = 1;
        while (e > 0) {
            if (e & 1) res *= b;
            b *= b, e /= 2;
        }
        return res;
    }
    m &operator+=(m o) {
        v -= MOD - o.v;
        if (v < 0) v += MOD;
        return *this;
    }
    m &operator-=(m o) {
        v -= o.v;
        if (v < 0) v += MOD;
        return *this;
    }
    m &operator*=(m o) {
        v = (T)((U)v * o.v % MOD);
        return *this;
    }
    m &operator/=(m o) { return *this *= o.pwr(o, MOD - 2); }
    m &operator^=(U e) { return *this = pwr(*this, e); }
    friend m operator-(m a, m b) { return a -= b; }
    friend m operator+(m a, m b) { return a += b; }
    friend m operator*(m a, m b) { return a *= b; }
    friend m operator/(m a, m b) { return a /= b; }
    friend m operator^(m a, U e) { return a.pwr(a, e); }
};

template <int MOD, typename T = Mint<MOD>>
void ntt(vector<T> &a, bool inv = 0) {
    int n = (int)a.size();
    auto b = a;
    T g = 1;
    while ((g ^ (MOD / 2)) == 1) g += 1;
    if (inv) g = T(1) / g;
    for (int step = n / 2; step; step /= 2) {
        T w = g ^ (MOD / (n / step)), wn = 1;
        for (int i = 0; i < n / 2; i += step) {
            for (int j = 0; j < step; j++) {
                auto u = a[2 * i + j], v = wn * a[2 * i + j + step];
                b[i + j] = u + v;
                b[i + n / 2 + j] = u - v;
            }
            wn = wn * w;
        }
        swap(a, b);
    }
    if (inv) {
        T invn = T(1) / n;
        for (int i = 0; i < n; i++) a[i] *= invn;
    }
}

template <int MOD>
vector<int> multiply(vector<int> &ta, vector<int> &tb) {
    using T = Mint<MOD>;
    int n = (int)ta.size(), m = (int)tb.size();
    int t = n + m - 1, sz = 1;
    while (sz < t) sz <<= 1;

    vector<T> a(sz), b(sz), c(sz);
    for (int i = 0; i < n; i++) a[i] = ta[i];
    for (int i = 0; i < m; i++) b[i] = tb[i];

    ntt<MOD>(a, 0), ntt<MOD>(b, 0);
    for (int i = 0; i < sz; i++) c[i] = a[i] * b[i];
    ntt<MOD>(c, 1);

    vector<int> res(sz);
    for (int i = 0; i < sz; i++) res[i] = c[i].v;
    while ((int)res.size() > t && res.back() == 0) res.pop_back();
    return res;
}

template <int MOD>
vector<int> shift(vector<int> &ta, int k) {
    using T = Mint<MOD>;
    int n = (int)ta.size();
    vector<T> fat(n + 1, 1), ifat(n + 1), a(n), shifting(n);
    for (int i = 1; i <= n; i++) {
        fat[i] = fat[i - 1] * i;
    }
    ifat[n] = 1 / fat[n];
    for (int i = n; i > 0; i--) {
        ifat[i - 1] = ifat[i] * i;
    }
    for (int i = 0; i < n; i++) {
        a[i] = ta[i] * fat[i];
    }
    T pk = 1;
    for (int i = 0; i < n; i++) {
        shifting[n - i - 1] = pk * ifat[i];
        pk *= k;
    }
    vector<int> a_int(n), s_int(n);
    for (int i = 0; i < n; i++) {
        a_int[i] = a[i].v;
        s_int[i] = shifting[i].v;
    }
    vector<int> b = multiply<MOD>(a_int, s_int);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = (T(b[n - 1 + i]) * ifat[i]).v;
    }
    return ans;
}

const int MOD = 998244353;
using mint = Mint<MOD>;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), b(n + 1);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    auto c = shift<MOD>(a, k);
    auto d = shift<MOD>(b, -k);
    for (auto u : c) {
        cout << u << ' ';
    }
    cout << endl;
    for (auto u : d) {
        cout << u << ' ';
    }
    cout << endl;
    for (int i = 0; i <= n; i++) {
        cout << mint((c[i] + d[i]) % MOD).v << " \n"[i == n];
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
