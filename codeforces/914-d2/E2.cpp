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

const int maxn = 2e5 + 5;
int n, q;
vector<int> adj[maxn];

struct BinaryLifting {
    vector<vector<int>> adj, up;
    vector<int> tin, tout, dep;
    int N, LG, t;

    void dfs(int u, int p = -1, int d = 0) {
        dep[u] = d;
        tin[u] = t++;
        for (int i = 0; i < LG - 1; i++) up[u][i + 1] = up[up[u][i]][i];
        for (int v : adj[u]) if (v != p) {
            up[v][0] = u;
            dfs(v, u, d + 1);
        }
        tout[u] = t++;
    }

    void build(int root, vector<vector<int>> adj2) {
        t = 1;
        N = size(adj2);
        LG = 32 - __builtin_clz(N);
        adj = adj2;
        tin = tout = dep = vector<int>(N);
        up = vector (N, vector<int>(LG));
        up[root][0] = root;
        dfs(root);
    }

    bool ancestor(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }

    int lca(int u, int v) {
        if (ancestor(u, v)) return u;
        if (ancestor(v, u)) return v;
        for (int i = LG - 1; i >= 0; i--) {
            if (!ancestor(up[u][i], v)) u = up[u][i];
        }
        return up[u][0];
    }

    int lca2(int u, int v) {
        assert(ancestor(v, u));
        for (int i = LG - 1; i >= 0; i--) {
            if (!ancestor(up[u][i], v)) u = up[u][i];
        }
        return u;
    }

    int dis(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }

    int kth(int u, int k) {
        for (int i = 0; i < LG; i++) {
            if (k & (1 << i)) u = up[u][i];
        }
        return u;
    }

} bl;

int T = 0;
int tin[maxn], who[maxn], sz[maxn];

void dfs_tin(int u, int p = -1) {
    who[tin[u] = T++] = u;
    sz[u] = 1;
    debug(u, tin[u]);
    for (auto v : adj[u]) if (v != p) {
        dfs_tin(v, u);
        sz[u] += sz[v];
    }
}

ii seg[2 * maxn];

ii merge(ii a, ii b) {
    vector<int> poss {a.first, a.second, b.first, b.second};

    int d = -1;
    ii best = {-1, -1};

    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            int u = poss[i], v = poss[j];
            if (u == -1 || v == -1) continue;
            if (bl.dis(u, v) > d) {
                d = bl.dis(u, v);
                best = {u, v};
            }
        }
    }

    return best;
}

void build() {
    for (int i = 0; i < n; i++) {
        seg[i + n] = make_pair(who[i], who[i]);
        debug(seg[i + n], i, who[i], i + n);
    }
    for (int i = n - 1; i > 0; i--) {
        seg[i] = merge(seg[i * 2], seg[i * 2 + 1]);
    }
}

ii query(int l, int r) {
    ii res = {-1, -1};
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = merge(res, seg[l++]);
        if (r & 1) res = merge(res, seg[--r]);
    }
    return res;
}

void solve() {
    fill(seg, seg + 2 * maxn, make_pair(-1, -1)); 

    cin >> n >> q;

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }

    dfs_tin(0);

    vector<vector<int>> aux(n);
    for (int i = 0; i < n; i++) aux[i] = adj[i];
    bl.build(0, aux);

    build();

    while (q--) {
        int u; cin >> u;
        u--;
        int k; cin >> k;

        vector<ii> rem;
        for (int i = 0; i < k; i++) {
            int v; cin >> v;
            v--;
            debug(v);

            if (bl.ancestor(v, u)) {
                int x = bl.lca2(u, v);
                int L = tin[x], R = tin[x] + sz[x] - 1;
                debug(x);
                debug(L, R);
                if (L > 0) rem.eb(0, L - 1);
                if (R + 1 < n) rem.eb(R + 1, n - 1);
            } else {
                int L = tin[v], R = tin[v] + sz[v] - 1;
                debug(L, R);
                rem.eb(L, R);
            }
        }

        vector<ii> used;

        if (rem.size()) {
            sort(all(rem));
            vector<ii> rem2 = {rem[0]};

            for (int i = 1; i < (int)rem.size(); i++) {
                auto [L, R] = rem[i];
                if (L <= rem2.back().second + 1) rem2.back().second = max(rem2.back().second, R);
                else rem2.eb(L, R);
            }

            debug(rem);
            debug(rem2);

            int L = 0, R = n - 1;

            for (int i = 0; i < (int)rem2.size(); i++) {
                if (rem2[i].first > L) {
                    used.eb(L, rem2[i].first - 1);
                }
                L = rem2[i].second + 1;
            }
            if (rem2.back().second < R) {
                used.eb(rem2.back().second + 1, R);
            }

        } else {
            used.eb(0, n - 1);
        }

        auto base = query(used[0].first, used[0].second);
        debug(used, base);

        for (int i = 1; i < (int)used.size(); i++) {
            base = merge(base, query(used[i].first, used[i].second));
        }

        cout << max(bl.dis(u, base.first), bl.dis(u, base.second)) << endl;

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
