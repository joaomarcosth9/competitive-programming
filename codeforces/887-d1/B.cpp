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
    vector<ii> a(n);
    for (int i = 0; i < n; i++) {
        a[i].second = i;
        cin >> a[i].first;
    }
    sort(rall(a));
    vector<int> res(n);

    int l = 0, r = n - 1;

    int N = n;

    debug(a);
    int pos = 0;

    while (l <= r) {
        debug(N);
        if ((a[l].first - pos == N) ^ (a[r].first - pos == 0)) {
            if (a[l].first - pos == N) res[a[l++].second] = N--, pos++;
            else if (a[r].first - pos == 0) res[a[r--].second] = -N--;
        } else {
            cout << "NO" << endl;
            return;
        }
        debug(res);
    }

    cout << "YES" << endl;
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
