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
void out(bool ans) { cout << (ans ? "YES" : "NO") << endl; }

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n), h(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> h[i];

    vector<int> valid(n);
    valid[n - 1] = 1;
    for (int i = 0; i < n - 1; i++) {
        valid[i] = !(h[i] % h[i + 1]);
    }
    vector<ll> pref(n + 1), pref2(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + valid[i];
        pref2[i + 1] = pref2[i] + a[i];
    }

    auto query = [&] (int l, int r) {
        return pref[r + 1] - pref[l];
    };
    auto query2 = [&] (int l, int r) {
        return pref2[r + 1] - pref2[l];
    };

    ll L = 1, R = n;
    ll ans = 0;

    auto test = [&] (int len) {
        bool ok = 0;
        for (int i = 0; i + len - 1 < n; i++) {
            int LL = i, RR = i + len - 1;
            if (query(LL, RR - 1) == len - 1) ok |= query2(LL, RR) <= k;
        }
        return ok;
    };

    while (L <= R) {
        int mid = midpoint(L, R);
        if (test(mid)) {
            L = mid + 1;
            ans = mid;
        } else R = mid - 1;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) { cin >> TC;
        int TEST = 1;
        while (TEST <= TC) {
            cerr << "[Testcase " << TEST << "]" << endl;
            solve();
            /* cout << solve() << endl; */
            /* cout << (solve() ? "YES" : "NO") << endl; */
            ++TEST;
        }
    } else solve();
}
