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
#define int ll

void solve() {
    int p, f, n, m, s, w; cin >> p >> f >> n >> m >> s >> w;
    if (p > f) swap(p, f);
    if (s > w) swap(s, w), swap(n, m);

    int res = 0;

    for (int i = 0; i <= n; i++) {
        if (p < i * s) break;
        int nn = n, mm = m;
        int pp = p, ff = f;

        int now = 0;

        int add = i;
        now += add;
        n -= add;
        p -= add * s;
        debug(i, now, p, f);

        add = min(m, p / w);

        now += add;
        p -= add * w;
        m -= add;
        debug(i, now, p, f);

        add = min(n, f / s);

        now += add;
        f -= add * s;
        n -= add;
        debug(i, now, p, f);

        add = min(m, f / w);
        now += add;
        f -= add * w;
        m -= add;
        debug(i, now, p, f);

        res = max(res, now);

        swap(n, nn), swap(m, mm);
        swap(p, pp), swap(f, ff);
    }

    cout << res << endl;
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
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
