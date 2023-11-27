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
#define int ll
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

void solve() {
    int n; cin >> n;
    vector<ii> a(n);
    for (auto &[l, r] : a) cin >> l >> r;

    vector<int> x, y;
    for (auto &[l, r] : a) x.eb(l), y.eb(r);

    sort(all(x));
    sort(all(y));

    ll dx = x[0];
    ll dy = y[0];
    for (int i = 0; i < n; i++) x[i] -= dx;
    for (int i = 0; i < n; i++) y[i] -= dy;

    ll mh = accumulate(all(x), 0ll);
    vector<int> line(x[n - 1] + 1);
    for (int i = 0; i < n; i++) line[x[i]]++;
    ll best = mh;
    int where = 0;
    int rguys = n - line[0];
    int lguys = 0;

    debug(line);
    debug(x, mh);
    for (int i = 1; i <= x[n - 1]; i++) {
        mh -= rguys;
        rguys -= line[i];
        lguys += line[i - 1];
        mh += lguys;
        debug(i, mh);
        if (mh < best) {
            best = mh;
            where = i;
        }
    }
    cout << where + dx << " ";

    mh = accumulate(all(y), 0ll);
    line.assign(y[n - 1] + 1, 0);
    for (int i = 0; i < n; i++) line[y[i]]++;
    best = mh;
    where = 0;
    rguys = n - line[0];
    lguys = 0;

    for (int i = 1; i <= y[n - 1]; i++) {
        mh -= rguys;
        rguys -= line[i];
        lguys += line[i - 1];
        mh += lguys;
        if (mh < best) {
            best = mh;
            where = i;
        }
    }

    cout << where + dy << endl;

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
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
