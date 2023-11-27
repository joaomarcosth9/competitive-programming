#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

const int maxn = 2e5, maxn2 = 18;
vector<int> g[maxn];
int arr[maxn];

template <typename T> struct rmq {
    vector<T> v;
    int n;
    static const int b = 30;
    vector<int> mask, t;

    int op(int x, int y) { return v[x] < v[y] ? x : y; }
    int msb(int x) { return __builtin_clz(1) - __builtin_clz(x); }
    rmq() {}
    rmq(const vector<T> &v_) : v(v_), n(v.size()), mask(n), t(n) {
        for (int i = 0, at = 0; i < n; mask[i++] = at |= 1) {
            at = (at << 1) & ((1 << b) - 1);
            while (at and op(i, i - msb(at & -at)) == i) at ^= at & -at;
        }
        for (int i = 0; i < n / b; i++) t[i] = b * i + b - 1 - msb(mask[b * i + b - 1]);
        for (int j = 1; (1 << j) <= n / b; j++)
            for (int i = 0; i + (1 << j) <= n / b; i++)
                t[n / b * j + i] = op(t[n / b * (j - 1) + i], t[n / b * (j - 1) + i + (1 << (j - 1))]);
    }
    int small(int r, int sz = b) { return r - msb(mask[r] & ((1 << sz) - 1)); }
    T query(int l, int r) {
        if (r - l + 1 <= b) return small(r, r - l + 1);
        int ans = op(small(l + b - 1), small(r));
        int x = l / b + 1, y = r / b - 1;
        if (x <= y) {
            int j = msb(y - x + 1);
            ans = op(ans, op(t[n / b * j + x], t[n / b * j + y - (1 << j) + 1]));
        }
        return ans;
    }
};

namespace lca {
    int v[2 * maxn], pos[maxn], dep[2 * maxn];
    int t;
    rmq<int> RMQ;

    void dfs(int i, int d = 0, int p = -1) {
        v[t] = i, pos[i] = t, dep[t++] = d;
        for (int j : g[i])
            if (j != p) {
                dfs(j, d + 1, i);
                v[t] = i, dep[t++] = d;
            }
    }
    void build(int n, int root) {
        t = 0;
        dfs(root);
        RMQ = rmq<int>(vector<int>(dep, dep + 2 * n - 1));
    }
    int lca(int a, int b) {
        a = pos[a], b = pos[b];
        return v[RMQ.query(min(a, b), max(a, b))];
    }
    int dist(int a, int b) { return dep[pos[a]] + dep[pos[b]] - 2 * dep[pos[lca(a, b)]]; }
} // namespace lca

namespace vt {
    vector<pair<int, int>> virt[maxn];
    int qt = 0, diff = 0;
    int build_virt(vector<int> v, int _color) {
        set<int> nodes;
        qt = diff = 0;
        auto cmp = [&](int i, int j) { return lca::pos[i] < lca::pos[j]; };
        sort(v.begin(), v.end(), cmp);
        for (int i = (int)v.size() - 1; i; i--) v.push_back(lca::lca(v[i], v[i - 1]));
        sort(v.begin(), v.end(), cmp);
        v.erase(unique(v.begin(), v.end()), v.end());
        for (int i = 0; i < (int)v.size(); i++) virt[v[i]].clear();
        for (int i = 1; i < (int)v.size(); i++) virt[lca::lca(v[i - 1], v[i])].clear();
        for (int i = 1; i < (int)v.size(); i++) {
            int parent = lca::lca(v[i - 1], v[i]);
            int d = lca::dist(parent, v[i]);
            virt[parent].emplace_back(v[i], d);
            if (nodes.find(v[i]) == nodes.end()) {
                nodes.insert(v[i]);
                if (arr[v[i]] != _color) diff++;
                else qt++;
            }
            if (nodes.find(parent) == nodes.end()) {
                nodes.insert(parent);
                if (arr[parent] != _color) diff++;
                else qt++;
            }
        }
        return v[0];
    }
} // namespace vt

vector<int> color[maxn];
long long res[maxn], noderes[maxn], cur[maxn], total = 0;
int qt, diff, current;
map<pair<int, int>, int> idx;

pair<long long, long long> dfs_virt(int u, vector<pair<int, int>> adj[]) {
    long long under = 0, prev = 0, total_noderes = 0, thisnode = 0;
    for (auto [v, _] : adj[u]) {
        auto [_prev, _under] = dfs_virt(v, adj);
        total_noderes += _prev, under += _under;
    }
    thisnode -= total_noderes;
    thisnode += (qt - under - (arr[u] == current)) * (under + (arr[u] == current));
    total_noderes += thisnode;
    noderes[u] += thisnode;
    return {total_noderes, under + (arr[u] == current)};
}

long long dfs(int u, int p = -1) {
    long long prev = 0;
    for (int v : g[u])
        if (v != p) {
            prev += dfs(v, u);
        }
    return res[idx[make_pair(u, p)]] += prev + noderes[u];
}

void solve() {
    int n;
    cin >> n;
    int _root = -1;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        color[arr[i]].emplace_back(i);
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        if (_root == -1) _root = u;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        idx[make_pair(u, v)] = idx[make_pair(v, u)] = i;
    }
    lca::build(n, _root);
    for (int i = 1; i <= n; i++) {
        if (color[i].size() <= 1) continue;
        int root = vt::build_virt(color[i], i);
        qt = vt::qt, diff = vt::diff;
        current = i;
        dfs_virt(root, vt::virt);
    }
    dfs(_root);
    for (int i = 1; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
