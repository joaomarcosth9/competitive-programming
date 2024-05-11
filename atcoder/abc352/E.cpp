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
    int number_of_sets;
    DSU(int n = 0) : par(n), sz(n, 1), number_of_sets(n) {
        iota(par.begin(), par.end(), 0);
    }
    int find(int a) { return a == par[a] ? a : par[a] = find(par[a]); }
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) {
            return false;
        }
        number_of_sets--;
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        par[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

void solve() {
    int n, q; cin >> n >> q;
    DSU d(n + 1);

    vector<tuple<int, int, vector<int>>> qq;

    for (int i = 0; i < q; i++) {
        int k, c; cin >> k >> c;
        vector<int> aa(k);
        for (int j = 0; j < k; j++) cin >> aa[j];
        sort(aa.begin(), aa.end());
        qq.emplace_back(c, k, aa);
    }
    sort(qq.begin(), qq.end(), [&] (auto &l, auto &r) {
        return get<0>(l) < get<0>(r);
    });

    ll res = 0;
    for (auto [c, k, aa] : qq) {
        for (int i = 1; i < k; i++) {
            if (d.unite(aa[i], aa[i - 1])) {
                res += c;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (d.unite(1, i)) {
            cout << -1 << endl;
            return;
        }
    }
    cout << res << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
