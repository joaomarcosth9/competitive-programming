#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

const int N = 5001;
int n, a[N];
ll b[N];
ll min_dep[N];
vector<int> adj[N];

void dfs(int u) {
    if (adj[u].empty()) {
        b[u] = 1e18;
        return;
    }
    b[u] = -a[u];
    for (int v : adj[u]) {
        b[u] += a[v];
        dfs(v);
    }
}

vector<tuple<ll, ll, ll>> st;

void get_fixes(int u, int d = 0) {
    if (d > 0) {
        st.push_back({d, b[u], u});
    }
    for (int v : adj[u]) {
        get_fixes(v, d + 1);
    }
}

ll res = 0;

void dfs_res(int u) {
    for (int v : adj[u]) {
        dfs_res(v);
    }
    debug(u, b[u]);
    if (b[u] < 0) {
        st.clear();
        get_fixes(u);
        sort(st.begin(), st.end());
        for (int i = 0; i < (int)st.size(); i++) {
            auto &[cost, val, who] = st[i];
            if (val >= abs(b[u])) {
                res += cost * abs(b[u]);
                b[who] -= abs(b[u]);
                b[u] = 0;
                break;
            } else {
                b[u] += val;
                b[who] = 0;
                res += cost * val;
            }
        }
    }
    debug(u, b[u]);
}

void print() {
    cout << "=== TREE ===" << endl;
    for (int i = 0; i < n; i++) {
        for (auto j : adj[i]) {
            cout << "(" << i << "," << a[i] << ") (" << j << "," << a[j] << ")" << endl;
        }
    }
    cout << "============" << endl;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    res = 0;
    for (int i = 1; i < n; i++) {
        int p; cin >> p;
        p--;
        adj[p].push_back(i);
    }
    //print();
    dfs(0);
    dfs_res(0);
    cout << res << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
        for (int i = 0; i < n; i++) {
            adj[i].clear();
            b[i] = a[i] = 0;
        }
    }
}

