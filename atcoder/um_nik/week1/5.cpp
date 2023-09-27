#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef pair<int, int> ii;
int testcases = 0;
const int INF = 1.05e9;
const ll INFLL = 4.5e18;
#define endl '\n'
#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#define dbarr(x...)
#endif

const int maxx = 5000;
ll dp[maxx][55][55] = {};

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(begin(v), end(v));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[0][0][j] = 1;
        }
    }
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            for (int s = 0; s < maxx; s++) {
                dp[s][i][j] = dp[s][i][j - 1];
                if (s - v[j - 1] >= 0) {
                    dp[s][i][j] += dp[s - v[j - 1]][i - 1][j - 1];
                    if (s == 7) {
                        db(i, j, s, dp[s][i][j]);
                    }
                }
            }
        }
    }
    /* db("a"); */
    /* return; */
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        db(i, m * i, dp[m * i][i][n]);
        res += dp[m * i][i][n];
    }
    cout << res << endl;
    /* while(1){ */
    /*     int s, i, j; cin >> s >> i >> j; */
    /*     db(dp[s][i][j]); */
    /* } */
}

signed main() {
#ifndef LOCAL_DEBUG
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tsts = 1;
    if (testcases) cin >> tsts;
    while (tsts--) solve();
    return 0;
}
