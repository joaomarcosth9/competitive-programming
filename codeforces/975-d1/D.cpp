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
    vector<int> par, sz, on, has_mx_even, has_mx_odd, a, lmost, good_mx;
    int mx, s, qt_good_maximum;
    void build(const vector<int> &b) {
        a = b;
        int n = (int)a.size();
        mx = *max_element(a.begin(), a.end());
        par.assign(n, 0);
        on.assign(n, 0);
        has_mx_even.assign(n, 0);
        has_mx_odd.assign(n, 0);
        lmost.assign(n, 0);
        good_mx.assign(n, 0);
        iota(lmost.begin(), lmost.end(), 0);
        iota(par.begin(), par.end(), 0);
        sz.assign(n, 1);
        qt_good_maximum = s = 0;
    }
    int find(int u) { return u == par[u] ? u : par[u] = find(par[u]); }
    bool is_on(int u) { return u == par[u] ? on[u] : on[u] = is_on(par[u]); }
    void activate(int i) {
        if (a[i] == mx && (i % 2) == 0) has_mx_even[i] = 1;
        if (a[i] == mx && (i % 2) == 1) has_mx_odd[i] = 1;
        if (a[i] == mx) good_mx[i] = 1, qt_good_maximum++;
        on[i] = 1;
        s += (sz[i] + 1) / 2;
        if (i > 0 && is_on(i - 1)) unite(i, i - 1);
        if (i < (int)par.size() - 1 && is_on(i + 1)) unite(i, i + 1);
    }
    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        if (good_mx[u]) good_mx[u] = 0, qt_good_maximum--;
        if (good_mx[v]) good_mx[v] = 0, qt_good_maximum--;
        s -= (sz[u] + 1) / 2;
        s -= (sz[v] + 1) / 2;
        par[v] = u;
        sz[u] += sz[v];
        s += (sz[u] + 1) / 2;
        lmost[u] = min(lmost[u], lmost[v]);
        has_mx_even[u] |= has_mx_even[v];
        has_mx_odd[u] |= has_mx_odd[v];
        if (sz[u] % 2 == 0 && (has_mx_even[u] || has_mx_odd[u])) good_mx[u] = 1, qt_good_maximum++;
        else if (lmost[u] % 2 == 1 && has_mx_odd[u]) good_mx[u] = 1, qt_good_maximum++;
        else if (lmost[u] % 2 == 0 && has_mx_even[u]) good_mx[u] = 1, qt_good_maximum++;
        return true;
    }
    int sum() {
        return s - (qt_good_maximum == 0);
    }
};

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);

    for (int &i : a) {
        cin >> i;
    }

    DSU d;
    d.build(a);

    map<int, vector<int>, greater<int>> mpos;

    int mx = *max_element(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        mpos[a[i]].push_back(i);
    }

    int ans = 0;

    for (auto [mn, pos] : mpos) {
        for (auto i : pos) {
            d.activate(i);
        }
        ans = max(ans, mx + mn + d.sum());
    }

    cout << ans << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}
