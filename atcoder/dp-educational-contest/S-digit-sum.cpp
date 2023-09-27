#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define endl '\n'
#define cerr                                                                                                           \
    if (false) cerr
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

string L, R;
const int mod = 1e9 + 7;
int d;
const int maxs = 1e4 + 10, maxd = 105;
ll p10[maxs];
ll dp[maxs][maxd][2];

ll dpp(int dig, int modd, bool mx, bool is_zero) {
    // if (dig == -1 && is_zero) return 0;
    if (dig == -1) return modd == 0;
    if (dp[dig][modd][mx] != -1) return dp[dig][modd][mx];

    ll ret = 0;

    for (int i = 0; i <= 9; i++) {
        bool valid = !mx || R[dig] >= i + '0';
        if (valid) {
            int new_modd = (modd + i) % d;
            bool new_mx = mx && R[dig] == i + '0';
            bool new_is_zero = is_zero && i == 0;
            ret = (ret + dpp(dig - 1, new_modd, new_mx, new_is_zero)) % mod;
        }
    }
    return dp[dig][modd][mx] = ret;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> R;
    cin >> d;

    reverse(begin(R), end(R));
    while (R.size() < 1e4 + 5) {
        R += "0";
    }
    cout << (dpp(10004, 0, 1, 1) - 1 + mod) % mod << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    auto start = chrono::steady_clock::now();
    if (TC) {
        cin >> TC;
        start = chrono::steady_clock::now();
        int TEST = 0;
        while (TEST < TC) {
            cerr << "[Testcase " << TEST + 1 << "]" << endl;
            solve();
            ++TEST;
            cerr << endl;
        }
    } else
        solve();
#ifdef LOCAL_DEBUG
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "\nTime taken: ";
    cerr << chrono::duration<double, milli>(diff).count() << " ms" << endl;
#endif
}
