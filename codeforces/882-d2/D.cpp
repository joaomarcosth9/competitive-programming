#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

template <class T>
class segtree {
const T neutral = 0;
#define comp(a, b) ((a)+(b))
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
	void update(int i) {
		tree[i += n] ^= 1;
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

const int maxn = 2e5 + 5;
string s;
int n, m, q;
int peso[maxn];
set<int> falta;
int l[maxn], r[maxn];
int aux[maxn];

void solve() {
    cin >> n >> m >> q;
    cin >> s;
    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i];
        l[i]--, r[i]--;
    }
    for(int i = 0; i < n; i++){
        falta.emplace(i);
    }
    for (int i = 0; i < n; i++) s[i] -= '0';
    int uns = 0;
    for (int i = 0; i < n; i++) {
        uns += s[i];
    }
    int cpeso = 1;
    int N = 0;
    for (int i = 0; i < m; i++) {
        int L = l[i], R = r[i];
        auto lb = falta.lower_bound(L);
        while(lb != falta.end() && *lb <= R){
            int u = *lb;
            for(int j = u; j <= R; j++){
                u = j;
                if(peso[j]) break;
                peso[j] = cpeso;
                cpeso++;
                N++;
                falta.erase(j);
            }
            lb = falta.upper_bound(u);
        }
    }
    for (int i = 0; i < n; i++)  {
        if (s[i] && peso[i]) aux[peso[i] - 1] = 1;
    }

    segtree<int> seg(aux, aux + N);
  
    // queries de [0, uns] na quantidade de uns dessa seg
    // update no idx muda seg[peso[idx]];
    for (int i = 0; i < q; i++) {
        int idx; cin >> idx; idx--;
        if(s[idx] == 1){
            uns--;
        } else {
            uns++;
        }
        s[idx] ^= 1;
        seg.update(peso[idx] - 1);
        cout << min(uns, N) - seg.query(0, min(uns, N) - 1) << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC) { cin >> TC;
        while (TC--) solve();
    } else solve();
    return 0;
}
