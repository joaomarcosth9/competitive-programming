#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

template<typename T> struct SegmentTree {
    struct Node {
        T val;
        Node() : val(0) {} // neutral node
        Node(T _val) : val(_val) {}
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
    SegmentTree(int _N) : N(_N) {
        tree.resize(2 * N);
    }
    SegmentTree(const vector<T> _arr) : N(_arr.size()), arr(begin(_arr), end(_arr)) {
        tree.resize(2 * N);
        build();
    }
    int query(int l, int r) {
        Node resl = Node(), resr = Node();
        for (l += N, r += N + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) resl = Node(resl, tree[l++]);
            if (r & 1) resr = Node(tree[--r], resr);
        }
        return Node(resl, resr).val;
    }
    void update(int i, T val, bool replace) {
        i += N;
        if (replace) tree[i] = Node(val);
        else tree[i] = Node(tree[i].val + val);
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
    int n, m; cin >> n >> m;

    vector<vector<tuple<int, int>>> events(n + 2);

    for (int i = 0; i < m; i++) {
        int l, r, x; cin >> l >> r >> x;
        events[r].push_back({l, x});
    }

    vector<int> res(n + 2);
    SegmentTree<int> seg(n + 5);
    stack<int> stk;

    for (int r = 0; r <= n + 1; r++) {
        stk.push(r);
        for (auto [l, x] : events[r]) {
            int has = seg.query(l, r);
            while (has < x) {
                res[stk.top()] = 1;
                seg.updateSet(stk.top(), 1);
                stk.pop();
                has++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << res[i] << " \n"[i == n];
    }

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
