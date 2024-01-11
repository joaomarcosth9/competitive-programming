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
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

void solve() {
    int n, q; cin >> n >> q;

    vector<ull> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    while (q--) {
        ull k; cin >> k;
        ull res = 0;
        auto aa = a;
        for (int bit = 62; bit >= 0; bit--) {
            ull ck = k;
            vector<ull> b(n);
            bool db = 1;
            for (int i = 0; i < n; i++) {
                if (a[i] & (1ll << bit)) {
                    b[i] = a[i];
                } else {
                    ull next = (a[i] | (1ll << bit)) & ~((1ll << bit) - 1);
                    b[i] = next;
                    if (ck >= next - a[i]) {
                        ck -= next - a[i];
                    } else {
                        db = 0;
                        break;
                    }
                }
            }
            if (db) {
                k = ck;
                res |= (1ll << bit);
                a = b;
            }
        }
        cout << res << endl;
        a = aa;
    }
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
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
