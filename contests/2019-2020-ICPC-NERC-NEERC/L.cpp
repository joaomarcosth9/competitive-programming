#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 4e5 + 5;
const int S = 2 * N;

array<int, 26> go[S];
int len[S], lnk[S], val[S], last = 1, id = 2;

void insert(int idx, char ch) {
    int c = (int)(ch - 'a');
    int cur = id++;
    len[cur] = len[last] + 1;
    val[cur] = idx;
    int p = last;
    while (p > 0 && go[p][c] == 0) {
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
            val[clone] = -1;
            len[clone] = len[p] + 1;
            lnk[clone] = lnk[s];
            go[clone] = go[s];
            while (p > 0 && go[p][c] == s) {
                go[p][c] = clone;
                p = lnk[p];
            }
            lnk[s] = lnk[cur] = clone;
        }
    }
    last = cur;
}

vector<int> adj[S];

pair<int, int> res = {1, 1};

pair<int, int> best(pair<int, int> a, pair<int, int> b) {
    if ((ll)a.first * b.second > (ll)b.first * a.second)
        return a;
    return b;
}

set<int> vals[S];
int res_[S];

void dfs(int u) {
    vals[u] = {val[u]};
    if (adj[u].empty()) {
        res_[u] = 1e9;
        return;
    }

    int sz = -1, who = -1;
    for (int v : adj[u]) {
        dfs(v);
        if ((int)vals[v].size() > sz) {
            sz = (int)vals[v].size();
            who = v;
        }
    }

    if (u == 1) {
        return;
    }

    debug(u, vals[u]);
    for (int v : adj[u]) {
        if (who == v) {
            debug("swp", vals[u], vals[v], u, v);
            swap(vals[u], vals[v]);
            res_[u] = res_[v];
            break;
        }
    }
    debug(u, vals[u]);

    for (int v : adj[u]) {
        debug(v, vals[v]);
        for (int x : vals[v]) {
            if (x == -1)
                continue;
            int nxt = 1e9, prv = 1e9;
            if (vals[u].lower_bound(x) != vals[u].end()) {
                nxt = *vals[u].lower_bound(x) - x;
            }
            if (vals[u].upper_bound(x) != vals[u].begin()) {
                prv = x - *(--vals[u].upper_bound(x));
            }
            vals[u].insert(x);
            assert(nxt > 0 && prv > 0);
            res_[u] = min(res_[u], min(nxt, prv));
        }
    }

    pair<int, int> now = {res_[u] + len[u], res_[u]};

    res = best(res, now);
}

void solve() {
    string s; cin >> s;
    int n = (int)s.size();
    for (int i = n - 1; i >= 0; i--) {
        insert(i, s[i]);
    }
    for (int i = 2; i < id; i++) {
        adj[lnk[i]].push_back(i);
    }
    dfs(1);

    int g = gcd(res.first, res.second);
    res.first /= g;
    res.second /= g;

    cout << res.first / res.second << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
