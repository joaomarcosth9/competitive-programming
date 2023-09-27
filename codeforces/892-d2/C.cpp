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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;
#define int ll

void solve() {
    int n;
    cin >> n;
    ll res = 0;
    if (n == 2) {
        cout << 2 << endl;
        return;
    }
    for (int i = 0; i <= n; i++) {
        ll res2 = 0;
        vector<ll> vals;
        for (int j = 1; j <= n - i; j++) {
            vals.emplace_back(j * j);
        }
        debug(vals);
        for (int l = n - i + 1, r = n; l <= n; l++, r--) {
            vals.emplace_back(l * r);
        }
        debug(vals);
        res2 = accumulate(begin(vals), end(vals), 0ll) - *max_element(begin(vals), end(vals));
        res = max(res, res2);
    }
    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    auto start = chrono::steady_clock::now();
    if (TC) {
        cin >> TC;
        start = chrono::steady_clock::now();
        int TEST = 0;
        while (TEST < TC) {
            cerr << "[Testcase " << TEST + 1 << "]" << endl;
            solve();
            ++TEST;
            cerr << endl;
        }
    } else
        solve();
#ifdef LOCAL_DEBUG
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "\nTime taken: ";
    cerr << chrono::duration<double, milli>(diff).count() << " ms" << endl;
#endif
}
