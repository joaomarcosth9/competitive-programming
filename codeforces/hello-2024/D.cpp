#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 200200, LOG = 20;
int n, a[N];

pair<int, int> m[LOG][N];
pair<int, int> m2[LOG][N];

pair<int, int> query(int l, int r) {
    int j = __builtin_clz(1) - __builtin_clz(r - l + 1);
    return min(m[j][l], m[j][r - (1 << j) + 1]);
}
pair<int, int> query2(int l, int r) {
    int j = __builtin_clz(1) - __builtin_clz(r - l + 1);
    return max(m2[j][l], m2[j][r - (1 << j) + 1]);
}

bool dfs(int l, int r, int sub = 0) {
    if (l > r) return true;

    auto [mn, idx] = query(l, r);
    auto [mx, idx2] = query2(l, r);

    mn -= sub;
    mx -= sub;

    if (mn != 0) return false;

    return (dfs(l, idx - 1, sub + (mx != 0)) && dfs(idx + 1, r, sub + (mx != 0)));
}

bool solve() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) m[0][i] = make_pair(a[i], i);
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) m[j][i] = min(m[j - 1][i], m[j - 1][i + (1 << (j - 1))]);
    }
    for (int i = 0; i < n; i++) m2[0][i] = make_pair(a[i], i);
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) m2[j][i] = max(m2[j - 1][i], m2[j - 1][i + (1 << (j - 1))]);
    }

    return dfs(0, n - 1);

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        /* solve(); */
        /* cout << solve() << endl; */
        cout << (solve() ? "Yes" : "No") << endl;
    }
}
