#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define endl '\n'
#define cerr                                                                   \
	if (false)                                                                 \
	cerr
#endif
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto &x) { return res; }
#define L2(res...) [&](const auto &x, const auto &y) { return res; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;
#define int ll
const int MAX = 1e5 + 5, INF = 2e9;

int n, a[MAX];
int mn[MAX], sz[MAX], nodomn[MAX];
vector<int> res;
vector<int> g[MAX], nodos[MAX];
vector<int> gi[MAX]; // grafo invertido
int vis[MAX], vis2[MAX], vis3[MAX];
stack<int> S;
int comp[MAX]; // componente conexo de cada vertice

void dfs(int k) {
	vis[k] = 1;
	for (int i = 0; i < (int)g[k].size(); i++)
		if (!vis[g[k][i]])
			dfs(g[k][i]);

	S.push(k);
}

void scc(int k, int c) {
	vis[k] = 1;
	sz[c] += 1;
	comp[k] = c;
	nodos[c].eb(k);
	if (a[k] < mn[c]) {
		nodomn[c] = k;
		mn[c] = a[k];
	}
	for (int i = 0; i < (int)gi[k].size(); i++)
		if (!vis[gi[k][i]])
			scc(gi[k][i], c);
}

void kosaraju() {
	for (int i = 0; i < n; i++)
		vis[i] = 0;
	for (int i = 0; i < n; i++)
		if (!vis[i])
			dfs(i);

	for (int i = 0; i < n; i++)
		vis[i] = 0;
	while (S.size()) {
		int u = S.top();
		S.pop();
		if (!vis[u]) {
			assert(mn[u] == INF);
			scc(u, u);
		}
	}
}

void dfs3(int u) {
	vis3[u] = 1;
	for (auto v : gi[u])
		if (!vis3[v] && comp[v] == comp[u]) {
			dfs3(v);
		}
	res.eb(u);
}

void process(int u) {
	vis[u] = 1;
	debug(nodos[u]);
	if (sz[u] == 1) {
		res.eb(nodos[u][0]);
		return;
	}
	dfs3(nodomn[u]);
}

vector<int> toposort;
void dfs2(int u) {
	vis[u] = 1;
	for (int v : g[u])
		if (!vis[v]) {
			dfs2(v);
		}
	if (!vis2[comp[u]])
		toposort.eb(comp[u]);
	vis2[comp[u]] = 1;
}

void solve() {
	cin >> n;

	toposort.clear();
	for (int i = 0; i <= n; i++)
		mn[i] = INF;

	for (int i = 0; i < n; i++) {
		int u;
		cin >> u;
		u--;
		g[i].eb(u);
		gi[u].eb(i);
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	kosaraju();
	for (int i = 0; i < n; i++)
		vis[i] = 0;
	for (int i = 0; i < n; i++) {
		if (!vis2[comp[i]])
			dfs2(i);
	}
	reverse(all(toposort));
	for (int i = 0; i < (int)toposort.size(); i++) {
		process(toposort[i]);
	}
	for (auto u : res)
		cout << u + 1 << " ";
	cout << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int TC = 1;
	if (TC) {
		cin >> TC;
		int TEST = 1;
		while (TEST <= TC) {
			cerr << "[Testcase " << TEST << "]" << endl;
			solve();
			for (int i = 0; i <= n; i++) {
				g[i].clear();
				gi[i].clear();
				nodos[i].clear();
				vis[i] = vis2[i] = vis3[i] = comp[i] = a[i] = sz[i] = 0;
				nodomn[i] = -1;
				mn[i] = INF;
			}
			res.clear();
			while (S.size())
				S.pop();
			++TEST;
		}
	} else
		solve();
}
