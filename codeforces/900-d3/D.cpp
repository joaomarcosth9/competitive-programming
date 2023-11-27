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

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> L(k), R(k);
    for (int i = 0; i < k; i++) cin >> L[i];
    for (int i = 0; i < k; i++) cin >> R[i];
    for (int i = 0; i < k; i++) L[i]--;
    for (int i = 0; i < k; i++) R[i]--;
    set<i3> lr;
    for (int i = 0; i < k; i++) {
        lr.emplace(L[i], R[i], i);
    }

    int q; cin >> q;

    vector<vector<int>> pref(k);
    for (int i = 0; i < k; i++) {
        pref[i].resize(R[i] - L[i] + 2);
    }

    debug(L);
    debug(R);

    while (q--) {
        int x; cin >> x;
        x--;
        debug(x);
        auto it = lr.upper_bound(make_tuple(x, INT_MAX, INT_MAX));
        --it;
        auto [le, ri, id] = *it;
        int LE = x - le;
        int RI = (ri - le) - (LE);
        if (RI < LE) swap(RI, LE);
        debug(LE, RI);
        pref[id][LE]++;
        pref[id][RI + 1]--;
    }
    for (int i = 0; i < k; i++) {
        for (int j = 1; j < (int)pref[i].size(); j++) pref[i][j] += pref[i][j - 1];
    }
    for (int i = 0; i < k; i++) {
        int idx = L[i], idx2 = R[i];
        for (int j = 0; j < ((int)pref[i].size() - 1) / 2; j++) {
            if (pref[i][j] & 1) {
                swap(s[idx], s[idx2]);
            }
            idx++, idx2--;
        }
    }
    cout << s << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
