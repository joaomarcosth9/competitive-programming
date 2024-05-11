#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

struct AC {
    const int K = 26;
    const char norm = 'a';
    inline int get(int c) { return c - norm; }

    vector<int> link, out_link, par;
    vector<char> pch;
    vector<vector<int>> next;
    vector<bool> out;
    vector<vector<int>> output;

    AC() { node(); link[0] = 0; }

    int node(int p = -1, char c = -1) {
        link.emplace_back(-1);
        out_link.emplace_back(-1);
        par.emplace_back(p);
        pch.emplace_back(c);
        next.emplace_back(K, -1);
        out.emplace_back(0);
        output.emplace_back();
        return (int)link.size() - 1;
    }

    int T = 0;

    int insert(const string &s) {
        int u = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            auto v = next[u][get(s[i])];
            if (v == -1) {
                next[u][get(s[i])] = v = node(u, s[i]);
            }
            u = v;
        }
        out[u] = true;
        output[u].emplace_back(T);
        return T++;
    }

    int get_link(int u) {
        if (link[u] == -1) {
            link[u] = par[u] ? go(get_link(par[u]), pch[u]) : 0;
        }
        return link[u];
    }

    int go(int u, char c) {
        if (next[u][get(c)] == -1) {
            next[u][get(c)] = u ? go(get_link(u), c) : 0;
        }
        return next[u][get(c)];
    }

    int exit(int u) {
        if (out_link[u] == -1) {
            int v = get_link(u);
            out_link[u] = (out[v] || !v) ? v : exit(v);
        }
        return out_link[u];
    }
} aho;

void solve() {
    int n; 
    string s;
    cin >> n >> s;
    int m = (int)aho.link.size();
    const int INF = 2e9;
    vector<vector<int>> dp(n + 1, vector<int> (m, INF));
    dp[0][0] = 0b000;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            int k = aho.go(j, s[i]);
            if (aho.exit(k) != 0 || aho.out[k]) continue;
            dp[i + 1][k] = min(dp[i + 1][k], dp[i][j]);
        }
    }
    int ans = 1e9;
    for (int j = 0; j < m; j++) {
        if (aho.exit(j) != 0 || aho.out[j]) continue;
        ans = min(ans, dp[n][j]);
    }
    cout << ans << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    aho.insert("pie");
    aho.insert("map");
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
