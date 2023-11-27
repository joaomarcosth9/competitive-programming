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
    vector<ll> v(3);
    for (ll &i : v) cin >> i;
    sort(rall(v));
    ll sum = accumulate(all(v), 0ll);
    for (int i = 0; i <= 3; i++) {
        ll cnt = 3 + i;
        if (sum % cnt) continue;
        ll each = sum / cnt;
        auto a = v;
        bool db = 1;
        debug(a, cnt, each);
        int done = 0;
        for (int j = 0; j < (int)a.size(); j++) {
            if (a[j] == each) continue;
            if (a[j] < each) db = 0;
            ll now = a[j] - each;
            a[j] = each;
            if (now && done < i) a.eb(now), done++;
        }
        if (!db) continue;
        if (a == vector<ll> (cnt, each)) return 1;
    }
    return 0;
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
