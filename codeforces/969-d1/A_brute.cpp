#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

vector<int> L;

pair<int, vector<pair<int, int>>> brute(string nodes, int turn) {
    if (count(nodes.begin(), nodes.end(), '?') == 0) {
        int res = 0;
        int root = nodes[0];
        for (int i : L) {
            if (nodes[i] != root) res++;
        }
        return {res, {}};
    }
    int n = (int)nodes.size();
    pair<int, vector<pair<int, int>>> now = {turn == 0 ? INT_MIN : INT_MAX, {}};
    debug("escolhendo play", turn, nodes);
    pair<int, int> play_now = {-1, -1};
    string best_choice = nodes;
    for (int i = 0; i < n; i++) {
        if (nodes[i] == '?') {
            nodes[i] = '0';
            if (turn == 0) {
                auto [res, plays] = brute(nodes, turn ^ 1);
                if (res > now.first) {
                    now = {res, plays};
                    play_now = {i, 0};
                    best_choice = nodes;
                }
            } else {
                auto [res, plays] = brute(nodes, turn ^ 1);
                if (res < now.first) {
                    now = {res, plays};
                    play_now = {i, 0};
                    best_choice = nodes;
                }
            }
            nodes[i] = '1';
            if (turn == 0) {
                auto [res, plays] = brute(nodes, turn ^ 1);
                if (res > now.first) {
                    now = {res, plays};
                    play_now = {i, 1};
                    best_choice = nodes;
                }
            } else {
                auto [res, plays] = brute(nodes, turn ^ 1);
                if (res < now.first) {
                    now = {res, plays};
                    play_now = {i, 1};
                    best_choice = nodes;
                }
            }
            nodes[i] = '?';
        }
    }
    now.second.push_back(play_now);
    debug("retornando", now.first, now.second, best_choice);
    return now;
}

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

    vector<int> leaves;

    function<void(int, int)> dfs = [&] (int u, int p) {
        bool leaf = 1;
        for (int v : adj[u]) if (v != p) {
            leaf = 0;
            dfs(v, u);
        }
        if (leaf) {
            leaves.push_back(u);
        }
    };

    dfs(0, 0);

    L = leaves;

    auto [res2, plays] = brute(s, 0);

    cout << res2 << endl;

    reverse(plays.begin(), plays.end());

    for (auto [i, v] : plays) {
        cout << i + 1 << ' ' << v << endl;
    }

    if (s[0] != '?') {
        int res = 0;
        char oth = s[0] ^ '0' ^ '1';
        for (int v : leaves) {
            if (s[v] == oth) res++;
        }
        int turn = 1;
        for (int v : leaves) {
            if (s[v] == '?') {
                res += turn;
                turn ^= 1;
            }
        }
        cout << res << endl;
    } else {
        int res = 0;
        int qt0 = 0, qt1 = 0, qtq = 0;
        debug(0, s[0]);
        for (int v : leaves) {
            debug(v, s[v]);
            if (s[v] == '0') qt0++;
            else if (s[v] == '1') qt1++;
            else qtq++;
        }
        if (qt1 >= qt0) {
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
