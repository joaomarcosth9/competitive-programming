#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int MAX_N = 2e5 + 5;

const int S = MAX_N * 2;

struct SA {
    array<int, 27> go[S];
    int id = 2, last = 1, lnk[S], len[S], endpos[S], idx[S], where[S];
    SA() {
        memset(idx, -1, sizeof idx);
    }
    void push(int idx_, char ch) {
        int c = (int)(ch - 'A');
        int cur = id++;
        len[cur] = len[last] + 1;
        endpos[cur] = 1;
        where[idx_] = cur;
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
                idx[clone] = idx[s];
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

    string t;
    vector<int> adj[S];
    int up[S][20];

    void dfs(int u, int p = -1) {
        if (p == -1) p = u;
        up[u][0] = p;
        up[u][1] = up[up[u][0]][0];
        up[u][2] = up[up[u][1]][1];
        up[u][3] = up[up[u][2]][2];
        up[u][4] = up[up[u][3]][3];
        up[u][5] = up[up[u][4]][4];
        up[u][6] = up[up[u][5]][5];
        up[u][7] = up[up[u][6]][6];
        up[u][8] = up[up[u][7]][7];
        up[u][9] = up[up[u][8]][8];
        up[u][10] = up[up[u][9]][9];
        up[u][11] = up[up[u][10]][10];
        up[u][12] = up[up[u][11]][11];
        up[u][13] = up[up[u][12]][12];
        up[u][14] = up[up[u][13]][13];
        up[u][15] = up[up[u][14]][14];
        up[u][16] = up[up[u][15]][15];
        up[u][17] = up[up[u][16]][16];
        up[u][18] = up[up[u][17]][17];
        up[u][19] = up[up[u][18]][18];

        for (int v : adj[u]) {
            dfs(v, u);
            endpos[u] += endpos[v];
        }
    }

    void set_string(string _t) {
        t = _t;
        int n = (int)t.size();
        for (int i = n - 1; i >= 0; i--) {
            push(i, t[i]);
        }
        for (int i = 2; i < id; i++) {
            adj[lnk[i]].push_back(i);
        }
        dfs(1);
    }

    int count(int l, int r) {
        int u = where[l], min_len = (r - l + 1);

        // nodo mais alto tal que len[u] >= m_len

        if (len[up[u][19]] >= min_len) {
            u = up[u][19];
        }
        if (len[up[u][18]] >= min_len) {
            u = up[u][18];
        }
        if (len[up[u][17]] >= min_len) {
            u = up[u][17];
        }
        if (len[up[u][16]] >= min_len) {
            u = up[u][16];
        }
        if (len[up[u][15]] >= min_len) {
            u = up[u][15];
        }
        if (len[up[u][14]] >= min_len) {
            u = up[u][14];
        }
        if (len[up[u][13]] >= min_len) {
            u = up[u][13];
        }
        if (len[up[u][12]] >= min_len) {
            u = up[u][12];
        }
        if (len[up[u][11]] >= min_len) {
            u = up[u][11];
        }
        if (len[up[u][10]] >= min_len) {
            u = up[u][10];
        }
        if (len[up[u][9]] >= min_len) {
            u = up[u][9];
        }
        if (len[up[u][8]] >= min_len) {
            u = up[u][8];
        }
        if (len[up[u][7]] >= min_len) {
            u = up[u][7];
        }
        if (len[up[u][6]] >= min_len) {
            u = up[u][6];
        }
        if (len[up[u][5]] >= min_len) {
            u = up[u][5];
        }
        if (len[up[u][4]] >= min_len) {
            u = up[u][4];
        }
        if (len[up[u][3]] >= min_len) {
            u = up[u][3];
        }
        if (len[up[u][2]] >= min_len) {
            u = up[u][2];
        }
        if (len[up[u][1]] >= min_len) {
            u = up[u][1];
        }
        if (len[up[u][0]] >= min_len) {
            u = up[u][0];
        }

        return endpos[u];
    }

} sa1, sa2;

int n, m;
string s, t;

string sep = string(1, 'Z' + 1);

void solve() {
    cin >> n >> m;
    cin >> s >> t;

    s = s + sep + t;

    sa1.set_string(s);
    sa2.set_string(t);

    int q; cin >> q;

    while (q--) {
        int l, r; cin >> l >> r;
        l--; r--;
        cout << sa1.count(l + n + 1, r + n + 1) - sa2.count(l, r) << endl;
    }

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}
