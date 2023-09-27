#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define endl '\n'
#define cerr if (false) cerr
#endif
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
#define int ll

const int maxn = 200005;
int n, m, k; 
int VIS = 0;
bool vis[maxn];
int a[maxn];
vector<int> adj[maxn];
vector<int> roots;
vector<int> nroots;
int MAX = -1;

void dfs(int u, int mx) {
    MAX = max(MAX, mx);
    assert(!vis[u]);
    vis[u] = 1;
    VIS += 1;
    for (int v : adj[u]) if (!vis[v]) {
        if (a[v] >= mx) dfs(v, a[v]);
        else nroots.eb(v);
    }
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> root(n, 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        root[v] = 0;
        adj[u].eb(v);
    }
    for (int i = 0; i < n; i++) if (root[i]) roots.eb(i);
    bool first = 1;
    vector<int> valroots, valroots2;
    for (auto u : roots) {
        valroots.eb(a[u]);
    }
    for (auto u : roots) {
        valroots2.eb(a[u] + k);
    }
    sort(all(valroots));
    sort(all(valroots2));
    debug(valroots);
    debug(valroots2);
    ll res = 0;
    while (1) {
        int mn = INT_MAX;
        MAX = 0;
        int N = ssize(roots);
        vector<int> day(N, 0);
        if (first) {
            int cmn = INT_MAX;
            for (int i = 0; i < N; i++) {
                cmn = k - valroots[i];
                if (i > 0) cmn += valroots[i - 1];
                mn = min(mn, cmn);
            }
            cmn = INT_MAX;
            for (int i = 0; i < N; i++) {
                cmn = k - valroots[i];
                if (i > 0) cmn += valroots[i - 1];
                if (cmn == mn) {
                    for (int j = (i - 1); j >= 0; j--) {
                        day[j] = 1;
                    }
                }
            }
        }
        for (int i = 0; i < N; i++) {
            int u = roots[i];
            if (vis[u]) continue;
            if (day[i] == 1) {
                nroots.eb(u);
                continue;
            }
            if (!first) dfs(u, a[u]);
            else dfs(u, a[u]);
        }
        if (!first) mn = 0;
        first = 0;
        debug(mn);

        if (VIS == n) {
            res += MAX - mn;
            debug(res);
            break;
        }
        res += (k - mn);
        debug(res);
        roots = nroots;
    }
    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) { cin >> TC;
        int TEST = 1;
        while (TEST <= TC) {
            cerr << "[Testcase " << TEST << "]" << endl;
            solve();
            for (int i = 0; i <= n; i++) {
                adj[i].clear();
                a[i] = 0;
                vis[i] = 0;
            }
            VIS = 0;
            roots.clear();
            nroots.clear();
            ++TEST;
        }
    } else solve();
}
