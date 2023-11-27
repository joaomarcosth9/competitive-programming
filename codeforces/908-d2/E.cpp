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
typedef __int128_t LL;
typedef tuple<int, int, int> i3;

ll solve() {
    int n; cin >> n;
    vector<ll> sz(n);
    vector<ll> l(n), r(n);
    vector<vector<ll>> num(n);
    ll minlen = 0, maxlen = 0;
    vector<ll> vals;
    map<ll, vector<int>> where;
    map<ll, map<int, ll>> freq;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m >> l[i] >> r[i];
        minlen += l[i];
        maxlen += r[i];
        num[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> num[i][j];
            where[num[i][j]].eb(i);
            vals.eb(num[i][j]);
        }
        for (int j = 0; j < m; j++) {
            ll f; cin >> f;
            sz[i] += f;
            freq[num[i][j]][i] = f;
        }
    }
    sort(all(vals));
    vals.erase(unique(all(vals)), end(vals));
    debug(minlen, maxlen);
    debug(vals);
    int N = size(vals);

    if (vals[0] > minlen || vals.back() < maxlen) return 0ll;

    if (maxlen - minlen + 1 > N) return 0ll;

    ll res = LLONG_MAX;
    for (ll len = minlen; len <= maxlen; len++) {
        debug(len);
        ll tres = 0;
        debug(where[len]);
        ll now = maxlen;
        for (int i : where[len]) now -= r[i];
        debug(now);
        for (int i : where[len]) {
            ll flen = freq[len][i];
            ll good = sz[i] - flen;
            if (good < r[i]) {
                if (good < l[i]) {
                    tres += l[i] - good;
                    now += l[i];
                } else {
                    now += good;
                }
            } else {
                now += r[i];
            }
        }
        tres += max(0ll, len - now);
        debug(tres);
        res = min(res, tres);
    }
    return res;
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
        cout << solve() << endl;
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
