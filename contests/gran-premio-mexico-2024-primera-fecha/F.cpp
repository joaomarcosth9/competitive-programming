#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 8e5 + 5, S = 2 * N;

struct SA {
    array<int, 28> go[S];
    int id = 2, last = 1, clk = 0;
    int lnk[S], idx[S], len[S], sa[N];
    bool is_clone[S];
    int it_sa = 0, n;
    vector<int> adj[S];
    ll res = 0;
    string s;
    void push(int idx_, char ch) {
        int c = ch - '`';
        int cur = id++;
        len[cur] = len[last] + 1;
        idx[cur] = idx_;
        int p = last;
        while (p > 0 && !go[p][c]) {
            go[p][c] = cur;
            p = lnk[p];
        }
        if (p == 0) {
            lnk[cur] = 1;
        } else {
            int s = go[p][c];
            if (len[s] == len[p] + 1) { 
                lnk[cur] = s;
            } else {
                int clone = id++;
                len[clone] = len[p] + 1;
                is_clone[clone] = 1;
                idx[clone] = idx[s];
                lnk[clone] = lnk[s];
                go[clone] = go[s];
                while (p > 0 && go[p][c] == s) {
                    go[p][c] = clone;
                    p = lnk[p];
                }
                lnk[cur] = lnk[s] = clone;
            }
        }
        last = cur;
    }
    bool is_s(int i) {
        int t_size = (n / 2) / 2;
        return i >= 0 && i < t_size;
    }
    bool is_t(int i) {
        int t_size = (n / 2) / 2;
        int first_t = (n / 2) + 1;
        return i >= first_t && i < first_t + t_size;
    }
    int back = 0;
    void dfs(int u, int p) {
        ranges::sort(adj[u], [&] (int v1, int v2) {
            return s[idx[v1] + len[u]] > s[idx[v2] + len[u]];
        });
        if (!is_clone[u]) {
            if (is_t(idx[u])) {
                back++;
            }
            if (is_s(idx[u])) {
                res += back;
            }
        }
        for (int v : adj[u]) {
            dfs(v, u);
        }
    }
    void build(string t) {
        memset(idx, -1, sizeof idx);
        s = t;
        n = (int)s.size();
        for (int i = n - 1; i >= 0; i--) {
            push(i, s[i]);
        }
        for (int i = 2; i < id; i++) {
            adj[lnk[i]].push_back(i);
        }
        dfs(1, 1);
    }
} sa;

int n;
string s, t;

void solve() {
    cin >> n >> s >> t;

    s += s;
    t += t;

    string S = s + "`" + t + "{";

    sa.build(S);

    cout << sa.res << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
