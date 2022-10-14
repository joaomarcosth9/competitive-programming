#include <bits/stdc++.h>

using namespace std;

int temtestcase = 0;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;
typedef long long ll;


// segtree<T> seg(*start, *end);
template <class T>
class segtree {
const T neutral = INFLL;
#define comp(a, b) min((a),(b))
private:
	vector<T> tree;
	int n;
public:
	segtree(T* st, T* en) {
		int sz = int(en-st);
		for (n = 1; n < sz; n <<= 1);
		tree.assign(n << 1, neutral);
		for(int i=0; i<sz; i++) tree[i+n] = st[i];
		for(int i=n+sz-1; i; i--)
			tree[i>>1] = comp(tree[i>>1], tree[i]);
	}
	void update(int i, T x) {
		tree[i += n] = x;
		for (i >>= 1; i; i >>= 1)
			tree[i] = comp(tree[i<<1], tree[1+(i<<1)]);
	}
	T query(int l, int r) {
		T res = neutral;
		for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) res = comp(res, tree[l++]);
			if (r & 1) res = comp(res, tree[--r]);
		}
		return res;
	}
};

void solve(){
    int n, q; cin >> n >> q;
    vector<ll> v(n);
    for(auto &a : v) cin >> a;
    segtree<ll> seg(&v[0], &v[n]);
    for(int i = 0; i < q; i++){
        int t; cin >> t;
        if(t == 1){
            int k, u; cin >> k >> u;
            seg.update(k-1, u);
        } else {
            int l, r; cin >> l >> r;
            cout << seg.query(l-1,r-1) << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tsts = 1;
    if(temtestcase) cin >> tsts;
    while(tsts--) solve();
    return 0;
}
