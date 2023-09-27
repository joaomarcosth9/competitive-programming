#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int maxn = 1e5 + 5;
vector<int> adj[maxn];
multiset<pair<int,int>> F[maxn];
int age[maxn], res[maxn], par[maxn][20];
int n, m;

void pre_dfs(int u = 0, int p = -1){
	for(int i = 1; i < 20; i++){
		par[u][i] = par[par[u][i - 1]][i - 1];
	}
	for(int v : adj[u]) if(v != p) {
		pre_dfs(v, u);
	}
}

int find_pai(int u, int r){
    for(int i = 19; i >= 0; i--){
        if(age[par[u][i]] <= r){
            u = par[u][i];
        }
    }
    return u;
}

void sobe(int u = 0, int p = -1){
    multiset<pair<int,int>> new_F;
	for(auto [l, r] : F[u]){
		int L = 1, R = n;
        int ans = find_pai(u, r);
        if(ans == u){
            new_F.emplace(l, r);
        } else {
            F[ans].emplace(l, r);
        }
	}
    F[u] = new_F;
	for(int v : adj[u]) if(v != p) {
		sobe(v, u);
	}
}

int seg[2 * maxn];
int query(int l, int r){
	int ans = 0;
	for(l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1){
		if(l & 1) ans += seg[l++];
		if(r & 1) ans += seg[--r];
	}
	return ans;
}

void update(int i, int x){
	seg[i += maxn] += x;
	for(i >>= 1; i; i >>= 1) {
		seg[i] = seg[i<<1] + seg[i<<1|1];
	}
}

void dfs(int u = 0, int p = -1){
	for(auto [l, _] : F[u]){
		update(l, 1);
	}
	res[u] += query(0, age[u]);
	for(int v : adj[u]) if(v != p) {
		dfs(v, u);
	}
	for(auto [l, _] : F[u]){
		update(l, -1);
	}
}

void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		int _age, p; cin >> _age >> p;
		p--;
		age[i] = _age;
		par[i][0] = p;
		if(i == p) continue;
		adj[p].emplace_back(i);
	}

	pre_dfs();

	for(int i = 0; i < m; i++){
		int u; cin >> u; u--;
		int l, r; cin >> l >> r;
		F[u].emplace(l, r);
	}

	sobe();

	dfs();

	for(int i = 0; i < n; i++){
		cout << res[i] << " ";
	}
	cout << endl;

}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(res, 0, sizeof(res));
	solve();
}
