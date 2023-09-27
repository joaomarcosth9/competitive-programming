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
#define int ll

const int maxn = 200005;
int n, m, k;
bool vis[maxn];
int a[maxn];
vector<int> adj[maxn];
vector<int> roots;
int dp[maxn];
int TIME = 0;

int dfs(int u, int mx, int time) {
    TIME = max(TIME, time);
    vis[u] = 1;
    int ret = time;
    for (int v : adj[u]) {
        if (vis[v]) {
            if (a[v] >= mx) {
                ret = max(ret, time + dp[v] + (a[v] - mx));
            } else {
                ret = max(ret, time + dp[v] + (k - mx) + (a[v]));
            }
            continue;
        }
        if (a[v] >= mx)
            ret = max(ret, dfs(v, a[v], time + (a[v] - mx)));
        else
            ret = max(ret, dfs(v, a[v], time + (k - mx) + a[v]));
    }
    return dp[u] = ret;
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> root(n, 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        root[v] = 0;
        adj[u].eb(v);
    }
    for (int i = 0; i < n; i++)
        if (root[i]) roots.eb(i);
    bool first = 1;
    vector<int> valroots;
    for (auto u : roots) {
        valroots.eb(a[u]);
    }
    sort(all(valroots));
    debug(valroots);
    ll res = LLONG_MAX;
    int N = ssize(roots);
    vector<int> hl(N);
    for (int i = 0; i < N; i++) {
        int u = roots[i];
        TIME = 0;
        hl[i] = dfs(u, a[u], 0);
    }

    auto valroots2 = valroots;
    for (int i = 0; i < N; i++) {
        valroots2[i] += hl[i];
    }
    debug(valroots2);
    debug(hl);

    vector<ll> suff(N + 1, 0);
    vector<ll> pref(N + 1, 0);
    for (int i = N - 1; i >= 0; i--) {
        suff[i] = max(suff[i + 1], valroots2[i]);
    }
    for (int i = 1; i <= N; i++) {
        pref[i] = max(pref[i - 1], valroots2[i - 1]);
    }

    for (int i = 0; i < N; i++) {
        ll cres = LLONG_MIN;
        if (i == 0) {
            cres = suff[i] - valroots[i];
            res = min(res, cres);
        } else {
            cres = max(suff[i] - valroots[i], cres);
            cres = max(cres, pref[i] + (k - valroots[i]));
        }
        debug(i, valroots[i], suff[i], pref[i]);
        debug(cres);
        res = min(res, cres);
    }

    assert(res != LLONG_MAX);
    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        int TEST = 1;
        while (TEST <= TC) {
            cerr << "[Testcase " << TEST << "]" << endl;
            solve();
            for (int i = 0; i <= n; i++) {
                adj[i].clear();
                a[i] = 0;
                dp[i] = 0;
                vis[i] = 0;
            }
            roots.clear();
            ++TEST;
        }
    } else
        solve();
}
