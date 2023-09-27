#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef pair<int, int> ii;
int testcases = 0;
const int INF = 1.05e9;
const ll INFLL = 4.5e18;
#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#define dbarr(x...)
#endif

const int maxn = 1.1e5;
int mergeMask[32][32];

bool contains(const string &s, const string &b) {
    int pos = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == b[pos]) pos++;
        if (pos == (int)b.size()) break;
    }
    return pos == (int)b.size();
}

vector<string> bits = {"a", "b", "c", "ab", "bc"};

struct node {
    int dp[32];
    node() {
        for (int i = 0; i < 32; i++) this->dp[i] = INF;
    }
    node(int bit) {
        for (int i = 0; i < 32; i++) this->dp[i] = INF;
        this->dp[(1 << bit)] = 0;
        this->dp[0] = 1;
    }
};

node neutral_r = node('a' - 'a');
node neutral_l = node('c' - 'a');

node comp(const node &lnode, const node &rnode) {
    node res;
    for (int mask1 = 0; mask1 < 32; mask1++) {
        for (int mask2 = 0; mask2 < 32; mask2++) {
            int mask3 = mergeMask[mask1][mask2];
            if (mask3 == -1) continue;
            res.dp[mask3] = min(res.dp[mask3], lnode.dp[mask1] + rnode.dp[mask2]);
        }
    }
    return res;
}

template <class T> class segtree {
  private:
    int nodes;
    vector<T> tree;
    int le(int n) { return 2 * n + 1; }
    int ri(int n) { return 2 * n + 2; }
    void build(int n, int esq, int dir, const string &s) {
        if (esq == dir) {
            tree[n] = node(s[esq] - 'a');
        } else {
            int mid = (esq + dir) / 2;
            build(le(n), esq, mid, s);
            build(ri(n), mid + 1, dir, s);
            tree[n] = comp(tree[le(n)], tree[ri(n)]);
        }
    }
    void update(int n, int esq, int dir, int x, char v) {
        if (esq > x || dir < x) return;
        if (esq == dir) {
            tree[n] = node(v - 'a');
        } else {
            int mid = (esq + dir) / 2;
            if (x <= mid)
                update(le(n), esq, mid, x, v);
            else
                update(ri(n), mid + 1, dir, x, v);
            tree[n] = comp(tree[le(n)], tree[ri(n)]);
        }
    }

  public:
    segtree(const string &s) {
        nodes = (int)s.size();
        tree.assign(4 * nodes, node());
        build(0, 0, nodes - 1, s);
    }
    int query(int mask) { return tree[0].dp[mask]; }
    void update(int x, char v) { update(0, 0, nodes - 1, x, v); }
};

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    segtree<node> seg(s);
    while (q--) {
        int i;
        char c;
        cin >> i >> c;
        seg.update(i - 1, c);
        int res = INF;
        for (int mask = 0; mask < 32; mask++) {
            res = min(res, seg.query(mask));
        }
        cout << res << endl;
    }
}

signed main() {
#ifndef LOCAL_DEBUG
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    auto resultingMask = [&](vector<string> &m1, vector<string> &m2) {
        int merged = 0;
        for (string &s : m1) {
            for (string &t : m2) {
                string smerged = s + t;
                if (contains(smerged, "abc")) {
                    return -1;
                }
                for (int i = 0; i < 5; i++) {
                    if (contains(smerged, bits[i])) {
                        merged |= (1 << i);
                    }
                }
            }
        }
        return merged;
    };
    for (int mask1 = 0; mask1 < 32; mask1++) {
        for (int mask2 = 0; mask2 < 32; mask2++) {
            vector<string> smask1, smask2;
            for (int i = 0; i < 5; i++) {
                if (mask1 & (1 << i)) smask1.push_back(bits[i]);
                if (mask2 & (1 << i)) smask2.push_back(bits[i]);
            }
            smask1.push_back("");
            smask2.push_back("");
            int merged = resultingMask(smask1, smask2);
            mergeMask[mask1][mask2] = merged;
        }
    }
    int tsts = 1;
    if (testcases) cin >> tsts;
    while (tsts--) solve();
    return 0;
}
