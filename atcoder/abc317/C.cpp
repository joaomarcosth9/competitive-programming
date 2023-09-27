#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define endl '\n'
#define cerr if (false) cerr
#endif
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

const int MAX = 11;
vector<pair<int, int>> g[MAX]; // {vizinho, peso}

int n;
 
vector<int> vis(n);
int dfs(int u, int msk = 0) {
    msk |= (1 << u);
    int ret = 0;
    for (auto [v, w] : g[u]) if (!(msk >> v & 1)) {
        ret = max(ret, w + dfs(v, msk));
    }
    return ret;
}

void solve() {
    cin >> n;
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        g[u].eb(v, w);
        g[v].eb(u, w);
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, dfs(i));
    }
    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
    if (TC) { cin >> TC;
        int TEST = 1;
        while (TEST <= TC) {
            cerr << "[Testcase " << TEST << "]" << endl;
            solve();
            ++TEST;
        }
    } else solve();
}
