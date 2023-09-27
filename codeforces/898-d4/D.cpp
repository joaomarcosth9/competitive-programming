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
void out(bool ans) { cout << (ans ? "YES" : "NO") << endl; }

ll solve() {
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    int L = 0, R = n;
    int ans = -1;

    int used = 0;
    for (int i = 0; i < n;) {
        if (s[i] == 'B') {
            i += k;
            used += 1;
        } else i++;
    }

    return used;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) { cin >> TC;
        int TEST = 1;
        while (TEST <= TC) {
            cerr << "[Testcase " << TEST << "]" << endl;
            /* solve(); */
            cout << solve() << endl;
            /* cout << (solve() ? "YES" : "NO") << endl; */
            ++TEST;
        }
    } else solve();
}
