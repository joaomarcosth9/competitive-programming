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
    int q; cin >> q;
    vector<ll> freq(63);

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x;
            freq[x]++;
        } else {
            ll w; cin >> w;
            ll done = 0;
            auto f2 = freq;
            for (int i = 0; i < 60; i++) {
                if (w & (1ll << i)) {
                    if (f2[i] == 0) {
                        done = -1;
                        break;
                    }
                    done += (1ll << i);
                    f2[i]--;
                }
                f2[i + 1] += f2[i] / 2;
            }
            cout << (done == w ? "Yes" : "No") << endl;
        }
    }
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
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
