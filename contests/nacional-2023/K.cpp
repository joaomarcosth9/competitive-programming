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

const int maxk = 24, maxn = 305, inf = 1e9;
int a[maxn], ppc[1 << maxk], dp[1 << maxk], first[maxk][maxn], back[1 << maxk];

void solve(int n, int k) {
    for (int i = 0; i < (1 << k); i++) ppc[i] = __builtin_popcount(i);

    for (int i = 0; i < k; i++) {
        first[i][n] = inf;
        for (int j = n - 1; j >= 0; j--) {
            first[i][j] = first[i][j + 1];
            if (a[j] == i) first[i][j] = j;
        }
    }

    for (int msk = 0; msk < (1 << k); msk++) {
        for (int u = 0; u < k; u++) {
            if (msk & (1 << u)) continue;
            if (first[u][dp[msk]] > dp[msk | (1 << u)]) {
                dp[msk | (1 << u)] = first[u][dp[msk]];
                back[msk | (1 << u)] = u;
                if (dp[msk | (1 << u)] == inf) {
                    vector<int> us(k);
                    vector<int> res;
                    msk |= (1 << u);
                    while (msk) {
                        res.eb(back[msk] + 1);
                        us[back[msk]] = 1;
                        msk ^= (1 << back[msk]);
                    }
                    reverse(all(res));
                    for (int i = 0; i < k; i++) if (!us[i]) res.eb(i + 1);
                    debug(res);
                    int it = 0;
                    for (int i = 0; i < n; i++) {
                        if (a[i] == res[it] - 1) it++;
                        if (it == k) break;
                    }
                    if (it == k) assert(false);
                    debug(res);
                    for (auto x : res) cout << x << " ";
                    cout << endl;
                    return;
                }
            }
        }
    }

    cout << "*" << endl;
}

void solve() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) a[i]--;
    if (k < 25) {
        solve(n, k);
    } else {
        vector<int> f(k), us(k);
        int K = k;
        int f0 = K;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (us[a[i]]) continue;
            if (f[a[i]] == 0) f0--;
            f[a[i]] = 1;
            if (f0 == 0) {
                us[a[i]] = 1;
                res.eb(a[i] + 1);
                f0 = --K;
            }
        }
        for (int i = 0; i < k; i++) if (!us[i]) res.eb(i + 1);
        for (auto u : res) cout << u << " ";
        cout << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
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
