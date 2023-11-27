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
    vector<int> v(3);
    for (int i = 0; i < 3; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    if (v[2] + v[1] >= 10) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    auto start = chrono::steady_clock::now();
    if (TC) { cin >> TC;
        start = chrono::steady_clock::now();
        int TEST = 0;
        while (TEST < TC) {
            cerr << "[Testcase " << TEST << "]" << endl;
            solve();
            ++TEST;
        }
    } else solve();
#ifdef LOCAL_DEBUG
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "\nTime taken: ";
    cerr << chrono::duration <double, milli> (diff).count() << " ms" << endl;
#endif
}
