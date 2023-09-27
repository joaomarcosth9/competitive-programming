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
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll sum = accumulate(all(a), 0ll);

    if (sum % n != 0) {
        cout << "NO" << endl;
        return;
    }

    map<ll, int> poss;

    ll av = sum / n;
    map<ll, vector<ii>> Path;

    for (int i = 0; i < 32; i++) {
        ll u = (1ll << i);
        poss[u] = 1;
        Path[u].eb(i, -1);
        u = -(1ll << i);
        poss[u] = 1;
        Path[u].eb(-1, i);
        for (int j = 0; j < 32; j++) {
            u = (1ll << i) - (1ll << j);
            poss[u] = 1;
            debug(u);
            Path[u].eb(i, j);
        }
    }

    for (int i = 0; i < n; i++) {
        int diff = a[i] - av;
        if (!poss.count(diff)) {
            cout << "NO" << endl;
            return;
        }
    }

    debug(av);

    map<int, int> used;

    for (int i = 0; i < n; i++) {
        ll diff = a[i] - av;
        debug(diff);
        debug(Path[diff]);
        auto [p, m] = Path[diff].back();
        used[p] += 1;
        used[m] -= 1;
    }

    bool db = 1;
    for (auto [k, v] : used) {
        db &= v == 0;
    }

    if (db) {
        cout << "YES" << endl;
        return;
    }

    debug(used);

    auto it = rbegin(used);

    while (it != rend(used)) {
        auto [k, v] = *it;
        if (k < -400) break;
        used[k - 1] -= v;
        debug(k, v);
        it->second = 0;
        it++;
    }

    debug(used);

    db = 1;
    for (auto [k, v] : used) {
        db &= v == 0;
    }

    if (db) {
        cout << "YES" << endl;
    } else
        cout << "NO" << endl;
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
