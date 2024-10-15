#include "bits/stdc++.h"
using namespace std;

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
        }
    };
    struct Node {
        T val;
        Node() : val(INT_MIN) {} // neutral node
        Node(T val) : val(val) {}
        Node(const Node& l, const Node& r) : val(max(l.val, r.val)) {} // merge
        void apply(NodeLazy& node) { 
            if (node.replace) {
                val = node.val;
            } else {
                val += node.val;
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
            tree[u] = Node(arr[l]);
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

template<typename T> struct SegmentTree {
    struct Node {
        T val;
        Node() : val(INT_MIN) {} // neutral node
        Node(T val) : val(val) {}
        Node(const Node& l, const Node& r) : val(max(l.val, r.val)) {} // merge
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
    Node query(int l, int r) {
        Node resl = Node(), resr = Node();
        for (l += N, r += N + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) resl = Node(resl, tree[l++]);
            if (r & 1) resr = Node(tree[--r], resr);
        }
        return Node(resl, resr);
    }
    void update(int i, T val, bool replace) {
        tree[i + N] = replace ? Node(val) : Node(tree[i + N].val + val);
        i += N;
        for (i /= 2; i > 0; i /= 2) tree[i] = Node(tree[i * 2], tree[i * 2 + 1]);
    }
    void updateSum(int i, T val) {
        update(i, val, false);
    }
    void updateSet(int i, T val) {
        update(i, val, true);
    }
};

template<typename T> struct HLD {
    int N, t;
    vector<vector<ii>> adj;
    vector<int> par, sz, pos, head, id;
    using Node = LazySegmentTree<T>::Node;
    LazySegmentTree<T> seg;
    HLD(int N) : N(N), adj(N), par(N), sz(N), pos(N), head(N), id(N), seg(N) {}
    void addEdge(int u, int v, T w = 1) {
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    HLD(vector<vector<ii>>& adj) : N(adj.size()), adj(adj), par(N), sz(N), pos(N), head(N), id(N), seg(N) {}
    HLD(vector<vector<int>>& adj2) : N(adj2.size()), adj(N), par(N), sz(N), pos(N), head(N), id(N), seg(N) {
        for (int u = 0; u < N; u++) {
            for (int v : adj2[u]) {
                adj[u].emplace_back(v, 1);
            }
        }
    }
    void predfs(int u, int p = -1) {
        par[u] = p;
        sz[u] = 1;
        for (int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i].first;
            if (v == p) continue;
            predfs(v, u);
            if (sz[v] > sz[adj[u][0].first]) swap(adj[u][0], adj[u][i]);
            sz[u] += sz[v];
        }
    }
    void dfs(int u, int p = -1) {
        id[pos[u] = t++] = u;
        for (int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i].first;
            if (v == p) continue;
            head[v] = (i == 0 ? head[u] : v);
            dfs(v, u);
        }
    }
    void computeNodes(int root, vector<T> arr = {}) {
        predfs(root);
        head[root] = root;
        dfs(root);
        arr.resize(N);
        vector<T> aux(N);
        for (int i = 0; i < N; i++) aux[pos[i]] = arr[i];
        seg = LazySegmentTree<T>(aux);
    }
    void computeEdges(int root) {
        predfs(root);
        head[root] = root;
        dfs(root);
        vector<T> aux(N);
        for (int i = 0; i < N; i++) {
            for (auto &[v, w] : adj[i]) {
                if (v == par[i]) aux[pos[i]] = w;
            }
        }
        seg = LazySegmentTree<T>(aux);
    }
    Node queryPath(int u, int v) {
        Node res;
        while (head[u] != head[v]) {
            if (pos[u] < pos[v]) swap(u, v);
            res = Node(res, seg.query(pos[head[u]], pos[u]));
            u = par[head[u]];
        }
        if (pos[u] > pos[v]) swap(u, v);
        res = Node(res, seg.query(pos[u], pos[v]));
        return res;
    }
    Node querySubtree(int u) {
        return seg.query(pos[u], pos[u] + sz[u] - 1);
    }
    void updatePath(int u, int v, T val, bool replace) {
        while (head[u] != head[v]) {
            if (pos[u] < pos[v]) swap(u, v);
            seg.update(pos[head[u]], pos[u], val, replace);
        }
        if (pos[u] > pos[v]) swap(u, v);
        seg.update(pos[u], pos[v], val, replace);
    }
    void updateSumPath(int u, int v, T val) {
        updatePath(u, v, val, false);
    }
    void updateSetPath(int u, int v, T val) {
        updatePath(u, v, val, true);
    }
    void updateSubtree(int u, T val, bool replace) {
        seg.update(pos[u], pos[u] + sz[u] - 1, val, replace);
    }
    void updateSumSubtree(int u, T val) {
        updateSubtree(u, val, false);
    }
    void updateSetSubtree(int u, T val) {
        updateSubtree(u, val, true);
    }
    int lca(int u, int v) {
        while (head[u] != head[v]) {
            if (pos[u] < pos[v]) swap(u, v);
            u = par[head[u]];
        }
        if (pos[u] > pos[v]) swap(u, v);
        return u;
    }
    int down(int u, int anc) {
        assert(u != anc);
        assert(lca(u, anc) == anc);
        while (par[head[u]] != anc && head[u] != head[anc]) u = par[head[u]];
        if (par[head[u]] == anc) return head[u];
        assert(head[u] == head[anc]);
        assert(par[id[pos[anc] + 1]] == anc);
        return id[pos[anc] + 1];
    }
};



template<typename T = mint> struct Power {
    vector<T> pow;
    Power(int n, T x) : pow(2 * n + 1) {
        pow[n] = T(1);
        pow[n + 1] = x;
        pow[n - 1] = T(1) / x;
        for (int i = n + 2; i < 2 * n + 1; i++) pow[i] = pow[i - 1] * pow[n + 1];
        for (int i = n - 2; i >= 0; i--) pow[i] = pow[i + 1] * pow[n - 1];
    }
    T operator()(int n) const { return pow[size(pow) / 2 + n]; }
    T inv(int n) const { return pow[size(pow) / 2 - n]; }
};

const int N = 1e5 + 5;
Power<mint> Pw(N, 1001003);

void solve() {
    int n, q; cin >> n >> q;

    vector<ll> a(n);
    for (ll &i : a) cin >> i;

    vector<vector<int>> adj(n);

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    HLD<ll> hld(adj);
    hld.computeNodes(0, a);

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int u, x; cin >> u >> x; u--;
            hld.updatePath(u, u, x, true);
        } else {
            int u, v; cin >> u >> v; u--, v--;
            cout << hld.queryPath(u, v) << " ";
        }
    }
    cout << endl;
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
