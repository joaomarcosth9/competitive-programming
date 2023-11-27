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

vector<int> res1, res2;
int n, k;

bool solve() {
    cin >> n >> k;
    res1.assign(k, 1);
    res2.assign(k, 2);
    res1[k - 1] = 0;
    res2[k - 1] = 0;
    res1[k - 1] = n - accumulate(all(res1), 0);
    res2[k - 1] = n - accumulate(all(res2), 0);
    return (res1[k - 1] % 2 && res1[k - 1] > 0) || ((res2[k - 1] % 2) == 0 && res2[k - 1] > 0);
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
        bool ok = solve();
        cout << (ok ? "Yes" : "No") << endl;
        if (ok) {
            if (res1[k - 1] % 2 && res1[k - 1] > 0) {
                for (auto u : res1) cout << u << " ";
                cout << endl;
            } else if ((res2[k - 1] % 2) == 0 && res2[k - 1] > 0) {
                for (auto u : res2) cout << u << " ";
                cout << endl;
            }
        }
        TEST += 1;
    }
}
