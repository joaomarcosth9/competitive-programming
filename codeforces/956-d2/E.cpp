#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

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
 
const int mod = (int)1e9 + 7;
using mint = Modular<std::integral_constant<decay<decltype(mod)>::type, mod>>;  

int uniform(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

ll total_scenarios = 0;
ll tot_points_alice = 0;
ll tot_points_bob = 0;

void brute(vector<pair<int, int>> balls, int turn, ll pa = 0, ll pb = 0) {
    int n = (int)balls.size();
    if (n == 0) {
        total_scenarios++;
        tot_points_alice += pa;
        tot_points_bob += pb;
        return;
    }
    for (int i = 0; i < n; i++) {
        auto [special, value] = balls[i];
        auto n_balls = balls;
        n_balls.erase(n_balls.begin() + i);
        ll n_pa = pa, n_pb = pb;
        if (turn == 0) {
            n_pa += value;
        } else {
            n_pb += value;
        }
        if (special == 0) {
            brute(n_balls, turn ^ 1, n_pa, n_pb);
        } else {
            brute(n_balls, turn, n_pa, n_pb);
        }
    }
}

void solve() {
    cout << setprecision(10) << fixed;
    total_scenarios = 0;
    tot_points_alice = 0;
    tot_points_bob = 0;

    int n, k; cin >> n >> k;
    vector<pair<int, int>> a(n);

    for (int i = 0; i < n; i++) {
        a[i].first = (i < k);
        cin >> a[i].second;
    }

    ll sum = 0, sum_special = 0;

    for (int i = 0; i < n; i++) {
        sum += a[i].second;
        if (a[i].first == 1) {
            sum_special += a[i].second;
        }
    }

    using mint = long double;

    vector<mint> ex_special(n + 1, 0), ex_not_special(n + 1, 0);
    vector<mint> ex_sum_total(n + 1, 0);
    vector<mint> ex_cnt_special(n + 1, 0), ex_cnt_not_special(n + 1, 0);
    vector<mint> prob_alice(n + 1, 0), prob_bob(n + 1, 0);
ex_special[0] = sum_special;
    ex_not_special[0] = sum - sum_special;
    ex_sum_total[0] = sum;
    ex_cnt_special[0] = k;
    ex_cnt_not_special[0] = n - k;
    prob_alice[0] = 1;
    prob_bob[0] = 0;

    mint e_a = 0, e_b = 0;

    for (int i = 0; i < n; i++) {
        mint prob_special = (mint)ex_cnt_special[i] / (n - i);
        mint prob_not_special = 1 - prob_special;
        mint expected_points_now = ex_sum_total[i] / (n - i);
        
        ex_special[i + 1] = ex_special[i] - (prob_special * ex_special[i]);
        ex_not_special[i + 1] = ex_not_special[i] - (prob_not_special * ex_not_special[i]);
        ex_sum_total[i + 1] = ex_sum_total[i] - expected_points_now;

        ex_cnt_special[i + 1] = ex_cnt_special[i] - prob_special;
        ex_cnt_not_special[i + 1] = ex_cnt_not_special[i] - prob_not_special;

        prob_alice[i + 1] = prob_alice[i] * prob_special + prob_bob[i] * prob_not_special;
        prob_bob[i + 1] = 1 - prob_alice[i + 1];

        e_a += prob_alice[i] * expected_points_now;
        e_b += prob_bob[i] * expected_points_now;
        debug(i, e_a, e_b, prob_alice[i], prob_bob[i]);
        debug(ex_special[i], ex_not_special[i], ex_sum_total[i], ex_cnt_special[i], ex_cnt_not_special[i]);
        debug(prob_alice[i], prob_bob[i], prob_special, prob_not_special, expected_points_now);
    }

    cout << e_a << " " << e_b << endl;

    cout << "Sum: " << sum << endl;

    // cout << "Sum Special: " << sum_special << endl;

    // cout << "Sum not Special: " << sum - sum_special << endl;

    brute(a, 0);

    // cout << "Modular expected Alice: " << mint(tot_points_alice) / total_scenarios << endl;

    // cout << "Modular expected Bob: " << mint(tot_points_bob) / total_scenarios << endl;

    cout << "Expected Alice: " << fixed << setprecision(10) << (long double)tot_points_alice / total_scenarios << endl;

    cout << "Expected Bob: " << fixed << setprecision(10) << (long double)tot_points_bob / total_scenarios << endl;
    return;

    long double expected_alice = (long double)tot_points_alice / total_scenarios;

    cout << "prob_alice: " << expected_alice / sum << endl;
    cout << "prob_bob: " << 1.0 - (expected_alice / sum) << endl;

    // cout << "Total Scenarios: " << total_scenarios << endl;

    // cout << "Total Points Alice: " << tot_points_alice << endl;

    // cout << "Total Points Bob: " << tot_points_bob << endl;

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
