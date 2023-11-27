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
map<string, int> conv;
int cnt = 0;
int go[maxn], back[maxn];
bool vis[maxn];

bool solve() {
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        string u, v; cin >> u >> v;
        if (!conv.count(u)) conv[u] = ++cnt;
        if (!conv.count(v)) conv[v] = ++cnt;
        go[conv[u]] = conv[v];
        back[conv[v]] = conv[u];
        debug(u, conv[u]);
        debug(v, conv[v]);
    }
    int db = 0;
    for (int i = 1; i <= cnt; i++) if (go[i] == 0 && !vis[i]) {
        int v = i;
        vis[v] = 1;
        db++;
        while (back[v]) {
            v = back[v];
            if (vis[v]) return 0;
            vis[v] = 1;
            db++;
        }
    }
    return db == cnt;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        /* solve(); */
        /* cout << solve() << endl; */
        cout << (solve() ? "Yes" : "No") << endl;
        TEST += 1;
    }
}
