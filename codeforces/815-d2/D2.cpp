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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

const int MAX = 4e5 + 5, LOG = 31;
const int MAXT = MAX * LOG;
int n, m;
int a[MAX], dp[MAX];
int trie[MAXT][2], go[MAXT][2];

void solve() {
    cin >> n;

    m = 1;

    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        int x = a[i] ^ i;
        int u = 0;
        dp[i] = 1;
        for (int bit = LOG - 1; bit >= 0; bit--) {
            int on = x >> bit & 1;
            int v = go[u][!on];

            if (v > 0) dp[i] = max(dp[i], trie[v][!(a[i] >> bit & 1)] + 1);

            if (go[u][on] == 0) go[u][on] = m++;
            u = go[u][on];
        }

        u = 0;
        for (int bit = LOG - 1; bit >= 0; bit--) {
            int on = x >> bit & 1;
            u = go[u][on];
            trie[u][i >> bit & 1] = max(trie[u][i >> bit & 1], dp[i]);
        }
    }

    cout << *max_element(dp, dp + n) << endl;
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
        for (int i = 0; i <= n; i++) dp[i] = a[i] = 0;
        for (int i = 0; i <= m; i++) trie[i][0] = trie[i][1] = 0;
        for (int i = 0; i <= m; i++) go[i][0] = go[i][1] = 0;
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
