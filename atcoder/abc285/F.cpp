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
        vector<int> f;
        bool sorted;
        Node() : f(26), sorted(true) { }
        Node(char c) : f(26), sorted(true) { f[c - 'a'] = 1; }
        Node(const Node& l, const Node& r) : f(26), sorted(l.sorted && r.sorted) {
            int mxl = 0, mnr = 25;
            for (int i = 0; i < 26; i++) if (l.f[i]) mxl = i;
            for (int i = 25; i >= 0; i--) if (r.f[i]) mnr = i;
            if (mnr < mxl) sorted = 0;
            if (sorted) for (int i = 0; i < 26; i++) f[i] = l.f[i] + r.f[i];
        }
    };
    int N;
    string arr;
    vector<Node> tree;
    void build() {
        for (int i = 0; i < N; i++) tree[i + N] = Node(arr[i]);
        for (int i = N - 1; i > 0; i--) tree[i] = Node(tree[i * 2], tree[i * 2 + 1]);
    }
    SegmentTree(int N) : N(N) {
        tree.resize(2 * N);
    }
    SegmentTree(const string arr) : N(arr.size()), arr(begin(arr), end(arr)) {
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
    void update(int i, T val) {
        tree[i += N] = Node(val);
        for (i /= 2; i > 0; i /= 2) tree[i] = Node(tree[i * 2], tree[i * 2 + 1]);
    }
};

void solve() {
    int n, q;
    string s;
    cin >> n >> s >> q;
    SegmentTree<char> seg(s);

    vector<int> F(26);
    for (int i = 0; i < n; i++) F[s[i] - 'a']++;

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int i; char c; cin >> i >> c;
            i--;
            F[s[i] - 'a']--;
            s[i] = c;
            seg.update(i, c);
            F[s[i] - 'a']++;
        } else {
            int l, r; cin >> l >> r;
            l--; r--;
            auto [f, db] = seg.query(l, r);
            int first = -1, last = 27;
            for (int i = 0; i < 26; i++) {
                if (f[i]) last = i;
            }
            for (int i = 25; i >= 0; i--) {
                if (f[i]) first = i;
            }
            for (int i = first + 1; i < last; i++) {
                db &= f[i] == F[i];
            }
            cout << (db ? "Yes" : "No") << endl;
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
