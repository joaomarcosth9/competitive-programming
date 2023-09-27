#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define endl '\n'
#define cerr                                                                                                           \
    if (false) cerr
#endif
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto &x) { return res; }
#define L2(res...) [&](const auto &x, const auto &y) { return res; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;
typedef tuple<int, int, int, int> i4;

const ll maxn = 305, inf = 1e13;
int n, m;
vector<vector<ll>> dis, adj;
vector<vector<ll>> mat[maxn];
vector<i4> edges;

void fw(int l, int r) {
    for (int k = l; k <= r; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}

void solve(int l, int r) {
    if (l == r) {
        mat[l] = dis;
        return;
    }
    int mid = (l + r) / 2;

    auto bkp = dis;

    fw(l, mid);
    solve(mid + 1, r);

    dis = bkp;

    fw(mid + 1, r);
    solve(l, mid);
}

void solve() {
    cin >> n >> m;
    dis = vector(n, vector<ll>(n, inf));
    for (int i = 0; i < n; i++) dis[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        dis[u][v] = dis[v][u] = w;
        edges.eb(i, u, v, w);
    }
    for (int i = 0; i < n; i++) {
        debug(adj[i]);
    }

    solve(0, n - 1);

    vector<ll> res(m, inf);
    for (auto &[id, u, v, w] : edges) {
        for (int i = 0; i < n; i++)
            if (i != v && i != u) {
                res[id] = min(res[id], mat[u][v][i] + mat[v][u][i]);
            }
    }
    for (auto u : res) cout << (u == inf ? -1 : u) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    if (TC) {
        cin >> TC;
        int TEST = 1;
        while (TEST <= TC) {
            cerr << "[Testcase " << TEST << "]" << endl;
            solve();
            ++TEST;
        }
    } else
        solve();
}
