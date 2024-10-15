#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

struct DSU {
    vector<int> par, sz;
    int num_sets;
    void build(int n) {
        par.assign(n, 0);
        iota(par.begin(), par.end(), 0);
        sz.assign(n, 1);
        num_sets = n;
    }
    int find(int a) { return a == par[a] ? a : par[a] = find(par[a]); }
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        num_sets--;
        par[b] = a;
        sz[a] += sz[b];
        return true;
    }
} dsu;

vector<vector<vector<int>>> d(11);
vector<vector<vector<pair<int, int>>>> queries(11);

void solve() {
    int n, m;
    cin >> n >> m;

    for (auto &u : d) {
        for (auto &v : u) v.clear();
    }

    for (auto &u : queries) {
        for (auto &v : u) v.clear();
    }

    for (int i = 0; i < n; i++) {
        for (int mod = 1; mod <= 10; mod++) {
            int mi = i % mod;
            d[mod][mi].push_back(i);
        }
    }

    for (int i = 0; i < m; i++) {
        int a, mod, k;
        cin >> a >> mod >> k;
        a--;

        int l = a, r = a + k * mod;
        int level = a % mod;

        queries[mod][level].push_back({l, r});
    }

    dsu.build(n);

    for (int mod = 1; mod <= 10; mod++) {
        for (int level = 0; level < mod; level++) {
            auto &v = d[mod][level];
            auto &q = queries[mod][level];
            sort(q.begin(), q.end());

            int ptr = 0, max_r = -1, cur_l = -1;

            for (int i = 0; i < (int)v.size(); i++) {
                if (ptr < (int)q.size()) {
                    auto [nl, nr] = q[ptr];
                    if (nl == v[i]) cur_l = nl, max_r = nr, ptr++;
                }
                while (ptr < (int)q.size()) {
                    auto [nl, nr] = q[ptr];
                    if (nl <= max_r) max_r = max(max_r, nr), ptr++;
                    else break;
                }
                if (cur_l <= v[i] && v[i] <= max_r) dsu.unite(v[i], cur_l);
                if (max_r == v[i]) max_r = -1, cur_l = -1;
            }
        }
    }

    cout << dsu.num_sets << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int mod = 1; mod <= 10; mod++) {
        d[mod].resize(mod);
        queries[mod].resize(mod);
    }

    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}