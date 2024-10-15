#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 100005;
const int S = 100005;

void subset_sum(vector<int> a) {
    // O(n * sum)
    int n = (int)a.size();
    vector<bitset<S>> dp(n + 1);
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        dp[i + 1] = dp[i] | (dp[i] << a[i]);
    }
    for (int i = 1; i < S; i++) {
        if (dp[n][i]) cout << i << ' ';
    }
    cout << endl;
    int x;
    cin >> x;
    // recover answer for sum = x
    if (dp[n][x]) {
        int lin = n, col = x;
        while (lin > 0 && col > 0) {
            if (dp[lin - 1][col]) {
                lin--;
            } else {
                cout << a[lin - 1] << ' ';
                col -= a[lin - 1];
            }
        }
    } else {
        cout << "No solution";
    }
    cout << endl;
}

void subset_sum_sqrt_S(vector<int> a) {
    // O(n * sqrt(sum))
    sort(a.begin(), a.end());
    map<int, vector<int>> b;
    for (int i = (int)a.size() - 1; i >= 0; i--) {
        b[a[i]].push_back(i);
    }
    vector<int> new_a;
    vector<vector<int>> real;
    for (auto [x, pos] : b) {
        int cnt = (int)pos.size();
        for (int p = 1; p <= cnt; p *= 2) {
            new_a.push_back(p * x);
            vector<int> cur;
            for (int j = 0; j < p; j++) {
                cur.push_back(pos.back());
                pos.pop_back();
            }
            real.push_back(cur);
            cnt -= p;
        }
        if (cnt > 0) {
            new_a.push_back(cnt * x);
            vector<int> cur;
            for (int j = 0; j < cnt; j++) {
                cur.push_back(pos.back());
                pos.pop_back();
            }
            real.push_back(cur);
        }
    }
    int n = (int)new_a.size();
    vector<bitset<S>> dp(n + 1);
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        dp[i + 1] = dp[i] | (dp[i] << new_a[i]);
    }
    for (int i = 1; i < S; i++) {
        if (dp[n][i]) cout << i << ' ';
    }
    cout << endl;
    int x;
    cin >> x;
    // recover answer for sum = x
    if (dp[n][x]) {
        int lin = n, col = x;
        while (lin > 0 && col > 0) {
            if (dp[lin - 1][col]) {
                lin--;
            } else {
                for (auto u : real[lin - 1]) {
                    cout << a[u] << ' ';
                }
                col -= new_a[lin - 1];
            }
        }
    } else {
        cout << "No solution";
    }
    cout << endl;
}

void solve() {
    vector<int> a = {3, 2, 2, 3, 3, 3, 2};
    cout << "a: ";
    for (int x : a) {
        cout << x << ' ';
    }
    cout << endl;
    subset_sum(a);
    subset_sum_sqrt_S(a);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
