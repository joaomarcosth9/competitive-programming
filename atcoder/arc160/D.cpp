#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

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

Mint fat[100005], invfat[100005];

Mint nck(long long n, long long k) { return fat[n] / (fat[k] * fat[n - k]); }

int op = 0;
Mint ncknaive(long long n, long long k) {
    debug(n, k);
    if (k > n) return 0;
    if (n == 0) return 1;
    if (k == 0) return 1;
    Mint ret = 1;
    for (long long U = n; U > max(k, n - k); U--) {
        ret *= U;
        op++;
        assert(op <= 1e8);
    }
    ret /= fat[min(k, n - k)];
    return ret;
}

void solve() {
    /* long long a, b; cin >> a >> b; */
    /* cout << nck(a, b) << '\n'; */
    /* cout << ncknaive(a, b) << '\n'; */
    /* return; */
    long long n, m, k;
    cin >> n >> m >> k;
    debug(n, m, k);
    if (m % k) {
        cout << 0 << '\n';
        return;
    }
    m /= k;
    debug(n, m, k);

    Mint res = 0;

    for (int i = 0; i <= (n - k + 1); i++) {
        debug(i);
        Mint curr1 = nck(n - k + 1, i);
        Mint curr2 = ncknaive(m + 2 * n - (i + 1) * k, 2 * n - k);
        if (i & 1)
            res -= curr1 * curr2;
        else
            res += curr1 * curr2;
    }
    cout << res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    fat[0] = 1;
    for (int i = 1; i < 100005; i++) {
        fat[i] = fat[i - 1] * i;
    }
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
