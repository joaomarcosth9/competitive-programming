#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif
#define endl '\n'
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto& x){ return res; }
#define L2(res...) [&](const auto& x, const auto& y){ return res; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;

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

const int mod = 998244353;
using mint = Modular<std::integral_constant<decay<decltype(mod)>::type, mod>>;

const int MOD = 998244353;

void ntt(vector<mint> &a, bool rev) {
    int n = a.size();
    auto b = a;
    assert(!(n & (n - 1)));
    mint g = 1;
    while ((g ^ ((MOD - 1) / 2)) == mint(1)) g += 1;
    if (rev) g = 1 / g;

    for (int step = n / 2; step; step /= 2) {
        mint w = g ^ ((MOD - 1) / (n / step)), wn = 1;
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
    if (rev) {
        auto n1 = mint(1) / n;
        for (auto &x : a) x *= n1;
    }
}

vector<mint> convolution(vector<mint> a, vector<mint> b) {
    vector<mint> l(a.begin(), a.end()), r(b.begin(), b.end());
    int N = l.size() + r.size() - 1, n = 1;
    while (n <= N) n *= 2;
    l.resize(n);
    r.resize(n);
    ntt(l, false);
    ntt(r, false);
    for (int i = 0; i < n; i++) l[i] *= r[i];
    ntt(l, true);
    l.resize(N);
    return l;
}

const int maxn = 2e5 + 500;
int n;
vector<ii> adj[maxn];
int sz[maxn], rem[maxn];

int dfs_sz(int i, int l = -1) {
    sz[i] = 1;
    for (auto [j, _] : adj[i])
        if (j != l and !rem[j]) sz[i] += dfs_sz(j, i);
    return sz[i];
}

int centroid(int i, int l, int size) {
    for (auto [j, _] : adj[i])
        if (j != l and !rem[j] and sz[j] > size / 2) return centroid(j, i, size);
    return i;
}

void dfs_poly(int u, vector<mint>& now, int p, int use, int d) {
    if (use) now[d]++;
    for (auto [v, use2] : adj[u]) if (v != p && !rem[v]) {
        dfs_poly(v, now, u, use2, d + use2);
    }
}


mint C[maxn];

void decomp(int i) {
    int c = centroid(i, i, dfs_sz(i));
    dfs_sz(c);
    rem[c] = 1;

    vector<vector<mint>> polys;

    for (auto [v, has] : adj[c]) if (!rem[v]) {
        vector<mint> now(sz[v] + 1);

        dfs_poly(v, now, c, has, has);
        if (has) for (int j = 2; j < (int)now.size(); j++) C[j] += now[j];
        polys.eb(now);
    }

    vector<mint> sum_all;
    for (auto &p : polys) {
        auto square = convolution(p, p);
        for (int j = 0; j < (int)square.size(); j++) C[j] -= square[j] / 2;
        if (size(sum_all) < size(p)) sum_all.resize(size(p));
        for (int j = 0; j < (int)p.size(); j++) sum_all[j] += p[j];
    }

    if (sum_all.size()) {
        auto square = convolution(sum_all, sum_all);
        for (int j = 0; j < (int)square.size(); j++) C[j] += square[j] / 2;
    }

    for (auto [j, _] : adj[c]) {
        if (!rem[j]) decomp(j);
    }
}

void solve() {
    cin >> n;
    int ans1 = 0;
    for (int i = 0; i < n - 1; i++) {
        int u, v, t; cin >> u >> v >> t;
        ans1 += t;
        u--; v--;
        adj[u].eb(v, t);
        adj[v].eb(u, t);
    }

    vector<mint> fat(n);
    fat[0] = 1;
    for (int i = 1; i < n; i++) fat[i] = fat[i - 1] * i;

    vector<mint> ifat(n);
    for (int i = 0; i < n; i++) ifat[i] = 1 / fat[i];

    decomp(0);

    for (int i = 2; i < n; i++) C[i] = C[i] * fat[i - 2];

    assert(C[0] == 0);
    assert(C[1] == 0);

    reverse(all(ifat));

    auto ans = convolution(vector<mint>(C, C + n), ifat);

    cout << ans1 << endl;
    for (int i = 2; i < n; i++) cout << (ans[n - 1 + i] / fat[i - 2]) << endl;
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
