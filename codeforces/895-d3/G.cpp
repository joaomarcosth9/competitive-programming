#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define endl '\n'
#define cerr                                                                                                           \
    if (false) cerr
#endif
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
#define int ll

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &u : a) cin >> u;
    vector<int> idx;
    __int128_t prod = 1;
    bool db = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 1) idx.eb(i);
        prod *= a[i];
        if (prod > (__int128_t)(2e14)) {
            db = 1;
        }
    }
    if (idx.empty()) {
        cout << "1 1" << endl;
        return;
    }
    if (db || ssize(idx) > 100) {
        cout << idx[0] + 1 << " " << idx.back() + 1 << endl;
        return;
    }
    vector<ll> pref(n + 1), pref2(n + 1);

    for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];

    pref2[0] = 1;
    for (int i = 0; i < n; i++) pref2[i + 1] = pref2[i] * a[i];

    auto query = [&](int l, int r) {
        if (l > r) return 0ll;
        return pref[r + 1] - pref[l];
    };
    auto queryP = [&](int l, int r) {
        if (l > r) return 1ll;
        return pref2[r + 1] / pref2[l];
    };

    int N = ssize(idx);
    ll bestsum = -1;
    ll L = -1, R = -1;

    for (int i = 0; i < N; i++) {
        ll psum = query(0, idx[i] - 1);
        for (int j = i; j < N; j++) {
            ll cprod = queryP(idx[i], idx[j]);
            ll ssum = query(idx[j] + 1, n - 1);
            if (psum + cprod + ssum > bestsum) {
                bestsum = psum + cprod + ssum;
                L = idx[i] + 1;
                R = idx[j] + 1;
            }
        }
    }
    cout << L << " " << R << endl;
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
            ++TEST;
        }
    } else
        solve();
}
