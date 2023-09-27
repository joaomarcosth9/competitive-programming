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
    vector<int> a(n);
    for (int &i : a) cin >> i;
    set<int> win;
    set<int> l;
    set<int> all;
    all.insert(a[0]);
    win.insert(a[0]);
    for (int i = 1; i < n; i++) {
        auto u = l.begin();
        int smaller = *all.begin();
        int uu = *win.begin();

        all.emplace(a[i]);

        if (a[i] < smaller) {
            win.emplace(a[i]);
            continue;
        }

        if (u == l.end()) {
            l.emplace(a[i]);
            continue;
        }

        if (a[i] < *u) {
            l.emplace(a[i]);
        } else {
            win.emplace(a[i]);
        }
    }
    cout << n - win.size() << endl;
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
