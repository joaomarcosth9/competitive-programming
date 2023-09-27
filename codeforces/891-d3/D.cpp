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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;
    vector<int> c(n);
    for (int i = 0; i < n; i++) c[i] = a[i] - b[i];
    int u = *max_element(begin(c), end(c));
    int C = count(begin(c), end(c), u);
    cout << C << endl;
    for (int i = 0; i < n; i++) {
        if (c[i] == u) cout << i + 1 << " ";
    }
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
