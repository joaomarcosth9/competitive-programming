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
    int n, x; cin >> n >> x;
    vector<ii> a(n);
    vector<int> oa;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        oa.eb(a[i].first);
        a[i].second = i;
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    sort(rall(a));
    sort(all(b));
    debug(a);
    debug(b);

    reverse(begin(a), begin(a) + x);

    for (int i = 0; i < x; i++) {
        if (a[i].first <= b[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    
    reverse(begin(a) + x, end(a));

    for (int i = x; i < n; i++) {
        if (a[i].first > b[i]) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        c[a[i].second] = b[i];
    }
    for (auto u : c) cout << u << " ";
    cout << endl;

    int ans = 0;
    for (int i = 0; i < n; i++) ans += oa[i] > c[i];
    assert(ans == x);

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
