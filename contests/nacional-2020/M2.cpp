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

int ch[maxn][26], pr[maxn], trie_cnt, sam_node[maxn], trie_node[maxn];
int sam_time = 0;
int need[maxn];

long long ans[maxn];

int len[maxn], lnk[maxn], go[maxn][26], sam_cnt;

int add_char(int x, int c) {
	if (!ch[x][c])
		pr[ch[x][c] = ++trie_cnt] = x;
	
	return ch[x][c];
}

void print_sam() {
#ifndef LOCAL_DEBUG
    return;
#endif
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
                printf("%d -> %c  ", go[i][c], char(c + 'A'));
        puts("");
    }
    for (int i = 0; i <= 10; i++) {
        printf("--");
    }
    printf("\n");
}

int extend(int p, int c, int tn) {
	int np = ++sam_cnt;
	len[np] = len[p] + 1;
    trie_node[np] = tn;
    need[np] = 1;

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
            need[nq] = 2;
			len[nq] = len[p] + 1;
            trie_node[nq] = trie_node[q];
			memcpy(go[nq], go[q], sizeof(go[q]));

			lnk[nq] = lnk[q];
			lnk[np] = lnk[q] = nq;

			while (p && go[p][c] == q) {
				go[p][c] = nq;
				p = lnk[p];
			}
		}
	}

	return np;
}

void bfs() {
	queue<int> q;

	q.push(1);
	sam_node[1] = trie_node[1] = sam_cnt = 1;

	while (!q.empty()) {
		int x = q.front();

		q.pop();

		for (int c = 0; c < 26; c++)
			if (ch[x][c]) {
				sam_node[ch[x][c]] = extend(sam_node[x], c, ch[x][c]);
				q.push(ch[x][c]);
			}
	}
}

vector<int> G[maxn];
int tin[maxn], tout[maxn], tim;
int f[25][maxn];

bool anc(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

void dfs_trie(int x) {
	tin[x] = ++tim;

    for (int c = 0; c < 26; c++) {
        if (ch[x][c]) {
            dfs_trie(ch[x][c]);
        }
    }

    tout[x] = ++tim;
}

int get_link(int u) {
    return lnk[u];
}

int vis[maxn], add[maxn];

int TIME = 0;

string curr;

void dfs(int x) {
	ans[x] = ans[pr[x]];

	int u = sam_node[x];

    ++TIME;

    int real_lnk = get_link(u);

    debug(x, u, curr, len[u], real_lnk, len[real_lnk], TIME);

    vis[real_lnk]++;

    if (vis[real_lnk] >= need[real_lnk]) {
        add[real_lnk] = len[real_lnk] - len[get_link(real_lnk)];
        ans[x] += add[real_lnk];
    }

    debug(x, u, ans[x]);

    for (int c = 0; c < 26; c++) {
        if (ch[x][c]) {
            curr.push_back((char)(c + 'A'));
            dfs(ch[x][c]);
            curr.pop_back();
        }
    }

    vis[real_lnk]--;
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

	dfs_trie(1);

	for (int i = 2; i <= sam_cnt; i++)
		G[lnk[i]].push_back(i);

    lnk[1] = 1;
	for (int i = 1; i <= sam_cnt; i++) {
		f[0][i] = lnk[i];
    }
	
	for (int j = 1; j <= 20; j++)
		for (int i = 1; i <= sam_cnt; i++)
			f[j][i] = f[j - 1][f[j - 1][i]];

    print_sam();

	dfs(1);

	for (int k : v)
		printf("%lld\n", ans[k]);

	return 0;
}
