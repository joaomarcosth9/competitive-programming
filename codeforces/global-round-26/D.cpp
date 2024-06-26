#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int uniform(long long l, long long r) {
    uniform_int_distribution<long long> uid(l, r);
    return (int)uid(rng);
}

template <typename T> T inverse(T a, T m) {
    T u = 0, v = 1;
    while (a != 0) {
        T t = m / a;
        m -= t * a;
        swap(a, m);
        u -= t * v;
        swap(u, v);
    }
    assert(m == 1);
    return u;
}
template <typename T> class Modular {
  public:
    using Type = typename decay<decltype(T::value)>::type;
    constexpr Modular() : value() {}
    template <typename U> Modular(const U &x) { value = normalize(x); }
    template <typename U> static Type normalize(const U &x) {
        Type v;
        if (-mod() <= x && x < mod())
            v = static_cast<Type>(x);
        else
            v = static_cast<Type>(x % mod());
        if (v < 0) v += mod();
        return v;
    }
    const Type &operator()() const { return value; }
    template <typename U> explicit operator U() const { return static_cast<U>(value); }
    constexpr static Type mod() { return T::value; }
    Modular &operator+=(const Modular &other) {
        if ((value += other.value) >= mod()) value -= mod();
        return *this;
    }
    Modular &operator-=(const Modular &other) {
        if ((value -= other.value) < 0) value += mod();
        return *this;
    }
    template <typename U> Modular &operator+=(const U &other) { return *this += Modular(other); }
    template <typename U> Modular &operator-=(const U &other) { return *this -= Modular(other); }
    template <typename U> Modular &operator^=(const U &other) { return *this = power(*this, other); }
    Modular &operator++() { return *this += 1; }
    Modular &operator--() { return *this -= 1; }
    Modular operator++(int) {
        Modular result(*this);
        *this += 1;
        return result;
    }
    Modular operator--(int) {
        Modular result(*this);
        *this -= 1;
        return result;
    }
    Modular operator-() const { return Modular(-value); }
    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type &operator*=(const Modular &rhs) {
#ifdef _WIN32
        uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
        uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
        asm("divl %4; \n\t" : "=a"(d), "=d"(m) : "d"(xh), "a"(xl), "r"(mod()));
        value = m;
#else
        value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
        return *this;
    }
    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, long long>::value, Modular>::type &
    operator*=(const Modular &rhs) {
        long long q = static_cast<long long>(static_cast<long double>(value) * rhs.value / mod());
        value = normalize(value * rhs.value - q * mod());
        return *this;
    }
    template <typename U = T>
    typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type &operator*=(const Modular &rhs) {
        value = normalize(value * rhs.value);
        return *this;
    }
    Modular &operator/=(const Modular &other) { return *this *= Modular(inverse(other.value, mod())); }
    friend const Type &abs(const Modular &x) { return x.value; }
    template <typename U> friend bool operator==(const Modular<U> &lhs, const Modular<U> &rhs);
    template <typename U> friend bool operator<(const Modular<U> &lhs, const Modular<U> &rhs);
    template <typename V, typename U> friend V &operator>>(V &stream, Modular<U> &number);
 
  private:
    Type value;
};
template <typename T> bool operator==(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T> &lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) == rhs; }
template <typename T> bool operator!=(const Modular<T> &lhs, const Modular<T> &rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T> &lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T> &rhs) { return !(lhs == rhs); }
template <typename T> bool operator<(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value < rhs.value; }
template <typename T> Modular<T> operator+(const Modular<T> &lhs, const Modular<T> &rhs) {
    return Modular<T>(lhs) += rhs;
}
template <typename T, typename U> Modular<T> operator+(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator^(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) ^= rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }
template <typename T> Modular<T> operator-(const Modular<T> &lhs, const Modular<T> &rhs) {
    return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U> Modular<T> operator-(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T> Modular<T> operator*(const Modular<T> &lhs, const Modular<T> &rhs) {
    return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U> Modular<T> operator*(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T> Modular<T> operator/(const Modular<T> &lhs, const Modular<T> &rhs) {
    return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U> Modular<T> operator/(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> power(const Modular<T> &a, const U &b) {
    assert(b >= 0);
    Modular<T> x = a, res = 1;
    U p = b;
    while (p > 0) {
        if (p & 1) res *= x;
        x *= x;
        p >>= 1;
    }
    return res;
}
template <typename T> bool IsZero(const Modular<T> &number) { return number() == 0; }
template <typename T> string to_string(const Modular<T> &number) { return to_string(number()); }
template <typename U, typename T> U &operator<<(U &stream, const Modular<T> &number) { return stream << number(); }
template <typename U, typename T> U &operator>>(U &stream, Modular<T> &number) {
    typename common_type<typename Modular<T>::Type, long long>::type x;
    stream >> x;
    number.value = Modular<T>::normalize(x);
    return stream;
}
 
const int MOD1 = 998244353;
const int MOD2 = (int)(1e9) + 7;
using mint1 = Modular<std::integral_constant<decay<decltype(MOD1)>::type, MOD1>>;
using mint2 = Modular<std::integral_constant<decay<decltype(MOD2)>::type, MOD2>>;

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
    friend ostream& operator<<(ostream& os, Hash o) {
        os << o.h1;
        return os;
    }
};

const int PRIME = uniform(1e6, 3e6);
const int MAXN = 2e6 + 5;
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
            int c = (int)(s[i] - 'a' + 1);
            hsh[i + 1] = hsh[i] + (pot[i + 1] * Hash(c, c));
        }
    }
    Hash operator()(int l = 0, int r = -1) const {
        if (r == -1)
            r = N - 1;
        return (hsh[r + 1] - hsh[l]) * invpot[l];
    }
};

void solve() {
    string s; cin >> s;
    int n = (int)s.size();

    vector<int> first_nona(n + 1, n);
    for (int i = n - 1; i >= 0; i--) {
        first_nona[i] = first_nona[i + 1];
        if (s[i] != 'a') {
            first_nona[i] = i;
        }
    }

    if (first_nona[0] == n) {
        cout << n - 1 << endl;
        return;
    }

    Hashing h(s);

    ll res = 0;

    int f = first_nona[0];

    for (int i = f; i < n; i++) {
        int len = (i - f + 1);
        int ga = f;

        auto hash_now = h(f, i);

        bool db = 1;

        debug(f, i, hash_now);

        for (int j = f; j < n; j++) {
            if (j + len - 1 >= n) {
                db = 0;
                break;
            }
            auto test_hash = h(j, j + len - 1);

            if (hash_now != test_hash) {
                db = 0;
                break;
            }

            int last_id = j + len - 1;

            j = first_nona[j + len] - 1;

            if (j < n - 1) ga = min(ga, j - last_id);
        }

        debug(db);

        if (db) {
            res += ga + 1;
        }

    }

    cout << res << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    precalc();
    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}
