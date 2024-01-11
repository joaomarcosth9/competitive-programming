#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 200200, K = 30;

int n, k;
int nxt, r1, r2, r3, X, res;
int a[N];

const int T = N * K;

int go[T][2];
vector<int> who[T];

void insert(int x, int id) {
    int u = 0;
    for (int i = k - 1; i >= 0; i--) {
        int on = x >> i & 1;
        if (go[u][on] == 0) {
            go[u][on] = nxt++;
        }
        u = go[u][on];
        who[u].emplace_back(id);
    }
}

pair<int, int> query(int x) {
    int u = 0;
    int ret = 0;
    for (int i = k - 1; i >= 0; i--) {
        int on = x >> i & 1;
        if (go[u][on]) {
            u = go[u][on];
        } else if (go[u][!on]) {
            u = go[u][!on];
            ret |= 1 << i;
        }
    }
    return {ret, who[u].back()};
}

void solve() {
    cin >> n >> k;

    while (nxt >= 0) {
        go[nxt][0] = go[nxt][1] = 0;
        who[nxt].clear();
        nxt--;
    }

    nxt = 1;
    r1 = r2 = -1;
    res = 2e9;
    r3 = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        if (i > 0) {
            auto [x, i2] = query(a[i]);
            if (x < res) {
                res = x;
                r1 = i;
                r2 = i2;
            }
        }

        insert(a[i], i);
    }

    for (int i = k - 1; i >= 0; i--) {
        if (res >> i & 1) {
            r3 |= (1 << i) * (rng() % 2);
        } else {
            if (a[r1] >> i & 1) continue;
            r3 |= (1 << i);
        }
    }

    cout << r1 + 1 << " " << r2 + 1 << " " << r3 << endl;

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
