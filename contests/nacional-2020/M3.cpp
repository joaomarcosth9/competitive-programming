#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

constexpr int maxn = 400005;

int ch[maxn][26], pr[maxn], trie_cnt, sam_node[maxn];

long long ans[maxn];

int len[maxn], lnk[maxn], go[maxn][26], sam_cnt;

int add_char(int x, int c) {
    if (!ch[x][c])
        pr[ch[x][c] = ++trie_cnt] = x;

    return ch[x][c];
}

void print_sam() {
    return;
    for (int i = 0; i <= 4; i++) {
        printf("--");
    }
    printf(" SAM "); for (int i = 0; i <= 4; i++) {
        printf("--");
    }
    printf("\n");
    for (int i = 1; i <= sam_cnt; i++) {
        printf("node %d: lnk = %d  len = %d  ", i, lnk[i], len[i]);
        for (int c = 0; c < 26; c++)
            if (go[i][c])
                printf("%c -> %d  ", char(c + 'A'), go[i][c]);
        puts("");
    }
    for (int i = 0; i <= 10; i++) {
        printf("--");
    }
    printf("\n");
}

int extend(int p, int c) {
    int np = ++sam_cnt;
    len[np] = len[p] + 1;

    debug("extendendo", p, char(c + 'A'), np);

    while (p && !go[p][c]) {
        go[p][c] = np;
        p = lnk[p];
    }

    if (!p)
        lnk[np] = 1;
    else {
        int q = go[p][c];

        if (len[q] == len[p] + 1)
            lnk[np] = q;
        else {
            int nq = ++sam_cnt;
            len[nq] = len[p] + 1;
            memcpy(go[nq], go[q], sizeof(go[q]));

            lnk[nq] = lnk[q];
            lnk[np] = lnk[q] = nq;

            while (p && go[p][c] == q) {
                go[p][c] = nq;
                p = lnk[p];
            }
        }
    }

    print_sam();

    return np;
}

void bfs() {
    queue<int> q;

    q.push(1);
    sam_node[1] = sam_cnt = 1;

    while (!q.empty()) {
        int x = q.front();

        debug(x);

        q.pop();

        for (int c = 0; c < 26; c++)
            if (ch[x][c]) {
                debug(x, char(c + 'A'), ch[x][c]);
                sam_node[ch[x][c]] = extend(sam_node[x], c);
                q.push(ch[x][c]);
            }
    }
}

vector<int> G[maxn];
int dfn[maxn], tim;
int d[maxn], f[25][maxn];

void dfs_sam(int x) {
    d[x] = d[lnk[x]] + 1;
    dfn[x] = ++tim;

    for (int y : G[x])
        dfs_sam(y);
}

int lca(int x, int y) {
    if (d[x] != d[y]) {
        if (d[x] < d[y])
            swap(x, y);

        int t = d[x] - d[y];
        for (int i = 0; t; i++, t >>= 1)
            if (t & 1)
                x = f[i][x];
    }

    if (x == y)
        return x;

    for (int i = 20; ~i; i--)
        if (f[i][x] != f[i][y]) {
            x = f[i][x];
            y = f[i][y];
        }

    return f[0][x];
}

struct cmp {
    bool operator () (int x, int y) const {
        return dfn[x] < dfn[y];
    }
};

set<int, cmp> st, sp;

int vis[maxn];

void add(int o, long long &ans) {
    if (!vis[o]++) {
        int u = *--sp.lower_bound(o), v = *sp.upper_bound(o);
        if (v > sam_cnt)
            v = 0;

        ans += len[o];

        // printf("add(%d)  u = %d  v = %d\n", o, u, v);

        if (u && v)
            ans += len[lca(u, v)];
        if (u)
            ans -= len[lca(u, o)];
        if (v)
            ans -= len[lca(o, v)];

        sp.insert(o);
    }
}

void del(int o, long long &ans) {
    if (!--vis[o]) {
        int u = *--sp.lower_bound(o), v = *sp.upper_bound(o);
        if (v > sam_cnt)
            v = 0;

        ans -= len[o];

        // printf("del(%d)  u = %d  v = %d\n", o, u, v);

        if (u && v)
            ans -= len[lca(u, v)];
        if (u)
            ans += len[lca(u, o)];
        if (v)
            ans += len[lca(o, v)];

        // assert(sp.count(o));

        sp.erase(sp.find(o));
    }
}

void dfs(int x) {
    ans[x] = ans[pr[x]];

    int o = sam_node[x];

    int u = *--st.lower_bound(o), v = *st.upper_bound(o);

    if (v > sam_cnt)
        v = 0;

    // add(o, ans[x]);

    if (u && v)
        del(lca(u, v), ans[x]);
    if (u)
        add(lca(u, o), ans[x]);
    if (v)
        add(lca(o, v), ans[x]);

    st.insert(o);

    for (int c = 0; c < 26; c++)
        if (ch[x][c])
            dfs(ch[x][c]);

    u = *--st.lower_bound(o), v = *st.upper_bound(o);

    if (v > sam_cnt)
        v = 0;

    // add(o, ans[x]);

    if (u && v)
        add(lca(u, v), ans[0]);
    if (u)
        del(lca(u, o), ans[0]);
    if (v)
        del(lca(o, v), ans[0]);

    st.erase(o);
}

char s[maxn];

int main() {

    scanf("%s", s);

    int x = trie_cnt = 1;

    for (const char *c = s; *c; c++)
        x = add_char(x, *c - 'A');

    scanf("%s", s);

    vector<int> v;
    v.push_back(x);

    for (const char *c = s; *c; c++) {
        if (*c == '-')
            x = pr[x];
        else
            x = add_char(x, *c - 'A');

        v.push_back(x);
    }

    bfs();

    for (int i = 2; i <= sam_cnt; i++)
        G[lnk[i]].push_back(i);

    st.insert(0);
    st.insert(dfn[sam_cnt + 1] = sam_cnt + 1);
    sp.insert(0);
    sp.insert(sam_cnt + 1);

    dfs_sam(1);

    for (int i = 1; i <= sam_cnt; i++)
        f[0][i] = lnk[i];

    for (int j = 1; j <= 20; j++)
        for (int i = 1; i <= sam_cnt; i++)
            f[j][i] = f[j - 1][f[j - 1][i]];

    dfs(1);

    for (int x : v)
        printf("%lld\n", ans[x]);

    return 0;
}
