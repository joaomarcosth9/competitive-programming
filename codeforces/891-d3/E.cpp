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
    vector<pair<ll, int>> v(n);
    vector<ll> res(n);
    for (int i = 0; i < n; i++) {
        ll u;
        cin >> u;
        v[i] = {u, i};
    }
    sort(begin(v), end(v));

    ll t = 0;
    for (int i = 0; i < n; i++) t += v[i].first - v[0].first + 1;
    res[v[0].second] = t;
    ll t2 = 0;
    for (int i = n - 1; i >= 0; i--) t2 += v[n - 1].first - v[i].first + 1;
    res[v[n - 1].second] = t2;

    for (int i = 1; i < n - 1; i++) {
        ll delta = v[i].first - v[i - 1].first;
        t += delta * (i - 1);
        t -= delta * (n - 1 - i);
        res[v[i].second] = t;
    }
    for (auto u : res) cout << u << " ";
    cout << endl;
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
