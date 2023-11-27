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

void solve() {
    int n; cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> g(n);
    vector<int> p(n);
    for (int i = 0; i < n; i++) p[i] = i;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if (j != i) {
            if (a[i][j] == 'o') g[i]++;
        }
    }
    sort(all(p), L2((g[x] > g[y]) || (g[x] == g[y] && x < y)));
    for (auto u : p) cout << u + 1 << " ";
    cout << endl;
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
