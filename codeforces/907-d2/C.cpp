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

int solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    sort(all(a));
    ll res = 0, x = 0;

    debug(a);
    int r = n - 1;
    for (int i = 0; i <= r; i++) {
        debug(i, res);
        if (a[i] == 0) continue;
        if (i == r) {
            debug(res, a[i], x);

            if (x >= a[i]) {
                res++;
                break;
            } else if (a[i] <= 2) {
                res += a[i];
                break;
            }

            res += (a[i] - x + 1) / 2 + 1;

            break;
        }

        if (x + a[i] >= a[r]) {
            res += a[r] - x;
            res++;
            a[i] -= a[r] - x;
            a[r] = 0;
            x = 0;
            r--;
            i--;
        } else {
            x += a[i];
            res += a[i];
        }

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
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
