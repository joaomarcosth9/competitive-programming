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
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> sellers(m);

    for (int &i : sellers) cin >> i;
    sort(begin(sellers), end(sellers));

    bool inserted = 0;
    if (sellers[0] != 1) {
        sellers.insert(begin(sellers), 1);
        inserted = 1;
        m += 1;
    } // I always need to have one in the beggining

    vector<int> pref(m + 1);
    // pref[i] = how many cookies did she eat until seller i
    int last = 1;
    pref[0] = 1;

    for (int i = 1; i < m; i++) {

        int j = sellers[i];
        int dist = j - last;

        ll delta = 1;
        delta += (dist) / d;
        if (dist % d == 0) delta -= 1;

        pref[i] = pref[i - 1] + delta;

        last = j;
    }

    int _dist = n - last;
    pref[m] = pref[m - 1] + (_dist) / d;

    map<int, int> ress;
    ress[0] = pref[m];

    if (true) {
        last = sellers[m - 2];

        ll rest = pref[m - 2];

        int dist = n - last;

        rest += (dist / d);
        ress[m - 1] = rest;
    }

    for (int i = 1; i < m - 1; i++) {
        last = sellers[i - 1];
        int j = sellers[i + 1];

        ll rest = pref[i - 1] + (pref[m] - pref[i + 1]) + 1;

        int dist = j - last;
        rest += (dist / d);

        if (dist % d == 0) rest--;

        ress[i] = rest;
    }

    ll best = 1e18;
    for (auto [k, v] : ress) {
        if (k == 0 && inserted) continue;
        best = min(best, v);
    }

    int pop = 0;

    for (auto [k, v] : ress) {
        if (k == 0 && inserted) continue;
        debug(v == best, k);
        pop += v == best;
    }

    cout << best << " " << pop << endl;
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
