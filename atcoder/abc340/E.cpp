#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

template<typename T> struct LazySegmentTree {
    struct NodeLazy {
        T val;
        bool replace, hasLazy;
        NodeLazy() : val(0), replace(false), hasLazy(false) {}
        NodeLazy(T _val, bool _replace = false) : val(_val), replace(_replace), hasLazy(true) {}
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
        Node() : val(0), L(-1), R(1e9) {} // neutral node
        Node(T _val, int idx) : val(_val), L(idx), R(idx) {}
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
            tree[u] = Node(arr[l], l);
            return;
        }
        int mid = (l + r) / 2;
        build(u * 2, l, mid);
        build(u * 2 + 1, mid + 1, r);
        tree[u] = Node(tree[u * 2], tree[u * 2 + 1]);
    }
    LazySegmentTree(int _N) : N(_N) {
        tree.resize(4 * N);
        lazy.resize(4 * N);
    }
    LazySegmentTree(const vector<T> _arr) : N(int(_arr.size())), arr(begin(_arr), end(_arr)) {
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
    T query(int l, int r) {
        return query(1, 0, N - 1, l, r).val;
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

void solve() {
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    vector<int> b(m);
    for (ll &i : a) cin >> i;
    for (int &i : b) cin >> i;
    LazySegmentTree<ll> seg(a);
    for (int i = 0; i < m; i++) {
        int j = b[i];
        ll qt = seg.query(j, j);
        seg.updateSet(j, j, 0);
        if (j < n - 1) {
            if (qt <= (n - 1) - j){
                seg.updateSum(j + 1, j + qt, 1);
                qt = 0;
            } else {
                seg.updateSum(j + 1, n - 1, 1);
                qt -= (n - 1) - j;
            }
        }
        if (qt) {
            ll q = qt / n;
            ll r = qt % n;
            seg.updateSum(0, n - 1, q);
            seg.updateSum(0, r - 1, 1);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << seg.query(i, i) << " ";
    }
    cout << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
