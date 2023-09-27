#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
#define int ll
const int maxn = 2e5 + 5;
int n;
vector<int> adj[maxn];

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

const int neutral = 0;
#define comp(a, b) (a + b)
class SegmentTree {
private:
	vector<int> st, lazy;
	int size;
#define left(p) (p << 1)
#define right(p) (p << 1 | 1)
	void push(int p, int l, int r){
		if(lazy[p] == -1) return;
		st[p] = (r - l + 1) * lazy[p];
		if(l != r){
			lazy[right(p)] = lazy[p];
			lazy[left(p)] = lazy[p];
		}
		lazy[p] = -1;
	}
	void update(int p, int l, int r, int a, int b, int k){
		push(p, l, r);
		if(a > r || b < l) return;
		if(l >= a && r <= b){
			lazy[p] = k;
			push(p, l, r); return;
		}
		update(left(p), l, (l + r) / 2, a, b, k);
		update(right(p), (l + r) / 2 + 1, r, a, b, k);
		st[p] = comp(st[left(p)], st[right(p)]);
	}
	int query(int p, int l, int r, int a, int b){
		push(p, l, r);
		if(a > r || b < l) return neutral;
		if(l >= a && r <= b) return st[p];
		int m = (l + r) / 2;
		int p1 = query(left(p), l, m, a, b);
		int p2 = query(right(p), m + 1, r, a, b);
		return comp(p1, p2);
	}
public:
	void build(){
		size = n;
		st.resize(4 * maxn);
		lazy.assign(4 * maxn, -1);
	}
	int query(int l, int r){
		if(l > r) swap(l, r);
		return query(1, 0, size - 1, l, r);
	}
	void update(int l, int r, int k){
		if(l > r) swap(l, r);
		update(1, 0, size - 1, l, r, k);
	}
};

SegmentTree seg;

namespace hld {
	const int MAX = maxn;
	int t, sz[MAX], pos[MAX], pai[MAX], head[MAX], who[MAX];
	ll merge(ll a, ll b) { return a + b; }
	void dfs_sz(int u, int p = -1) {
		sz[u] = 1;
		for(int& v : adj[u]) if(v != p) {
			dfs_sz(v, u);
			sz[u] += sz[v];
			if(sz[v] > sz[adj[u][0]] || adj[u][0] == p) swap(v, adj[u][0]);
		}
	}
	void dfs_hld(int u, int p = -1){
		who[t] = u;
		pos[u] = t;
		t++;
		for(int v : adj[u]) if(v != p) {
			pai[v] = u;
			head[v] = (v == adj[u][0] ? head[u] : v);
			dfs_hld(v, u);
		}
	}
	void build(int root = 0){
		dfs_sz(root);
		t = 0;
		pai[root] = root;
		head[root] = root;
		dfs_hld(root);
	}
	void update(int u, int v, int k){
		if(pos[u] > pos[v]) swap(u, v);
		if(head[u] == head[v]) seg.update(pos[u], pos[v], k);
		else {
			seg.update(pos[head[v]], pos[v], k);
			update(u, pai[head[v]], k);
		}
	}
	ll query_subtree(int u){
		return seg.query(pos[u], pos[u] + sz[u] - 1);
	}
	int diff(int u){
		return sz[u] - query_subtree(u);
	}
    bool aceso(int u){
        return seg.query(pos[u], pos[u]) == 1;
    }
	void balance(int u){
        if(aceso(u)) return;
		int p = head[u];
		int dist = pos[u] - pos[p] + 1;
        debug(u, p, diff(p), dist);
		if(diff(p) == dist){
			update(u, p, 1);
			if(p != 0) balance(pai[p]);
		} else {
			int L = pos[p], R = pos[u];
			int ans = -1;
			while(L <= R){
				int mid = (L + R) / 2;
				dist = pos[u] - mid + 1;
				if(dist == diff(who[mid])){
					ans = who[mid];
					R = mid - 1;
				} else {
					L = mid + 1;
				}
			}
			if(ans != -1) update(u, ans, 1);
		}
	}
	void update_subtree(int u, int k){
		seg.update(pos[u], pos[u] + sz[u] - 1, k);
		if(k == 1) balance(pai[u]);
		else update(u, 0, k);
	}
}

void solve(){
	cin >> n;
	seg.build();
	for(int i = 0; i < n - 1; i++){
		int u, v; cin >> u >> v;
		u--, v--;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	hld::build();
	int q; cin >> q;
	while(q--){
		int t; cin >> t;
		int u; cin >> u; u--;
        for(int i = 0; i < n; i++){
            debug(i, hld::aceso(i));
        }
		if(t == 1){
            /* if(hld::aceso(u)) continue; */
			hld::update_subtree(u, 1);
		} else if(t == 2){
            /* if(!hld::aceso(u)) continue; */
			hld::update_subtree(u, 0);
		} else {
			cout << hld::query_subtree(u) << endl;
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
}

