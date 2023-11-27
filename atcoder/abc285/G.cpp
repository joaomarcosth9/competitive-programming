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

const long long inf = 1LL << 61;
struct Dinic {
    struct edge {
        int to, rev;
        long long flow, w;
        int id;
    };
    int n, s, t, mxid;
    vector<int> d, flow_through;
    vector<int> done;
    vector<vector<edge>> g;
    Dinic() {}
    Dinic(int _n) {
        n = _n + 10;
        mxid = 0;
        g.resize(n);
    }
    void add_edge(int u, int v, long long w, int id = -1) {
        edge a = {v, (int)g[v].size(), 0, w, id};
        edge b = {u, (int)g[u].size(), 0, 0, -2}; // for bidirectional edges cap(b) = w
        g[u].emplace_back(a);
        g[v].emplace_back(b);
        mxid = max(mxid, id);
    }
    bool bfs() {
        d.assign(n, -1);
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto &e : g[u]) {
                int v = e.to;
                if (d[v] == -1 && e.flow < e.w) d[v] = d[u] + 1, q.push(v);
            }
        }
        return d[t] != -1;
    }
    long long dfs(int u, long long flow) {
        if (u == t) return flow;
        for (int &i = done[u]; i < (int)g[u].size(); i++) {
            edge &e = g[u][i];
            if (e.w <= e.flow) continue;
            int v = e.to;
            if (d[v] == d[u] + 1) {
                long long nw = dfs(v, min(flow, e.w - e.flow));
                if (nw > 0) {
                    e.flow += nw;
                    g[v][e.rev].flow -= nw;
                    return nw;
                }
            }
        }
        return 0;
    }
    long long max_flow(int _s, int _t) {
        s = _s;
        t = _t;
        long long flow = 0;
        while (bfs()) {
            done.assign(n, 0);
            while (long long nw = dfs(s, inf)) flow += nw;
        }
        flow_through.assign(mxid + 10, 0);
        for (int i = 0; i < n; i++)
            for (auto e : g[i])
                if (e.id >= 0) flow_through[e.id] = e.flow;
        return flow;
    }
};

bool solve() {
    int n, m; cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int N = n * m + 10;

    Dinic d(3 * N + 10);

    int source = 0, sink = 1;

    auto nd = [&] (int i, int j) {
        int nodo = (i * m + j) + 10;
        return nodo;
    };
    auto valid = [&] (int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    };

    debug(source, sink);

    vector<ii> moves = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (a[i][j] != '1') {
            int side = (i + j) % 2;
            int me = nd(i, j);
            debug(i, j, me);

            if (side & 1) {
                d.add_edge(me, sink, 1);
            } else {
                d.add_edge(source, me, 1);
                for (auto [y, x] : moves) {
                    int ni = i + y, nj = j + x;
                    if (valid(ni, nj) && a[ni][nj] != '1') {
                        int nodo = nd(ni, nj);
                        if (a[i][j] == '2' || a[ni][nj] == '2') {
                            debug(me, nodo);
                            d.add_edge(me, nodo, 1);
                        }
                    }
                }
            }
        }
    }

    d.max_flow(source, sink);

    bool db = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (a[i][j] == '2') {
            int me = nd(i, j);
            bool has = 0;
            for (auto e : d.g[me]) has |= e.flow == 1;
            for (auto e : d.g[me]) debug(me, e.to, e.flow);
            db &= has;
        }
    }

    return db;

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        /* solve(); */
        /* cout << solve() << endl; */
        cout << (solve() ? "Yes" : "No") << endl;
        TEST += 1;
    }
}
