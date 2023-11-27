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
    vector a(n, vector<int> (n - 1));
    for (int i = 0; i < n; i++) {
        for (auto &u : a[i]) cin >> u;
        reverse(all(a[i]));
    }
    vector<int> res(n);
    for (int j = 0; j < n; j++) {
        vector<int> freq(n + 1);
        for (int i = 0; i < n; i++) if (a[i].size()) {
            freq[a[i].back()]++;
        }
        int mx = 0, who = 0;
        for (int i = 1; i <= n; i++) {
            if (freq[i] > mx) {
                mx = freq[i];
                who = i;
            }
        }
        for (int i = 0; i < n; i++) if (a[i].size()) {
            if (a[i].back() == who) a[i].pop_back();
        }
        res[j] = who;
    }

    for (auto u : res) cout << u << " ";
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
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
