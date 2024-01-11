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

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> d(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        d[u]++; d[v]++;
    }

    for (int i = 0; i < n; i++) d[i]--;

    vector<int> p(n);
    iota(all(p), 0);
    sort(all(p), L2(a[x] > a[y]));

    ll res = accumulate(all(a), 0ll);
    int it = 0;

    cout << res << " ";

    for (int i = 0; i < n - 2; i++) {
        int u = p[it];
        while (it < n - 1 && d[u] == 0) {
            it++;
            u = p[it];
        }
        res += a[u];
        cout << res << " ";
        d[u]--;
        while (it < n - 1 && d[u] == 0) {
            it++;
            u = p[it];
        }
    }
    cout << endl;

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
