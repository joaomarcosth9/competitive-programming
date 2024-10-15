#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 1e6 + 5, INF = 1e9;

struct Seg {
    int t[2 * N];
    Seg() {
        for (int &i : t) {
            i = -INF;
        }
    }
    int query(int l, int r) {
        int ans = -INF;
        for (l += N, r += N + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = max(ans, t[l++]);
            if (r & 1) ans = max(ans, t[--r]);
        }
        return ans;
    }
    void update(int i, int x) {
        i += N;
        t[i] = max(t[i], x);
        for (i >>= 1; i > 0; i >>= 1) {
            t[i] = max(t[i << 1], t[i << 1 | 1]);
        }
    }
} seg;

int n, a[N], b[N];
ll res = 0;

void solve() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b, b + n);

    int len = unique(b, b + n) - b;

    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(b, b + len, a[i]) - b + 1;
    }

    stack<int> stk;

    int L = -1;

    for (int i = 0; i < n; i++) {
        L = max(L, seg.query(a[i] + 1, n));
        res += L + 1;

        while (stk.size() && a[i] > a[stk.top()]) {
            // o stk.top() tem alguem maior que ele pra direita ja
            seg.update(a[stk.top()], stk.top());
            stk.pop();
        }
        stk.push(i);
    }

    cout << (ll)n * (n + 1) / 2 - res << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}