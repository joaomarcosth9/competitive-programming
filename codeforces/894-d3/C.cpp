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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> m;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]] += 1;
        mx = max(a[i], mx);
    }
    if (n == 1) {
        cout << (a[0] == 1 ? "YES" : "NO") << endl;
        return;
    }

    bool db = 1;

    vector<int> need(n);

    if (a[0] != n || mx > n) {
        cout << "NO" << endl;
        return;
    }

    int ac = m[1];
    debug(m);

    for (int i = 1; i < n; i++) {
        // a[i] -> qnts caras tem altura >= i + 1;
        db &= a[i] == n - ac;
        ac += m[i + 1];
    }

    cout << (db ? "YES" : "NO") << endl;
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
