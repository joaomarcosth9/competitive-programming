#include <bits/stdc++.h>

using namespace std;

const int MAX = 3e5 + 5;
const long long INF = 1e18 + 5;

struct edge {
    long long a, b;
};

int res[MAX];
vector<pair<int, edge>> Adj[MAX];
vector<long long> pref_a, pref_b;

void check(int u) {
    long long pfa = pref_a.back();
    pref_b.push_back(INF);
    int l = 0, r = (int)pref_b.size() - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (pref_b[mid] <= pfa) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    res[u] = l - 1;
    pref_b.pop_back();
}

void dfs(int u) {
    if (u) {
        check(u);
    }
    for (auto [v, edge] : Adj[u]) {
        pref_a.push_back(pref_a.back() + edge.a);
        pref_b.push_back(pref_b.back() + edge.b);
        dfs(v);
        pref_a.pop_back();
        pref_b.pop_back();
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int p, a, b;
        cin >> p >> a >> b;
        p--;
        Adj[p].emplace_back(i, edge{a, b});
    }
    dfs(0);
    for (int i = 0; i < n; i++) {
        Adj[i].clear();
    }
    for (int i = 1; i < n; i++) {
        cout << res[i] << " \n"[i == n - 1];
    }
}

signed main() {
    pref_a.push_back(0LL);
    pref_b.push_back(0LL);
#ifdef SUBLIME
    freopen("/tmp/input.txt", "r", stdin);
    freopen("/tmp/output.txt", "w", stdout);
#endif
#ifndef LOCAL_DEBUG
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
