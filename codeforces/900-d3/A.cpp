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

bool solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    for (int i = 0; i < n; i++) {
        vector<int> f(101);
        int k1 = 0, k2 = 0;
        int mx = 0, mx2 = 0;
        for (int j = i; j < n; j++) {
            f[a[j]] += 1;
            if (f[a[j]] > mx2) {
                mx2 = f[a[j]];
                k2 = a[j];
            }
            if (mx2 > mx) {
                swap(k2, k1);
                swap(mx2, mx);
            }
            if (k1 == k && mx > mx2) {
                return true;
            }
        }
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        /* solve(); */
        /* cout << solve() << endl; */
        cout << (solve() ? "YES" : "NO") << endl;
        TEST += 1;
    }
}
