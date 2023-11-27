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

bool solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    int sz = 1;
    while (sz < n) sz *= 2;
    a.resize(sz, INT_MAX);
    int pot = 1;
    bool ok = 1;
    int l = 0, r = 0;
    while (r <= sz) {
        ok &= is_sorted(begin(a) + l, begin(a) + r + 1);
        debug(l, r);
        while (l <= r) a[l++] = 0;
        r = (r * 2) + 1;
    }
    return ok;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        /* solve(); */
        /* cout << solve() << endl; */
        cout << (solve() ? "YES" : "NO") << endl;
        TEST += 1;
    }
}
