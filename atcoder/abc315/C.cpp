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
    map<int, multiset<int>> all;
    for (int i = 0; i < n; i++) {
        int f, s; cin >> f >> s;
        all[f].emplace(s);
    }
    int res = INT_MIN;
    int mx1 = INT_MIN, mx2 = INT_MIN;
    debug(all);
    for (auto [f, s] : all) {
        auto maior = s.rbegin();
        if (*maior > mx2) {
            mx2 = *maior;
            if (mx2 > mx1) swap(mx1, mx2);
        }
        if (s.size() > 1) {
            auto segundo = maior;
            segundo++;
            int h = *maior + *segundo / 2;
            res = max(res, h);
        }
    }
    for (auto [f, s] : all) {
        auto maior = s.rbegin();
        if (*maior == mx1) {
            int h = mx2 + *maior;
            res = max(res, h);
        } else {
            int h = mx1 + *maior;
            res = max(res, h);
        }
    }
    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
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
