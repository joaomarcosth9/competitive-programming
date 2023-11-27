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

string w;

bool solve() {
    int n, x;
    string s; cin >> s >> x;
    n = size(s);
    for (char &i : s) i -= '0';
    w = string (n, -1);

    for (int i = 0; i < n; i++) {
        if (s[i] == 0) {
            if (i - x >= 0) {
                w[i - x] = 0;
            }
            if (i + x < n) {
                w[i + x] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == 1) {
            bool ok = 0;
            if (i - x >= 0) {
                if (w[i - x] != 0) {
                    w[i - x] = 1;
                    ok = 1;
                }
            }
            if (!ok && i + x < n) {
                if (w[i + x] != 0) {
                    w[i + x] = 1;
                    ok = 1;
                }
            }
            if (!ok) return 0;
        }
    }

    for (int i = 0; i < n; i++) if (w[i] == 2) {
        w[i] = 1;
    }
    for (int i = 0; i < n; i++) if (w[i] == -1) {
        w[i] = 0;
    }

    string t(n, -1);
    for (int i = 0; i < n; i++) {
        if (i - x >= 0 && w[i - x] == 1) t[i] = 1;
        else if (i + x < n && w[i + x] == 1) t[i] = 1;
        else t[i] = 0;
    }

    assert(t == s);

    return 1;
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
        /* cout << (solve() ? "Yes" : "No") << endl; */
        bool ok = solve();
        if (ok) {
            for (auto u : w) cout << char(u + '0');
            cout << endl;
        } else cout << -1 << endl;
        TEST += 1;
    }
}
