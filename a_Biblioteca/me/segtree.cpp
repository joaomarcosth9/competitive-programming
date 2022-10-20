// 0 - INDEXED
// segtree<T> seg(*start, *end);
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

