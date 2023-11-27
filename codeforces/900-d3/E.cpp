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

template <class T> class segtree {
    const T neutral = INT_MAX;
#define comp(a, b) ((a) & (b))
  private:
    vector<T> tree;
    int n;

  public:
    segtree(T *st, T *en) {
        int sz = int(en - st);
        for (n = 1; n < sz; n <<= 1);
        tree.assign(n << 1, neutral);
        for (int i = 0; i < sz; i++) tree[i + n] = st[i];
        for (int i = n - 1; i; i--) tree[i] = comp(tree[i << 1], tree[i << 1 | 1]);
    }
    segtree(vector<T> st) {
        int sz = size(st);
        for (n = 1; n < sz; n <<= 1);
        tree.assign(n << 1, neutral);
        for (int i = 0; i < sz; i++) tree[i + n] = st[i];
        for (int i = n - 1; i; i--) tree[i] = comp(tree[i << 1], tree[i << 1 | 1]);
    }
    void update(int i, int x) {
        tree[i += n] += x;
        for (i >>= 1; i; i >>= 1) tree[i] = comp(tree[i << 1], tree[i << 1 | 1]);
    }
    T query(int l, int r) {
        T res = neutral;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = comp(res, tree[l++]);
            if (r & 1) res = comp(res, tree[--r]);
        }
        return res;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    segtree<int> seg(a);
    int q; cin >> q;
    while (q--) {
        int l, k; cin >> l >> k;
        l--;
        int L = l, R = n - 1;
        int ans = -2;
        while (L <= R) {
            int mid = (L + R) / 2;
            if (seg.query(l, mid) >= k) {
                ans = mid;
                L = mid + 1;
            } else R = mid - 1;
        }
        cout << ans + 1 << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
