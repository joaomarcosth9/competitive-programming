#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    string s;
    cin >> s;

    vector<bool> leaf(n);

    function<void(int, int)> dfs = [&] (int u, int p) {
        leaf[u] = 1;
        for (int v : adj[u]) if (v != p) {
            leaf[u] = 0;
            dfs(v, u);
        }
    };

    dfs(0, 0);

    if (s[0] != '?') {
        int res = 0, turn = 1;
        char oth = s[0] ^ '0' ^ '1';
        for (int i = 0; i < n; i++) {
            if (leaf[i] && s[i] == oth) {
                res++;
            } else if (leaf[i] && s[i] == '?') {
                res += turn;
                turn ^= 1;
            }
        }
        cout << res << endl;
    } else {
        int res = 0, qt0 = 0, qt1 = 0, qtq = 0, oq = 0;
        for (int i = 1; i < n; i++) {
            if (leaf[i] && s[i] == '?') {
                qtq++;
            } else if (leaf[i] && s[i] == '1') {
                qt1++;
            } else if (leaf[i] && s[i] == '0') {
                qt0++;
            } else if (s[i] == '?') {
                oq++;
            }
        }
        if (qt1 == qt0) {
            res += qt1;
            if (qtq & 1 && oq & 1) {
                res += (qtq + 1) / 2;
            } else {
                res += qtq / 2;
            }
        } else if (qt1 > qt0) {
            res += qt1;
            res += qtq / 2;
        } else {
            res += qt0;
            res += qtq / 2;
        }
        cout << res << endl;
    }
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