mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long uniform(long long l, long long r) {
    uniform_int_distribution<long long> uid(l, r);
    return uid(rng);
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
 
const int mod = 998244353;
using mint = Modular<std::integral_constant<decay<decltype(mod)>::type, mod>>;

template<typename T = mint> struct Factorials {
    vector<T> fact, ifact;
    Factorials(int n): fact(n + 1), ifact(n + 1) {
        assert(n < mod);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
        ifact[n] = 1 / fact[n];
        for (int i = n; i >= 1; i--) ifact[i - 1] = ifact[i] * i;
    }
    T operator()(int n) const { return fact[n]; }
    T inv(int n) const { return ifact[n]; }
};

template<typename T = mint> struct Power {
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

template<typename T = mint> struct Binomial {
    Factorials<T> f;
    Binomial(int n): f(n) {}
    T ncr(int n, int r) const {
        if (r < 0 || r > n) return 0;
        return f(n) * f.inv(r) * f.inv(n - r);
    }
    T npr(int n, int r) const {
        if (r < 0 || r > n) return 0;
        return f(n) * f.inv(n - r);
    }
    T snb(int n, int k) const {
        return ncr(n + k - 1, n);
    }
};

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
template <typename T, typename U, typename V> pair<T, U> operator+(const pair<T, U>& l, const V& r) {
    return {l.first + r, l.second + r};
}
template <typename T, typename U, typename V> pair<T, U> operator-(const pair<T, U>& l, const V& r) {
    return {l.first - r, l.second - r};
}
template <typename T, typename U, typename V> pair<T, U> operator*(const pair<T, U>& l, const V& r) {
    return {l.first * r, l.second * r};
}
template <typename T, typename U, typename V> pair<T, U> operator/(const pair<T, U>& l, const V& r) {
    return {l.first / r, l.second / r};
}
template <typename T, typename U, typename V> pair<T, U>& operator+=(pair<T, U>& l, const V& r) {
    return l = l + r;
}
template <typename T, typename U, typename V> pair<T, U>& operator-=(pair<T, U>& l, const V& r) {
    return l = l - r;
}
template <typename T, typename U, typename V> pair<T, U>& operator*=(pair<T, U>& l, const V& r) {
    return l = l * r;
}
template <typename T, typename U, typename V> pair<T, U>& operator/=(pair<T, U>& l, const V& r) {
    return l = l / r;
}

const int N = 1e6 + 5;

const int mod1 = 998244353;
const int mod2 = 1e9 + 7;
using mint1 = Modular<std::integral_constant<decay<decltype(mod1)>::type, mod1>>;
using mint2 = Modular<std::integral_constant<decay<decltype(mod2)>::type, mod2>>;

using Hash = pair<mint1, mint2>;

const int PRIME = 1000000 + (rng() % 1000000);

Power<Hash> Pw(N, {PRIME, PRIME});

template<typename obj> struct Hashing {
    vector<Hash> hsh;
    int N;
    bool inverse;
    Hashing(obj s, bool inverse = false) : inverse(inverse) {
        N = size(s);
        if (inverse) reverse(begin(s), end(s));
        hsh.resize(N);
        hsh[0] = Hash(s[0], s[0]);
        for (int i = 1; i < N; i++) {
            hsh[i] = hsh[i - 1] + (Pw(i) * s[i]);
        }
    }
    Hash operator()(int l, int r) const {
        if (inverse) {
            l = N - 1 - l;
            r = N - 1 - r;
            swap(l, r);
        }
        if (l == 0) return hsh[r];
        return (hsh[r] - hsh[l - 1]) * Pw(-l);
    }
};

template<typename obj> struct DynamicHashing {
    template<typename T = int, typename U = int> struct SegmentTree {
        struct Node {
            T val;
            Node() : val(0, 0) {} // neutral node
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
        SegmentTree(const vector<U>& arr) : N(arr.size()), arr(begin(arr), end(arr)) {
            tree.resize(2 * N);
            build();
        }
        Node query(int l, int r) {
            Node resl = Node(), resr = Node();
            for (l += N, r += N + 1; l < r; l /= 2, r /= 2) {
                if (l & 1) resl = Node(resl, tree[l++]);
                if (r & 1) resr = Node(tree[--r], resr);
            }
            return Node(resl, resr);
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
    int N;
    obj s;
    bool inverse;
    SegmentTree<Hash, Hash> hsh;
    DynamicHashing(obj s, bool inverse = false) : N(size(s)), s(s), inverse(inverse), hsh(N) {
        if (inverse) reverse(begin(s), end(s));
        vector<Hash> arr(N);
        for (int i = 0; i < N; i++) {
            arr[i] = (Pw(i) * s[i]);
        }
        hsh = SegmentTree<Hash, Hash>(arr);
    }
    Hash operator()(int l, int r) {
        if (inverse) {
            l = N - 1 - l;
            r = N - 1 - r;
            swap(l, r);
        }
        return (Hash)hsh.query(l, r) * Pw(-l);
    }
    void update(int i, char c) {
        if (inverse) i = N - 1 - i;
        hsh.updateSet(i, Pw(i) * c);
    }
};
