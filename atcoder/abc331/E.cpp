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
typedef tuple<int, int, int, int> i4;

void solve() {
    int n, m, l; cin >> n >> m >> l;
    vector<pair<ll, ll>> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int j = 0; j < m; j++) {
        cin >> b[j].first;
        b[j].second = j;
    }

    vector<set<int>> cant(n);
    for (int i = 0; i < l; i++) {
        int c, d; cin >> c >> d;
        cant[c - 1].emplace(d - 1);
    }

    sort(all(a));
    sort(all(b));

    if (n == 1) {
        for (int i = m - 1; i >= 0; i--) {
            if (!cant[0].count(b[i].second)) {
                cout << a[0].first + b[i].first << endl;
                return;
            }
        }
        assert(false);
    }
    if (m == 1) {
        for (int i = n - 1; i >= 0; i--) {
            if (cant[a[i].second].empty()) {
                cout << a[i].first + b[0].first << endl;
                return;
            }
        }
        assert(false);
    }

    vector<i3> sum;
    sum.eb(a.back().first + b.back().first, a[n - 1].second, b[m - 1].second);

    set<i3> pq;

    if (n > 1) {
        pq.emplace(a[n - 2].first + b[m - 1].first, n - 2, m - 1);
    }
    if (m > 1) {
        pq.emplace(a[n - 1].first + b[m - 2].first, n - 1, m - 2);
    }

    while ((int)sum.size() <= l) {
        auto [nsum, ida, idb] = *rbegin(pq);
        pq.erase(--end(pq));
        sum.eb(nsum, a[ida].second, b[idb].second);
        bool done = 0;
        if (ida > 0) {
            pq.emplace(a[ida - 1].first + b[idb].first, ida - 1, idb);
            done = 1;
        }
        if (idb > 0) {
            pq.emplace(a[ida].first + b[idb - 1].first, ida, idb - 1);
            done = 1;
        }
        if (!done) break;
    }

    sort(rall(sum));

    for (int i = 0; i < (int)sum.size(); i++) {
        auto [res, ida, idb] = sum[i];
        if (cant[ida].count(idb)) continue;
        debug(ida, idb);
        cout << res << endl;
        return;
    }
    assert(false);

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
