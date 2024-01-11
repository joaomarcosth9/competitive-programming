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

template<int mod> struct Mint {
    int val;
    Mint(ll v = 0) { val = v % mod; if (val < 0) val += mod; }
    Mint pwr(Mint b, ll e) {
        Mint res;
        for (res = 1; e; e >>= 1, b = b * b) if (e & 1) res = res * b;
        return res;
    }
    bool operator==(Mint o) { return val == o.val; }
    bool operator<(Mint o) const { return val < o.val; }
    friend Mint operator*(Mint a, Mint o) { return (ll)a.val * o.val; }
    friend Mint operator+(Mint a, Mint o) {
        a.val += o.val;
        if (a.val >= mod) a.val -= mod;
        return a;
    }
    friend Mint operator-(Mint a, Mint o) {
        a.val -= o.val;
        if (a.val < 0) a.val += mod;
        return a;
    }
    friend Mint operator^(Mint a, ll o) { return a.pwr(a, o); }
    friend Mint operator/(Mint a, Mint o) { return a * (o ^ (mod - 2)); }
};

const int mod = 998244353;
using mint = Mint<mod>;

template<typename T> struct LazySegmentTree {
    struct NodeLazy {
        T val, mult;
        bool hasLazy;
        NodeLazy() : val(0), mult(1), hasLazy(false) {}
        NodeLazy(T val, T mult) : val(val), mult(mult), hasLazy(true) {}
        void push(NodeLazy& node) {
            node.val = node.val * mult;
            node.mult = node.mult * mult;
            node.val = node.val + val;
            node.hasLazy = hasLazy;
        }
    };
    struct Node {
        T val;
        Node() : val(0) {} // neutral node
        Node(T val) : val(val) {}
        Node(const Node& l, const Node& r) : val(l.val + r.val) {} // merge
        void apply(NodeLazy& node) { 
            val = val * node.mult;
            val = val + node.val;
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
    void update(int u, bool mult, int l, int r, int L, int R, T val) {
        push(u, l, r);
        if (l > R || r < L) return;
        if (l >= L && r <= R) {
            if (mult) {
                lazy[u] = NodeLazy(0, val);
            } else {
                lazy[u] = NodeLazy(val, 1);
            }
            push(u, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(u * 2, mult, l, mid, L, R, val);
        update(u * 2 + 1, mult, mid + 1, r, L, R, val);
        tree[u] = Node(tree[u * 2], tree[u * 2 + 1]);
    }
    mint query(int l, int r) {
        return query(1, 0, N - 1, l, r).val;
    }
    void updateSum(int l, int r, T val) {
        update(1, 0, 0, N - 1, l, r, val);
    }
    void updateMult(int l, int r, T val) {
        update(1, 1, 0, N - 1, l, r, val);
    }
};

void solve() {
    int n, q; cin >> n >> q;

    vector<mint> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].val;

    LazySegmentTree seg(a);

    while (q--) {
        int l, r;
        mint x; cin >> l >> r >> x.val;
        l--; r--;
        mint val = mint(r - l) / (r - l + 1);
        seg.updateMult(l, r, val);
        seg.updateSum(l, r, x / (r - l + 1));
    }

    for (int i = 0; i < n; i++) cout << seg.query(i, i).val << " ";
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
