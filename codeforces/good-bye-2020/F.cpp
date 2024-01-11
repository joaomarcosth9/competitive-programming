#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 500500, mod = 1e9 + 7;

int n, m;

int sz[N], par[N], who[N];

int find(int x) {
    return x == par[x] ? x : x = find(par[x]);
}

void unite(int x, int y) {
    if (sz[x] > sz[y])
        swap(x, y);
    par[x] = y;
    sz[y] += sz[x];
}

void solve() {
    cin >> n >> m;

    for (int i = 0; i <= m; i++) {
        par[i] = i;
        sz[i] = 1;
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int x, y = m; 
        int k; cin >> k;

        if (k == 1) {
            cin >> x;
            x--;
        } else {
            cin >> x >> y;
            x--; y--;
        }

        x = find(x), y = find(y);

        if (x == y) continue;

        unite(x, y);

        who[ans++] = i;
    }

    int p2 = 1;
    for (int i = 0; i < ans; i++)
        p2 = p2 * 2 % mod;

    cout << p2 << " " << ans << endl;

    for (int i = 0; i < ans; i++)
        cout << who[i] + 1 << " ";
    cout << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
