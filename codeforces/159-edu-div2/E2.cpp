#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif
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
#define endl '\n'
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto& x){ return res; }
#define L2(res...) [&](const auto& x, const auto& y){ return res; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int long long 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

const int mod = 998244353;
using mint1 = Modular<std::integral_constant<decay<decltype(mod)>::type, mod>>;
const int mod2 = 1e9 + 7;
using mint2 = Modular<std::integral_constant<decay<decltype(mod2)>::type, mod2>>;
using Hash = pair<mint1, mint2>;

template <typename T, typename U> pair<T, U> operator+(const pair<T, U>& l, const pair<T, U>& r) {
    return {l.first + r.first, l.second + r.second};
}
template <typename T, typename U> pair<T, U> operator-(const pair<T, U>& l, const pair<T, U>& r) {
    return {l.first - r.first, l.second - r.second};
}
template <typename T, typename U> pair<T, U> operator*(const pair<T, U>& l, const pair<T, U>& r) {
    return {l.first * r.first, l.second * r.second};
}
template <typename T, typename U> pair<T, U> operator/(const pair<T, U>& l, const pair<T, U>& r) {
    return {l.first / r.first, l.second / r.second};
}
template <typename T, typename U> pair<T, U>& operator+=(pair<T, U>& l, const pair<T, U>& r) {
    return l = l + r;
}
template <typename T, typename U> pair<T, U>& operator-=(pair<T, U>& l, const pair<T, U>& r) {
    return l = l - r;
}
template <typename T, typename U> pair<T, U>& operator*=(pair<T, U>& l, const pair<T, U>& r) {
    return l = l * r;
}
template <typename T, typename U> pair<T, U>& operator/=(pair<T, U>& l, const pair<T, U>& r) {
    return l = l / r;
}
template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p) {
    return is >> p.first >> p.second;
}
template <typename T, typename U> pair<T, U> operator+(const pair<T, U>& l, const T& r) {
    return {l.first + r, l.second + r};
}
template <typename T, typename U> pair<T, U> operator-(const pair<T, U>& l, const T& r) {
    return {l.first - r, l.second - r};
}
template <typename T, typename U> pair<T, U> operator*(const pair<T, U>& l, const T& r) {
    return {l.first * r, l.second * r};
}
template <typename T, typename U> pair<T, U> operator/(const pair<T, U>& l, const T& r) {
    return {l.first / r, l.second / r};
}
template <typename T, typename U> pair<T, U>& operator+=(pair<T, U>& l, const T& r) {
    return l = l + r;
}
template <typename T, typename U> pair<T, U>& operator-=(pair<T, U>& l, const T& r) {
    return l = l - r;
}
template <typename T, typename U> pair<T, U>& operator*=(pair<T, U>& l, const T& r) {
    return l = l * r;
}
template <typename T, typename U> pair<T, U>& operator/=(pair<T, U>& l, const T& r) {
    return l = l / r;
}

template<typename T> struct Power {
    vector<T> pow;
    Power(int n, T x) : pow(2 * n + 1) {
        pow[n] = T(1, 1);
        pow[n + 1] = x;
        pow[n - 1] = T(1, 1) / x;
        for (int i = n + 2; i < 2 * n + 1; i++) pow[i] = pow[i - 1] * pow[n + 1];
        for (int i = n - 2; i >= 0; i--) pow[i] = pow[i + 1] * pow[n - 1];
    }
    T operator()(int n) const { return pow[size(pow) / 2 + n]; }
    T inv(int n) const { return pow[size(pow) / 2 - n]; }
};

const int P = 1e6 + (rng() % 1000000);
const int N = 1e6 + 5;
Power<Hash> Pw(N, Hash(P, P));

using Hash = pair<mint1, mint2>;

void solve() {
    int n; cin >> n;
    vector<string> b(n);
    for (auto& x : b) cin >> x;

    auto calc = []( vector<string> a) {
        int n = a.size();
        ll res = 0;

        map<Hash, int> pref;
        map<Hash, int> suff;

        for (int i = 0; i < n; i++) {
            auto &s = a[i];
            vector<Hash> ss(n);

            Hash now = {0, 0};
            for (int j = 0; j < (int)s.size(); j++) {
                now += Pw(j) * Hash(s[j] - 'a' + 1, s[j] - 'a' + 1);
                ss[j] = now;
            }

            ll added = 0;
            for (int j = (int)s.size() - 1; j >= 0; j--) {
                auto cur = ss[j];   
                res += suff[cur];
                added += suff[cur];
            }
            res += pref[Hash(0, 0)] - added;

            now = {0, 0};
            for (int j = (int)s.size() - 1; j >= 0; j--) {
                now += Pw((int)s.size() - j - 1) * Hash(s[j] - 'a' + 1, s[j] - 'a' + 1);
                suff[now] += s.size() - j;
            }

            pref[Hash(0, 0)] += s.size();
            for (int j = 0; j < (int)s.size(); j++) {
                pref[ss[j]] += s.size() - j - 1;
            }

        }

        return res;
    };

    ll res = 0;
    res = calc(b);
    reverse(all(b));
    res += calc(b);

    for (int i = 0; i < n; i++) {
        auto &s = b[i];
        int it = 0, it2 = (int)s.size() - 1;
        ll size = 2 * (int)s.size();
        while (it < it2) {
            if (s[it] == s[it2]) {
                it++;
                it2--;
                size -= 2;
            } else {
                res += size;
                break;
            }
        }
    }

    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
