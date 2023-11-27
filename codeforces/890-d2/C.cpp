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

int solve() {
    int n; cin >> n;
    ll k; cin >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i]; // n = 1000
    reverse(all(a));

    ll l = a[0] + 1, r = 1e14;

    ll res = a[0];

    while (l <= r) {
        ll mid = (l + r) / 2;
        // the maximum of the array will be mid
        auto b = a;
        bool db = 0;
        debug(mid);
        for (int i = 1; i < n; i++) { // maximum will be at position i
            if (b[i] >= mid) { db = 1; break; }
            int it = 1;
            ll K = mid - b[i];
            for (int j = i - 1; j >= 0; j--, it++) {
                ll need = mid - it;
                if (j == 0 && need > b[j]) { K = 1e9; break; }
                debug(i, j, need, b[j]);
                if (b[j] >= need) break;
                else {
                    K += need - b[j];
                }
            }
            debug(K, k);
            if (K <= k) { db = 1; break; }
        }
        if (db) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return res;
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
        cout << solve() << endl;
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
