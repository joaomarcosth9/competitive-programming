#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const ll INF = ll(-2e18) - 10;
struct Line {
    ll a, b;
    Line(ll a_ = 0, ll b_ = -INF) : a(a_), b(b_) { }
    ll operator()(ll x) { return a * x + b; }
};

template <ll MINL = ll(0), ll MAXR = ll(1e6 + 5)>
struct LichaoTree {
    vector<Line> tree;
    vector<int> L, R;

    int newnode() {
        tree.push_back(Line());
        L.push_back(-1);
        R.push_back(-1);
        return int(tree.size()) - 1;
    }

    LichaoTree() { newnode(); }

    int lc(int u) {
        if (L[u] == -1) L[u] = newnode();
        return L[u];
    }

    int rc(int u) {
        if (R[u] == -1) R[u] = newnode();
        return R[u];
    }

    void insert(Line line, int n = 0, ll l = MINL, ll r = MAXR) {
        ll mid = l + (r - l) / 2;
        bool bl = line(l) < tree[n](l);
        bool bm = line(mid) < tree[n](mid);
        bool br = line(r) < tree[n](r);
        if (bm) swap(tree[n], line);
        if (line.b == -INF) return;
        if (bl != bm) insert(line, lc(n), l, mid - 1);
        else if (br != bm) insert(line, rc(n), mid + 1, r);
    }

    ll query(int x, int n = 0, ll l = MINL, ll r = MAXR) {
        if (tree[n](x) == -INF || (l > r)) return -INF;
        if (l == r) return tree[n](x);
        ll mid = l + (r - l) / 2;
        if (x < mid) return min(tree[n](x), query(x, lc(n), l, mid - 1));
        else return min(tree[n](x), query(x, rc(n), mid + 1, r));
    }
};

void solve() {
    int n;
    ll c;
    cin >> n >> c;

    vector<ll> h(n);

    for (ll &i : h) {
        cin >> i;
    }

    vector<ll> dp(n, -INF);
    LichaoTree lichao;

    dp[0] = 0;
    lichao.insert(Line(-2 * h[0], dp[0] + h[0] * h[0]));

    for (int i = 1; i < n; i++) {
        dp[i] = c + h[i] * h[i];
        dp[i] += lichao.query(h[i]);
        lichao.insert(Line(-2 * h[i], dp[i] + h[i] * h[i]));
    }

    cout << dp[n - 1] << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}