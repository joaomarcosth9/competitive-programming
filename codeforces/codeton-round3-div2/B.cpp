#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define cerr                                                                                                           \
    if (false) cerr
#endif
#define endl '\n'
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto &x) { return res; }
#define L2(res...) [&](const auto &x, const auto &y) { return res; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;
void out(bool ans) { cout << (ans ? "YES" : "NO") << endl; }

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    if (n % 2 == 0) {
        int mx = 0;
        for (int i = 0; i < n; i++) mx ^= a[i];
        int v = 0;
        for (int i = 0; i < m; i++) v |= b[i];
        for (int i = 0; i < n; i++) a[i] |= v;
        int cx = 0;
        for (int i = 0; i < n; i++) cx ^= a[i];
        cout << cx << " " << mx << endl;
    } else {
        int mx = 0;
        for (int i = 0; i < n; i++) mx ^= a[i];
        int v = 0;
        for (int i = 0; i < m; i++) v |= b[i];
        for (int i = 0; i < n; i++) a[i] |= v;
        int cx = 0;
        for (int i = 0; i < n; i++) cx ^= a[i];
        cout << mx << " " << cx << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        int TEST = 1;
        while (TEST <= TC) {
            cerr << "[Testcase " << TEST << "]" << endl;
            solve();
            /* cout << solve() << endl; */
            /* cout << (solve() ? "YES" : "NO") << endl; */
            ++TEST;
        }
    } else
        solve();
}
