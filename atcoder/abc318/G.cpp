#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif
#define endl '\n'
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto& x){ return res; }
#define L2(res...) [&](const auto& x, const auto& y){ return res; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

struct block_cut_tree {
	vector<vector<int>> g, blocks, tree;
	vector<vector<pair<int, int>>> edgblocks;
	stack<int> s;
	stack<pair<int, int>> s2;
	vector<int> id, art, pos;
	
	block_cut_tree(vector<vector<int>> g_) : g(g_) {
		int n = g.size();
        tree.resize(n);
		id.resize(n, -1), art.resize(n), pos.resize(n);
		build();
	}

	int dfs(int i, int& t, int p = -1) {
		int lo = id[i] = t++;
		s.push(i);	
		
		if (p != -1) s2.emplace(i, p);
		for (int j : g[i]) if (j != p and id[j] != -1) s2.emplace(i, j);
		
		for (int j : g[i]) if (j != p) {
			if (id[j] == -1) {
				int val = dfs(j, t, i);
				lo = min(lo, val);

				if (val >= id[i]) {
					art[i]++;
					blocks.emplace_back(1, i);
					while (blocks.back().back() != j) 
						blocks.back().push_back(s.top()), s.pop();

					edgblocks.emplace_back(1, s2.top()), s2.pop();
					while (edgblocks.back().back() != pair(j, i))
						edgblocks.back().push_back(s2.top()), s2.pop();
				}
				// if (val > id[i]) aresta i-j eh ponte
			}
			else lo = min(lo, id[j]);
		}
		
		if (p == -1 and art[i]) art[i]--;
		return lo;
	}

	void build() {
		int t = 0;
		for (int i = 0; i < (int)g.size(); i++) if (id[i] == -1) dfs(i, t, -1);
		
        int n = tree.size(), m = blocks.size();
        tree.resize(n + m);
		for (int i = 0; i < m; i++) for (int j : blocks[i]) {
            tree[i + n].push_back(j), tree[j].push_back(i + n);
		}
	}
};

const int maxn = 1e6 + 5;
vector<vector<int>> adj;

namespace seg {
    const int MAX = maxn;
    const ll NEUTRAL = 0; // merge(a, neutral) = a
    ll merge(ll a, ll b) { return a + b; }
    int sz; // size of the array
    ll tree[4 * MAX], lazy[4 * MAX];
    int le(int n) { return 2 * n + 1; }
    int ri(int n) { return 2 * n + 2; }
    void push(int n, int esq, int dir) {
        if (lazy[n] == 0) return;
        tree[n] += lazy[n] * (dir - esq + 1);
        if (esq != dir) {
            lazy[le(n)] += lazy[n];
            lazy[ri(n)] += lazy[n];
        }
        lazy[n] = 0;
    }
    void build(int n, int esq, int dir) {
        if (esq == dir)
            tree[n] = 0;
        else {
            int mid = (esq + dir) / 2;
            build(le(n), esq, mid);
            build(ri(n), mid + 1, dir);
            tree[n] = merge(tree[le(n)], tree[ri(n)]);
        }
    }
    void build(int n) {
        sz = n;
        build(0, 0, sz - 1);
    }
    ll query(int l, int r, int n = 0, int esq = 0, int dir = sz - 1) {
        push(n, esq, dir);
        if (esq > r || dir < l) return NEUTRAL;
        if (l <= esq && dir <= r) return tree[n];
        int mid = (esq + dir) / 2;
        return merge(query(l, r, le(n), esq, mid), query(l, r, ri(n), mid + 1, dir));
    }
    void update(int l, int r, ll v, int n = 0, int esq = 0, int dir = sz - 1) {
        push(n, esq, dir);
        if (esq > r || dir < l) return;
        if (l <= esq && dir <= r) {
            lazy[n] += v;
            push(n, esq, dir);
        } else {
            int mid = (esq + dir) / 2;
            update(l, r, v, le(n), esq, mid);
            update(l, r, v, ri(n), mid + 1, dir);
            tree[n] = merge(tree[le(n)], tree[ri(n)]);
        }
    }
} // namespace seg

int n;

namespace hld {
    const int MAX = maxn;
    int t, sz[MAX], pos[MAX], pai[MAX], head[MAX];
    bool e = 0;
    ll merge(ll a, ll b) { return a + b; } // how to merge paths
    void dfs_sz(int u, int p = -1) {
        sz[u] = 1;
        for (int &v : adj[u])
            if (v != p) {
                dfs_sz(v, u);
                sz[u] += sz[v];
                if (sz[v] > sz[adj[u][0]] || adj[u][0] == p) swap(v, adj[u][0]);
            }
    }
    void dfs_hld(int u, int p = -1) {
        pos[u] = t++;
        for (int v : adj[u])
            if (v != p) {
                pai[v] = u;
                head[v] = (v == adj[u][0] ? head[u] : v);
                dfs_hld(v, u);
            }
    }
    void build(int root) {
        dfs_sz(root);
        t = 0;
        pai[root] = root;
        head[root] = root;
        dfs_hld(root);
    }
    void build2(int root, int n) {
        build(root);
        seg::build(n);
    }
    ll query(int u, int v) {
        if (pos[u] > pos[v]) swap(u, v);
        if (head[u] == head[v])
            return seg::query(pos[u] + e, pos[v]);
        else {
            ll qv = seg::query(pos[head[v]], pos[v]);
            ll qu = query(u, pai[head[v]]);
            return merge(qu, qv);
        }
    }
    void update(int u, ll k) {
        seg::update(pos[u], pos[u], k);
    }
}

bool solve() {
    int m; cin >> n >> m;
    adj.resize(n);

    int a, b, w; cin >> a >> w >> b;
    b--; a--; w--;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }

    block_cut_tree bct(adj);

    adj = bct.tree;

    hld::build2(a, adj.size());

    hld::update(w, 1);

    if (bct.art[w]) {
        for (auto v : adj[w]) {
            hld::update(v, 1);
        }
    } else {
        hld::update(hld::pai[w], 1);
    }

    return (hld::query(a, b) > 0);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        /* solve(); */
        /* /1* cout << solve() << endl; *1/ */
        cout << (solve() ? "Yes" : "No") << endl;
        TEST += 1;
    }
}


