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

const int maxn = 3e5 + 5;
int n;
int l[maxn], r[maxn];
string s;
int res;

void dfs(int u, int chg) {
    debug(u, chg);
    if (l[u] || r[u]) {
        if (l[u]) {
            if (s[u - 1] != 'L') dfs(l[u], chg + 1);
            else dfs(l[u], chg);
        }
        if (r[u]) {
            if (s[u - 1] != 'R') dfs(r[u], chg + 1);
            else dfs(r[u], chg);
        }
    } else {
        res = min(res, chg);
    }
}

void solve() {
    cin >> n >> s;
    res = INT_MAX;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }
    dfs(1, 0);
    cout << res << endl;
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
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
