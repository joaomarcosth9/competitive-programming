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
