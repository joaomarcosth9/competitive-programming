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
    int a, b, c; cin >> a >> b >> c;
    string l, r;

    int aa = a;
    if (aa) {
        l = "00";
        aa--;
        while (aa--) l += "0";
    }
    int cc = c;
    if (cc) {
        r = "11";
        cc--;
        while (cc--) r += "1";
    }
    debug(l, r);
    int sz = (a + b + c) + 1;
    sz -= l.size();
    sz -= r.size();
    int now = -1;

    cout << l;
    bool print = 0;
    char pchar = -1;

    debug(sz);

    if (r.size() && l.size()) {
        now = 1;
        if (sz & 1) {
            print = 1;
            pchar = '0';
            sz--;
        }
    } else if (l.size()) {
        now = 1;
    } else if (r.size()) {
        now = 0;
        if (sz & 1) {
            // ok
        } else {
            now = 1;
        }
    } else {
        now = 0;
    }

    while (sz--) {
        cout << char(now + 48);
        now ^= 1;
    }

    debug(print);

    cout << r;
    if (print) cout << pchar;
    cout << endl;
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
