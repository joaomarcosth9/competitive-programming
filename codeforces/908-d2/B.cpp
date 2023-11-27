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
    vector<int> a(n);
    for (int &i : a) cin >> i;
    vector<int> b(n, 1);
    map<int, int> f;
    for (auto u : a) f[u]++;
    int cnt = 0;
    for (auto [k, v] : f) {
        if (v >= 2 && cnt < 2) {
            cnt++;
            for (int i = 0; i < n; i++) {
                if (a[i] == k) {
                    b[i] = cnt + 1;
                    break;
                }
            }
        }
    }
    if (cnt < 2) cout << -1 << endl;
    else {
        for (auto u : b) cout << u << " ";
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
