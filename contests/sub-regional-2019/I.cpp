#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

const long long maxn = 405, INF = 1e18;
int n, m;
pair<int, int> temps[maxn];
tuple<int, int, int> edges[80000];
long long dcold[maxn][maxn], dhot[maxn][maxn];
long long comprcold[maxn], comprhot[maxn], cold[maxn], hot[maxn];
vector<tuple<int, int, int>> queryhot[maxn], querycold[maxn];
long long res[100005];

void floyd_warshall() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dcold[i][k] < INF && dcold[k][j] < INF) {
                    dcold[i][j] = min(dcold[i][j], dcold[i][k] + dcold[k][j]);
                }
                if (dhot[i][k] < INF && dhot[k][j] < INF) {
                    dhot[i][j] = min(dhot[i][j], dhot[i][k] + dhot[k][j]);
                }
            }
        }
        for (auto [u, v, i] : querycold[cold[k]]) {
            res[i] = dcold[u][v];
        }
        for (auto [u, v, i] : queryhot[hot[k]]) {
            res[i] = dhot[u][v];
        }
    }
}

void solve() {
    /* cin >> n >> m; */
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        long long a;
        scanf("%lld", &a);
        /* cin >> a; */
        temps[i] = {a, i};
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        /* cin >> u >> v >> w; */
        scanf("%d %d %lld", &u, &v, &w);
        u--, v--;
        edges[i] = {w, u, v};
    }

    sort(temps, temps + n);

    for (int i = 0; i < n; i++) {
        comprcold[temps[i].second] = i;
    }
    cold[0] = 0;
    for (int i = 1; i < n; i++) {
        if (temps[i].first == temps[i - 1].first)
            cold[i] = cold[i - 1];
        else
            cold[i] = cold[i - 1] + 1;
    }

    reverse(temps, temps + n);
    for (int i = 0; i < n; i++) {
        comprhot[temps[i].second] = i;
    }
    hot[0] = 0;
    for (int i = 1; i < n; i++) {
        if (temps[i].first == temps[i - 1].first)
            hot[i] = hot[i - 1];
        else
            hot[i] = hot[i - 1] + 1;
    }

    int maxk = hot[n - 1];

    for (int i = 0; i < n; i++) {
        dcold[i][i] = dhot[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        auto [w, u, v] = edges[i];
        u = comprcold[u], v = comprcold[v];
        dcold[u][v] = dcold[v][u] = w;
    }
    for (int i = 0; i < m; i++) {
        auto [w, u, v] = edges[i];
        u = comprhot[u], v = comprhot[v];
        dhot[u][v] = dhot[v][u] = w;
    }

    int q;
    /* cin >> q; */
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int u, v, k, t;
        /* cin >> u >> v >> k >> t; */
        scanf("%d %d %d %d", &u, &v, &k, &t);
        u--, v--, k--;
        k = min(k, maxk);
        if (t) {
            u = comprhot[u], v = comprhot[v];
            queryhot[k].emplace_back(u, v, i);
        } else {
            u = comprcold[u], v = comprcold[v];
            querycold[k].emplace_back(u, v, i);
        }
    }

    floyd_warshall();

    for (int i = 0; i < q; i++) {
        printf("%lld\n", (res[i] < INF ? res[i] : -1));
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(res, 0x3f, sizeof(res));
    memset(dcold, 0x3f, sizeof(dcold));
    memset(dhot, 0x3f, sizeof(dhot));
    solve();
    return 0;
}
