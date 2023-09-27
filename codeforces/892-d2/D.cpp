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
    int n; cin >> n; // number of portals
    vector<int> compr;
    vector<array<int, 2>> portals(n);
    for (int i = 0; i < n; i++) {
        int l, r, a, b;
        cin >> l >> r >> a >> b;
        portals[i] = {l, b};
    }
    sort(begin(portals), end(portals));

    int q; cin >> q;
    vector<int> queries(q);
    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        queries[i] = x;
    }

    vector<array<int, 2>> nportals;
    for (auto &u : portals) {
        int l = u[0], r = u[1];
        if (nportals.empty()) { nportals.emplace_back(u); continue; }
        if (nportals.back()[1] >= l) {
            nportals.back()[1] = max(nportals.back()[1], r);
        } else {
            nportals.emplace_back(u);
        }
    }

    for (int i = 0; i < q; i++) {
        int x = queries[i];
        auto u = lower_bound(begin(nportals), end(nportals), array<int, 2> {x + 1, -1});
        --u;
        int res = x;
        if (u != nportals.end()) res = max(res, (*u)[1]);
        cout << res << " ";
    }
    cout << endl;

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
