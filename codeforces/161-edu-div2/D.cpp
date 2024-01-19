#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 2), d(n + 2), L(n + 2), R(n + 2), vis(n + 2);

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> d[i];
    d[0] = 1e9, d[n + 1] = 1e9;

    int N = n + 2;

    for (int i = 0; i < N; i++) {
        R[i] = i + 1, L[i] = i - 1;
    }

    vector<int> p;
    for (int i = 1; i <= n; i++) p.emplace_back(i);

    for (int r = 0; r < n; r++) {
        vector<int> die;
        for (int x : p) {
            if (vis[x]) continue;
            if (a[L[x]] + a[R[x]] > d[x]) {
                die.emplace_back(x);
            }
        }
        p.clear();
        cout << size(die) << " ";
        for (int x : die) {
            R[L[x]] = R[x];
            L[R[x]] = L[x];
            vis[x] = 1;
            if (L[x] > 0) p.emplace_back(L[x]);
            if (R[x] <= n) p.emplace_back(R[x]);
        }
        sort(begin(p), end(p));
        p.erase(unique(begin(p), end(p)), end(p));
    }
    cout << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
