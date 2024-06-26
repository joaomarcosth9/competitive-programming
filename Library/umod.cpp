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
