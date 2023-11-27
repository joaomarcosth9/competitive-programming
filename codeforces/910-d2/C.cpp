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
    ll n, m, k; cin >> n >> m >> k;
    ll mh = (n - 1) + (m - 1);
    if (k < mh || (k - mh) % 2 == 1) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    string rb = "RB";
    int now = 0;

    for (int j = 0; j < m - 1; j++) cout << rb[0] << " ";
    cout << endl;
    for (int j = 0; j < m - 1; j++) cout << rb[0] << " ";
    cout << endl;

    for (int i = 2; i < n - 1; i++ ) {
        now ^= 1;
        for (int j = 0; j < m - 1; j++) cout << rb[now] << " ";
        cout << endl;
    }
    
    // verificar now
    for (int j = 0; j < m - 1; j++) cout << rb[now ^= 1] << " ";
    cout << endl;

    now = 0;
    for (int i = 0; i < n - 1; i++) {
        now ^= 1;
        for (int j = 0; j < m; j++) cout << rb[now] << " ";
        cout << endl;
    }
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
