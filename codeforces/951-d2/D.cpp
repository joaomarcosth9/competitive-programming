#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
#define int ll

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    char c = s[n - 1];
    vector<int> eq(n);
    eq[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == s[i + 1]) {
            eq[i] = eq[i + 1] + 1;
        } else {
            eq[i] = 1;
        }
    }
    vector<int> dp(n);
    for (int i = n - 1; i >= 0; i--) {
        if (eq[i] >= k) {
            dp[i] = 1;
            if (eq[i] == k && i + k < n) {
                dp[i] += dp[i + k];
            }
        }
    }

    debug(dp);
    if (dp[0] * k == n) {
        cout << n << endl;
        return;
    }

    int best = -1;

    for (int i = 0, x = 1; x < n; i++, x++) {
        int seq = dp[i + 1] * k;
        int right = (n - seq - x);
        if (right >= k) {
            continue;
        }
        debug(i, x, seq, right);
        // right < k
        int first_idx = x + seq;
        if (first_idx == n) {
            debug(first_idx == n);
            debug(dp[0] * k);
            if ((x % k) || dp[0] * k < x) {
                continue;
            } else {
                // ver se o prefixo realmente encaixa la
                if (s[i] != s[n - 1]) {
                    best = x;
                }
            }
        } else {
            // ver tb se o prefixo encaixa la
            debug(first_idx);
            debug(first_idx + eq[first_idx]);
            // first_idx do right
            if (first_idx + eq[first_idx] < n || (s[first_idx] == s[first_idx - 1])) {
                continue;
            } else {
                // right eh tudo igual
                int eq_here = min(dp[0] * k, x - (x % k));
                if (eq_here == x) {
                    continue;
                }
                int first_wrong = eq_here;
                int diff_here = x - eq_here;
                debug(eq_here, diff_here, right);
                if (diff_here + right != k) {
                    continue;
                }
                if (eq_here == 0) {
                    if (x >= k || eq[0] < x) {
                        continue;
                    } else {
                        if (s[0] == s[n - 1]) best = x;
                    }
                } else {
                    // eq_here > 0
                    int fit = diff_here;
                    if (diff_here >= k) {
                        continue;
                    }
                    int last = i - diff_here;
                    debug(last, s[i], s[last]);
                    if (s[i] == s[last]) {
                        continue;
                    }
                    int fst = last + 1;
                    debug(fst, eq[fst]);
                    if (eq[fst] < diff_here) {
                        continue;
                    }
                    if (s[i] == s[n - 1]) {
                        best = x;
                    }
                }
            }
        }
    }

    debug(best);
    cout << best << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}