#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

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
 
const int MOD = (int)1e9 + 7;
using mint = Modular<std::integral_constant<decay<decltype(MOD)>::type, MOD>>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    vector<mint> p(n);

    for (auto &x : a)
        cin >> x;

    for (auto &x : p) {
        cin >> x;
        x /= mint(10000);
    }

    vector<mint> prob(1024);
    prob[0] = 1;

    for (int i = 0; i < n; i++) {
        vector<mint> n_prob(1024);
        for (int x = 0; x < 1024; x++) {
            n_prob[x] = (prob[x ^ a[i]] * p[i]) + (prob[x] * (mint(1) - p[i]));
        }
        swap(prob, n_prob);
    }

    mint res = 0;

    for (int i = 0; i < 1024; i++) {
        res += (mint(i) * i) * prob[i];
    }

    cout << res << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}