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

const int maxn = 2005;
int n, m; 
vector<int> adj[maxn];
int grau[maxn];
int from[maxn];
int source[maxn];
int vis[maxn];
bool cycle[maxn];
int db = 0, db2 = 0;

vector<ii> edges;

bool test(int u) {
    for (int i = 0; i <= n; i++) vis[i] = (cycle[i] = 0);
    for (int i = 0; i <= n; i++) source[i] = from[i] = -1;
    db = db2 = 0;

    queue<int> q;

    for (int v : adj[u]) {
        q.emplace(v);
        from[v] = u;
        source[v] = v;
    }

    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        for (auto w : adj[v]) if (w != u) {
            if (source[w] == -1) {
                source[w] = source[v];
                from[w] = v;
                q.emplace(w);
            } else if (source[w] != source[v]) {
                db = w;
                db2 = v;
                edges.eb(db, db2);
                break;
            }
        }
        if (db) break;
    }

    if (!db) return 0;

    cycle[u] = 1;
    while (db != u) {
        edges.eb(db, from[db]);
        cycle[db] = 1;
        db = from[db];
    }
    while (db2 != u) {
        edges.eb(db2, from[db2]);
        cycle[db2] = 1;
        db2 = from[db2];
    }

    int cnt = 0;
    for (int v : adj[u]) if (!cycle[v]) {
        edges.eb(u, v);
        cnt++;
        if (cnt > 1) break;
    }

    if (cnt < 0) return 0;

    return 1;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].eb(v);
        adj[v].eb(u);
        grau[u]++; grau[v]++;
    }

    bool dbb = 0;

    for (int i = 1; i <= n; i++) if (grau[i] >= 4) {
        if (test(i)) {
            dbb = 1;

            cout << "YES" << endl;
            cout << size(edges) << endl;
            for (auto [u, v] : edges) cout << u << " " << v << endl;
            edges.clear();

            break;
        }
    }

    if (!dbb) cout << "NO" << endl;

    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        grau[i] = 0;
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
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
