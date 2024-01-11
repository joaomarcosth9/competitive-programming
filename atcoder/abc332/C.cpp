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
    int n, m; cin >> n >> m;
    string s; cin >> s;
    for (int i = 0; i < n; i++) s[i] -= '0';

    int l = 0, r = n;
    int ans = -1;

    auto test = [&] (int plain, int logo) {
        int P = plain, L = logo;
        for (int i = 0; i < n; i++) {
            if (s[i] == 0) {
                P = plain, L = logo;
            } else if (s[i] == 1) {
                if (P == 0) {
                    L--;
                    if (L < 0) return 0;
                } else {
                    P--;
                    if (P < 0) return 0;
                }
            } else {
                L--;
                if (L < 0) return 0;
            }
        }
        return 1;
    };

    while (l <= r) {
        int mid = midpoint(l, r);
        if (test(m, mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    cout << ans << endl;

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
