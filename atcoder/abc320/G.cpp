#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define cerr                                                                                                           \
    if (false) cerr
#endif
#define endl '\n'
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto &x) { return res; }
#define L2(res...) [&](const auto &x, const auto &y) { return res; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int ll
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;
void out(bool ans) { cout << (ans ? "YES" : "NO") << endl; }

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

/*
int main() {
    int n, m;
    cin >> n >> m;
    Dinic F(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        F.add_edge(u, v, w);
    }
    cout << F.max_flow(1, n) << '\n';
    return 0;
}
*/

void solve() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<string> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++)
        for (auto &c : a[i]) c -= '0';

    ll best = LLONG_MAX;

    for (int i = 0; i <= 9; i++) {
        int find = 0;
        vector<vector<int>> res(n);

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m && (int)res[j].size() <= n; k++) {
                if (a[j][k] == i) res[j].eb(k);
            }
            find += res[j].size() > 0;
        }

        if (find < n) continue;

        for (int j = 0; j < n; j++) {
            int o = res[j].size();
            while ((int)res[j].size() < n) {
                int S = res[j].size();
                for (int k = S - o; k < S; k++) res[j].eb(res[j][k] + m);
            }
        }

        map<int, ii> compr;

        for (int j = 0; j < n; j++)
            for (auto &x : res[j]) compr[x] = {1, x};
        int IT = n + 2;

        for (auto &[k, v] : compr) {
            v.first = IT++;
        }

        vector<vector<ii>> res2(n);
        for (int j = 0; j < n; j++) {
            res2[j].resize(res[j].size());
            for (int k = 0; k < (int)res[j].size(); k++) {
                res2[j][k] = compr[res[j][k]];
            }
        }

        ll l = 0, r = (n <= m ? m + 1 : n);

        ll ans = LLONG_MAX;

        while (l <= r) {
            ll mid = (l + r) / 2;
            int N = n + mid + 100;
            Dinic d(N + 5);

            for (int j = 0; j < n; j++) d.add_edge(0, j + 1, 1);
            for (int j = n + 2; j <= (n + 1) + mid; j++) d.add_edge(j, N + 1, 1);

            ll maxu = 0;
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < (int)res[j].size(); k++) {
                    auto [id, val] = res2[j][k];
                    if (id <= (n + 1) + mid) {
                        d.add_edge(j + 1, id, 1);
                        maxu = max(maxu, val);
                    } else
                        break;
                }
            }
            ll test = d.max_flow(0, N + 1);
            if (test == n) {
                ans = maxu;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        debug(i);
        debug(ans);

        // n nodes on the left
        // edge between u and v if res[u] contains v
        // [val] nodes on the right

        best = min(best, ans);
    }
    cout << (best == LLONG_MAX ? -1 : best) << endl;
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
            /* cout << solve() << endl; */
            /* cout << (solve() ? "YES" : "NO") << endl; */
            ++TEST;
        }
    } else
        solve();
}
