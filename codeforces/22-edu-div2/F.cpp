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

struct dsu {
    vector<int> id, sz, c;

    vector<vector<pair<int&, int>>> st;

    void build(int n) {
        id = c = vector<int> (n, 0);
        sz = vector<int> (n, 1);
        iota(all(id), 0);
    }

    int find(int a) { return a == id[a] ? a : find(id[a]); }
    int color(int a) { return a == id[a] ? c[a] : c[a] ^ color(id[a]); }

    void save(int &x) { st.back().eb(x, x); }

    void rollback() {
        while (st.back().size()) {
            auto [var, val] = st.back().back();
            debug(var, val);
            var = val;
            st.back().pop_back();
        }
        st.pop_back();
    }

    void unite(int a, int b) {
        st.eb();
        bool change = color(a) == color(b);
        a = find(a), b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        save(c[b]);
        save(sz[a]);
        save(id[b]);
        if (change) c[b] = 1;
        sz[a] += sz[b];
        id[b] = a;
    }
};

const int maxn = 1e5 + 5;
set<pair<int, int>> seg[4 * maxn];
int res[maxn * 2];
dsu d;

void update(int L, int R, pair<int, int> edge, int n = 1, int l = 1, int r = maxn) {
    if (l > R || r < L) return;
    if (l >= L && r <= R) {
        seg[n].emplace(edge);
        return;
    }
    int mid = (l + r) / 2;
    update(L, R, edge, n << 1, l, mid);
    update(L, R, edge, n << 1 | 1, mid + 1, r);
}

void dfs(int n, int l, int r, bool db) {
    for (auto [u, v] : seg[n]) {
        if (d.find(u) == d.find(v)) {
            db &= d.color(u) != d.color(v);
        }
        d.unite(u, v);
    }
    if (l == r) {
        res[l] = db;
    } else {
        int mid = (l + r) / 2;
        dfs(n << 1, l, mid, db);
        dfs(n << 1 | 1, mid + 1, r, db);
    }
    for (int i = 0; i < (int)seg[n].size(); i++) d.rollback();
}

void solve() {
    int n, q; cin >> n >> q;

    d.build(n);

    vector<map<int, int>> has(n);
    int time = 1;

    for (int i = 0; i < q; i++) {
        int u, v; cin >> u >> v;
        u--; v--;

        if (has[u][v] == 0) {
            has[u][v] = time;
        } else {
            update(has[u][v], time - 1, {u, v});
            has[u].erase(v);
        }
        
        time++;
    }

    for (int i = 0; i < n; i++) {
        for (auto [k, v] : has[i]) {
            assert(i < k);
            update(v, time, {i, k});
        }
    }

    dfs(1, 1, maxn, 1);
    
    for (int i = 1; i <= q; i++) {
        cout << (res[i] ? "YES" : "NO") << endl;
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
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
