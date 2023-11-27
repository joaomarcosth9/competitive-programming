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

template<typename T> struct SegmentTree {
    struct Node {
        T val;
        Node() : val(0) {} // neutral node
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
    Node query(int l, int r) {
        if (r < 0) return Node();
        if (l > r) return Node();
        if (l >= N) return Node();
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

void solve() {
    int n; cin >> n;
    int q; cin >> q;

    vector<int> a(n);
    for (int &i : a) cin >> i;
    set<int> idx;

    for (int i = 0; i < n; i++) {
        if (a[i] == 1) idx.insert(i);
    }

    SegmentTree seg(a);

    while (q--) {
        debug(idx);
        int t; cin >> t;
        if (t == 1) {
            int target; cin >> target;
            auto first = begin(idx);
            int all = seg.query(0, n - 1).val;

            if (all < target) {
                cout << "NO" << endl;
                continue;
            }

            debug(all, target);

            if (first == end(idx)) {
                if (target % 2 == 1) {
                    cout << "NO" << endl;
                    continue;
                } else {
                    cout << "YES" << endl;
                    continue;
                }
            } else {
                int id = *first + 1;
                int sum = seg.query(id, n - 1).val;
                if (sum >= target - 1) {
                    cout << "YES" << endl;
                    continue;
                } else {
                    int pairity = target - sum;
                    if (pairity % 2 == 1) {
                        cout << "YES" << endl;
                        continue;
                    }
                }
            }

            auto last = rbegin(idx);

            if (last == rend(idx)) {
                if (target % 2 == 1) {
                    cout << "NO" << endl;
                    continue;
                } else {
                    cout << "YES" << endl;
                    continue;
                }
            } else {
                int id = *last - 1;
                int sum = seg.query(0, id).val;
                if (sum >= target - 1) {
                    cout << "YES" << endl;
                    continue;
                } else {
                    int pairity = target - sum;
                    if (pairity % 2 == 1) {
                        cout << "YES" << endl;
                        continue;
                    }
                }
            }

            cout << "NO" << endl;

        } else {
            int i, x; cin >> i >> x;
            i--;
            if (a[i] == x) continue;
            if (a[i] == 1) {
                idx.erase(i);
            } else {
                idx.emplace(i);
            }
            a[i] = x;
            seg.updateSet(i, x);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
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
