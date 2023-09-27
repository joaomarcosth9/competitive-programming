#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define endl '\n'
#define cerr if (false) cerr
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

void solve() {
    int n; cin >> n;
    vector<vector<int>> v(n);
    int u = INT_MAX;
    ll cres = 0;
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        vector<int> a(m);
        for (int &j : a) {
            cin >> j;
            u = min(u, j);
        }
        sort(begin(a), end(a));
        cres += a[0];
        v[i] = a;
        debug(a);
    }
    vector<int> res;
    for (int i = 0; i < n; i++) {
        auto& a = v[i];
        res.emplace_back(a[1]);
    }
    sort(rbegin(res), rend(res));
    res.pop_back();
    cout << accumulate(begin(res), end(res), 0ll) + u << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    auto start = chrono::steady_clock::now();
    if (TC) { cin >> TC;
        start = chrono::steady_clock::now();
        int TEST = 0;
        while (TEST < TC) {
            cerr << "[Testcase " << TEST + 1 << "]" << endl;
            solve();
            ++TEST;
            cerr << endl;
        }
    } else solve();
#ifdef LOCAL_DEBUG
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "\nTime taken: ";
    cerr << chrono::duration <double, milli> (diff).count() << " ms" << endl;
#endif
}
