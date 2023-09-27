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
        val += oth.val;
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

using Mint = umod<int, (int)1e9 + 7>;
ostream &operator<<(ostream &os, Mint oth) {
    os << oth.val;
    return os;
}

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, Mint> freq;
    vector<int> vals;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        freq[a] += 1;
    }
    for (auto [val, _] : freq) {
        vals.emplace_back(val);
    }
    Mint res = 0;
    Mint prod = 1;
    for (int i = 0; i < (int)vals.size(); i++) {
        if (i + m - 1 >= (int)vals.size()) break;
        int lo = vals[i], hi = vals[i + m - 1];
        if (hi - lo >= m) continue;
        if (i == 0) {
            for (int j = 0; j < i + m; j++) {
                prod *= freq[vals[j]];
            }
        } else {
            prod /= freq[vals[i - 1]];
            prod *= freq[vals[i + m - 1]];
        }
        res += prod;
    }
    cout << res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
