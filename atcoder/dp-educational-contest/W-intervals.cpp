#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 2e5 + 5;
int n, m;

ll active = 0;
ll bg[N];
vector<pair<int, int>> en[N];

ll seg[4 * N];
ll lazy[4 * N];

void push(int u, int l, int r) {
    seg[u] += lazy[u];
    if (l != r) {
        lazy[u << 1] += lazy[u];
        lazy[u << 1 | 1] += lazy[u];
    }
    lazy[u] = 0;
}

ll query(int L, int R, int u = 1, int l = 0, int r = n) {
    push(u, l, r);
    if (l > R || r < L) return -2e15;
    if (l >= L && r <= R) {
        return seg[u];
    }
    int mid = (l + r) >> 1;
    return max(query(L, R, u << 1, l, mid), query(L, R, u << 1 | 1, mid + 1, r));
}

void update(int L, int R, ll x, int u = 1, int l = 0, int r = n) {
    push(u, l, r);
    if (l > r || l > R || r < L) return;
    if (l >= L && r <= R) {
        lazy[u] = x;
        push(u, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    update(L, R, x, u << 1, l, mid);
    update(L, R, x, u << 1 | 1, mid + 1, r);
    seg[u] = max(seg[u << 1], seg[u << 1 | 1]);
}

void updateset(int i, ll x, int u = 1, int l = 0, int r = n) {
    push(u, l, r);
    if (i < l || i > r) return;
    if (l == r) {
        seg[u] = x;
    } else {
        int mid = (l + r) >> 1;
        updateset(i, x, u << 1, l, mid);
        updateset(i, x, u << 1 | 1, mid + 1, r);
        seg[u] = max(seg[u << 1], seg[u << 1 | 1]);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int l, r, x; cin >> l >> r >> x;
        bg[l] += x;
        en[r].push_back({l, x});
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        active += bg[i];
        ll now = query(0, i - 1);
        ans = max(ans, now + active);
        updateset(i, now);
        for (auto [l, x] : en[i]) {
            update(l, i, x);
            active -= x;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
