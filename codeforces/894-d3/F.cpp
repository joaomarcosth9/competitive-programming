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
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto &x) { return res; }
#define L2(res...) [&](const auto &x, const auto &y) { return res; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

void solve() {
    ll w, f;
    cin >> w >> f;

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int sum = accumulate(all(a), 0);
    const ll ac = 1e6 + 1;

    if (w >= ac || f >= ac) {
        cout << 1 << endl;
        return;
    }

    ll l = 1, r = ac + 10010;

    auto test = [&](int sec) {
        const ll W = w * sec;
        const ll F = f * sec;
        if (W > ac || F > ac) {
            return true;
        }

        vector<bitset<ac>> dp(n + 1, bitset<ac>());

        // onde eu to por quanto mana tenho

        dp[0][W] = 1;
        ll pref = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= W; j++)
                if (dp[i][j]) {
                    // tenho j agua
                    // ja matei pref qtd de vida
                    int Wd = W - j;
                    int Wf = pref - Wd;
                    int k = F - Wf;
                    if (j >= a[i]) {
                        dp[i + 1][j - a[i]] = 1;
                    }
                    if (k >= a[i]) {
                        dp[i + 1][j] = 1;
                    }
                }
            pref += a[i];
        }

        bool db = 0;
        for (int i = 0; i <= W; i++) db |= dp[n][i];
        return db;
    };

    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (test(mid)) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        int TEST = 1;
        while (TEST <= TC) {
            cerr << "[Testcase " << TEST << "]" << endl;
            solve();
            ++TEST;
        }
    } else
        solve();
}
