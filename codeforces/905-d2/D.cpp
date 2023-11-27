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

int res(vector<int> a, vector<int> b) {
    sort(all(a));
    int n = size(a);
    int itb = 0;
    int ret = 0;
    for (int i = 0; i < n; i++) {
        while (itb < n && b[itb] <= a[i]) {
            itb++; ret++;
        }
        itb++;
    }
    return ret;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 1; i < n; i++) cin >> a[i];
    a[0] = 1;
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(all(b));
    auto base = res(a, b);
    int l = 1, r = m;
    int ans = -1;
    while (l <= r) {
        int mid = midpoint(l, r);
        a[0] = mid;
        if (res(a, b) == base) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    cout << (ll)(ans) * base + (ll)(m - ans) * (base + 1) << endl;
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
