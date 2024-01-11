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
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

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
const int mod2 = 1e9 + 7;
using mint1 = Modular<std::integral_constant<decay<decltype(mod)>::type, mod>>;
using mint2 = Modular<std::integral_constant<decay<decltype(mod2)>::type, mod2>>;

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

using Hash = pair<mint2, mint2>;

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

const int P = abs(1e6 + (rng() % (int)1e6));

const int N = 1e6 + 5;
Power<Hash> Pw(N, Hash(P, P));

template<typename T> struct SegmentTree {
    struct Node {
        T val;
        Node() : val() {} // neutral node
        Node(T val) : val(val) {}
        Node(const Node& l, const Node& r) : val(l.val + r.val) {} // merge
        friend ostream& operator<<(ostream& os, const Node& node) {
            return os << node.val;
        }
        explicit operator T() const {
            return val;
        }
    };
    int N;
    vector<T> arr;
    vector<Node> tree;
    void build() {
        for (int i = 0; i < N; i++) tree[i + N] = Node(arr[i]);
        for (int i = N - 1; i > 0; i--) tree[i] = Node(tree[i * 2], tree[i * 2 + 1]);
    }
    SegmentTree(int N) : N(N) {
        tree.resize(2 * N);
    }
    SegmentTree(const vector<T> arr) : N(arr.size()), arr(begin(arr), end(arr)) {
        tree.resize(2 * N);
        build();
    }
    T query(int l, int r) {
        Node resl = Node(), resr = Node();
        for (l += N, r += N + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) resl = Node(resl, tree[l++]);
            if (r & 1) resr = Node(tree[--r], resr);
        }
        return Node(resl, resr).val;
    }
    void update(int i, T val, bool replace) {
        tree[i += N] = replace ? Node(val) : Node(tree[i].val + val);
        for (i /= 2; i > 0; i /= 2) tree[i] = Node(tree[i * 2], tree[i * 2 + 1]);
    }
    void updateSum(int i, T val) {
        update(i, val, false);
    }
    void updateSet(int i, T val) {
        update(i, val, true);
    }
};

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;

    string revs = s;
    reverse(all(revs));

    SegmentTree<Hash> seg(n), seg2(n);

    for (int i = 0; i < n; i++) {
        seg.updateSet(i, Hash(s[i], s[i]) * Pw(i));
    }

    for (int i = 0; i < n; i++) {
        seg2.updateSet(i, Hash(revs[i], revs[i]) * Pw(i));
    }

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int i; char c; cin >> i >> c;
            i--;
            int j = n - 1 - i;

            s[i] = c;
            revs[j] = c;

            seg.updateSet(i, Hash(s[i], s[i]) * Pw(i));
            seg2.updateSet(j, Hash(revs[j], revs[j]) * Pw(j));

        } else {
            int l, r; cin >> l >> r;
            l--; r--;
            int l1 = n - 1 - l;
            int r1 = n - 1 - r;
            swap(l1, r1);

            auto q1 = seg.query(l, r) * Pw(-l);
            auto q2 = seg2.query(l1, r1) * Pw(-l1);

            cout << (q1 == q2 ? "Yes" : "No") << endl;

        }
    }
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
