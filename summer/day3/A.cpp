#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef pair<int, int> ii;
int testcases = 0;
const int INF = 1.05e9;
const ll INFLL = 4.5e18;
#define endl '\n'
#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#define dbarr(x...)
#endif

typedef tuple<ll, ll, ll> i3;

struct DSU {
    vector<ll> pa, sz;
    DSU(int n) {
        sz.assign(n + 5, 1);
        for (int i = 0; i < n + 5; i++) pa.push_back(i);
    }
    int find(int a) { return pa[a] = (a == pa[a] ? a : find(pa[a])); }
    bool sameSet(int a, int b) { return find(a) == find(b); }
    void unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return;
        if (sz[ra] > sz[rb]) swap(ra, rb);
        pa[ra] = rb;
        sz[rb] += sz[ra];
    }
};

vector<ll> arr;
vector<i3> edges;

void solve() {
    ll n, m;
    cin >> n >> m;
    arr.assign(n + 1, 0);
    DSU dsu(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v;
        if (u > v) swap(u, v);
        w = min(arr[u], arr[v]);
        edges.emplace_back(u, v, w);
    }
    auto comp = [](i3 &t1, i3 &t2) { return get<2>(t1) > get<2>(t2); };
    sort(edges.begin(), edges.end(), comp);
    long double res = 0;
    for (auto edge : edges) {
        auto [u, v, w] = edge;
        int ru = dsu.find(u), rv = dsu.find(v);
        db(w);
        if (ru == rv) continue;
        res += w * (dsu.sz[ru] * dsu.sz[rv]);
        db(res);
        dsu.unite(u, v);
    }
    res /= (n * (n - 1)) >> 1;
    cout << setprecision(6) << fixed;
    cout << res << endl;
}

signed main() {
#ifndef LOCAL_DEBUG
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tsts = 1;
    if (testcases) cin >> tsts;
    while (tsts--) solve();
    return 0;
}
