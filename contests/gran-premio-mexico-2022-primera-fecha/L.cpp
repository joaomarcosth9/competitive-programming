#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

template <auto MOD, typename T = decltype(MOD)>
struct Mint {
    using m = Mint<MOD, T>;
    T v;
    Mint(T val = 0) : v(val) {
        if (v < 0) v += MOD;
    }
    bool operator==(m o) const { return v == o.v; }
    bool operator!=(m o) const { return v != o.v; }
    bool operator<(m o) const { return v < o.v; }
    m pwr(m b, ll e) {
        m res = 1;
        while (e > 0) {
            if (e & 1) res *= b;
            b *= b, e >>= 1;
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
        v = (T)((ll)v * o.v % MOD);
        return *this;
    }
    m &operator/=(m o) { return *this *= o.pwr(o, MOD - 2); }
    m &operator^=(ll e) { return *this = pwr(*this, e); }
    friend m operator-(m a, m b) { return a -= b; }
    friend m operator+(m a, m b) { return a += b; }
    friend m operator*(m a, m b) { return a *= b; }
    friend m operator/(m a, m b) { return a /= b; }
    friend m operator^(m a, ll e) { return a.pwr(a, e); }
};

const int MOD = 1e9 + 7;
using mint = Mint<MOD>;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    vector<int> L(n, -1), R(n, n);
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        while (stk.size() && a[i] > a[stk.top()]) {
            R[stk.top()] = i;
            stk.pop();
        }
        if (stk.size()) {
            if (a[stk.top()] > a[i]) {
                L[i] = stk.top();
            } else {
                L[i] = L[stk.top()];
            }
        }
        stk.push(i);
    }

    vector<mint> pref(n + 1), suff(n + 2), p2(n + 1), s2(n + 2);

    for (int i = 1; i <= n; i++) {
        if (a[i - 1] < 0) a[i - 1] += MOD;
        pref[i] = pref[i - 1] + a[i - 1];
    }

    for (int i = n; i >= 1; i--) {
        suff[i] = suff[i + 1] + a[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        p2[i] = p2[i - 1] + pref[i];
    }

    for (int i = n; i >= 1; i--) {
        s2[i] = s2[i + 1] + suff[i];
    }

    function<mint(int, int)> sumQuery = [&] (int l, int r) {
        return pref[r + 1] - pref[l];
    };

    function<mint(int, int)> queryTras = [&] (int l, int r) {
        return s2[l + 1] - s2[r + 2] - (suff[r + 2] * (r - l + 1));
    };

    function<mint(int, int)> queryFrente = [&] (int l, int r) {
        return p2[r + 1] - p2[l] - (pref[l] * (r - l + 1));
    };

    mint ans = 0;
    for (int i = 0; i < n; i++) {
        ans += queryTras(L[i] + 1, i) * (R[i] - i) + queryFrente(i + 1, R[i] - 1) * (i - L[i]);
    }
    cout << ans.v << endl;

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
