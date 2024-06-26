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
