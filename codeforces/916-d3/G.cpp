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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
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
using mint = Modular<std::integral_constant<decay<decltype(mod)>::type, mod>>;

vector<int> compress(vector<int> a) {
    int n = size(a);
    auto b = a;
    sort(all(b));
    b.erase(unique(all(b)), end(b));
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(all(b), a[i]) - begin(b);
    }
    return a;
}

template<typename T> struct LazySegmentTree {
    struct NodeLazy {
        T val;
        bool replace, hasLazy;
        NodeLazy() : val(0), replace(false), hasLazy(false) {}
        NodeLazy(T val, bool replace = false) : val(val), replace(replace), hasLazy(true) {}
        void push(NodeLazy& node) {
            if (replace) {
                node.val = val;
                node.replace = true;
            } else {
                node.val += val;
            }
            node.hasLazy = true;
        }
    };
    struct Node {
        T val;
        int L, R;
        Node() : val(0), L(0), R(0) {} // neutral node
        Node(T val, int L, int R) : val(val), L(L), R(R) {}
        Node(const Node& l, const Node& r) : val(l.val + r.val), L(l.L), R(r.R) {} // merge
        void apply(NodeLazy& node) { 
            if (node.replace) {
                val = node.val * (R - L + 1);
            } else {
                val += node.val * (R - L + 1);
            }
            node = NodeLazy();
        }
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
    vector<NodeLazy> lazy;
    void build(int u, int l, int r) {
        if (l == r) {
            tree[u] = Node(arr[l], l, r);
            return;
        }
        int mid = (l + r) / 2;
        build(u * 2, l, mid);
        build(u * 2 + 1, mid + 1, r);
        tree[u] = Node(tree[u * 2], tree[u * 2 + 1]);
    }
    LazySegmentTree(int N) : N(N) {
        tree.resize(4 * N);
        lazy.resize(4 * N);
    }
    LazySegmentTree(const vector<T> arr) : N(arr.size()), arr(begin(arr), end(arr)) {
        tree.resize(4 * N);
        lazy.resize(4 * N);
        build(1, 0, N - 1);
    }
    Node query(int u, int l, int r, int L, int R) {
        push(u, l, r);
        if (l > R || r < L) return Node();
        if (l >= L && r <= R) return tree[u];
        int mid = (l + r) / 2;
        return Node(query(u * 2, l, mid, L, R), query(u * 2 + 1, mid + 1, r, L, R));
    }
    void push(int u, int l, int r) {
        if (!lazy[u].hasLazy) return;
        if (l != r) {
            lazy[u].push(lazy[u * 2]);
            lazy[u].push(lazy[u * 2 + 1]);
        }
        tree[u].apply(lazy[u]);
    }
    void update(int u, bool replace, int l, int r, int L, int R, T val) {
        push(u, l, r);
        if (l > R || r < L) return;
        if (l >= L && r <= R) {
            lazy[u] = NodeLazy(val, replace);
            push(u, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(u * 2, replace, l, mid, L, R, val);
        update(u * 2 + 1, replace, mid + 1, r, L, R, val);
        tree[u] = Node(tree[u * 2], tree[u * 2 + 1]);
    }
    Node query(int l, int r) {
        return query(1, 0, N - 1, l, r);
    }
    void update(int l, int r, T val, bool replace) {
        update(1, replace, 0, N - 1, l, r, val);
    }
    void updateSum(int l, int r, T val) {
        update(1, 0, 0, N - 1, l, r, val);
    }
    void updateSet(int l, int r, T val) {
        update(1, 1, 0, N - 1, l, r, val);
    }
};

mint calc(vector<int> a) {
    int n = size(a);
    a = compress(a);

    if (a[0] == a.back()) return mint(2);

    vector<int> first(n, -1), second(n, -1);

    for (int i = 0; i < n; i++) {
        if (first[a[i]] == -1) first[a[i]] = i;
        else second[a[i]] = i;
    }

    multiset<ii> pq;
    map<int, int> used;

    for (int i = 0; i < n; i++) if (!used[a[i]]) {
        used[a[i]] = 1;
        pq.emplace(second[a[i]] - first[a[i]], a[i]);
    }

    map<int, ll> conv;
    for (int i = 0; i < n; i++) {
        if (conv.count(a[i])) continue;
        conv[a[i]] = (abs((ll)rng())) % (1ll << 60);
    }

    vector<ll> pref(n);
    pref[0] = conv[a[0]];
    for (int i = 1; i < n; i++) pref[i] = conv[a[i]] ^ pref[i - 1];
    auto query = [&] (int l, int r) {
        if (l == 0) return pref[r];
        else return pref[r] ^ pref[l - 1];
    };

    LazySegmentTree<int> seg(n);
    for (int i = 0; i < n; i++) seg.updateSet(i, i, 1);

    map<ll, int> last;
    for (int i = 0; i < n; i++) last[pref[i]] = i;

    for (int i = 0; i < n; i++) {
        seg.updateSet(i + 1, last[pref[i]], 0);
    }

    debug(pref);

    mint ret = 0;

    for (int i = 0; i < n; i++) {
        ret += seg.query(i, i).val;
    }

    /* assert((int)ret >= 4); */
    return ret;
}

int t = 1;

void solve() {
    int n; cin >> n;
    n *= 2;
    vector<int> a(n);
    vector<int> first(n, -1), second(n, -1);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (first[a[i]] == -1) first[a[i]] = i;
        else second[a[i]] = i;
    }

    /* if (t == 96) { */
    /*     cout << n << "#"; */
    /*     for (int i = 0; i < n; i++) cout << a[i] << "#"; */
    /*     cout << endl; */
    /*     t++; */
    /*     return; */
    /* } */

    int now = 0;
    vector<int> color(n);

    vector<int> L(n), R(n), db(n);

    for (int i = 0; i < n; i++) {
        if (!color[i]) {
            now++;
            int r = second[a[i]];
            L[now] = i;
            db[now] = 1;
            for (int j = i; j <= r; j++) {
                color[j] = now;
                if (second[a[j]] > r) {
                    db[now]++;
                    r = second[a[j]];
                }
                R[now] = r;
            }
        }
    }

    debug(color);
    debug(db);

    cout << now << " ";
    mint res = 1;
    
    for (int c = 1; c <= now; c++) {
        vector<int> b(begin(a) + L[c], begin(a) + R[c] + 1);
        res *= calc(b);
    }

    cout << res << endl;
    t++;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    t = 1;
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
