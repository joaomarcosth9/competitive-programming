#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int M = 5005;

bool possible[M][M];

int dp[M][M];

vector<int> queries1[M], queries2[M];

vector<int> pref1[M], pref2[M];

void solve() {
    int n, m;
    cin >> n >> m;

    int cur = 0;

    vector<int> c1, c2;

    possible[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        int r;
        cin >> r;

        if (r == 0) {

            sort(c1.begin(), c1.end());
            sort(c2.rbegin(), c2.rend());

            queries1[cur] = c1;
            queries2[cur] = c2;

            c1.clear();
            c2.clear();

            cur++;
        } else if (r > 0) {
            // check da p1
            c1.push_back(abs(r));
        } else {
            // check da p2
            c2.push_back(abs(r));
        }

    }

    sort(c1.begin(), c1.end());
    sort(c2.rbegin(), c2.rend());

    queries1[cur] = c1;
    queries2[cur] = c2;

    for (cur = 1; cur <= m; cur++) {
        for (int p1 = 0; p1 <= cur; p1++) {
            possible[cur][p1] |= possible[cur - 1][p1];
            if (p1 > 0) possible[cur][p1] |= possible[cur - 1][p1 - 1];
        }

        int has1 = 0, has2 = int(queries2[cur].size());
        int ptr1 = 0, ptr2 = 0;

        for (int p1 = 0; p1 <= cur; p1++) {
            int p2 = cur - p1;

            while (ptr1 < int(queries1[cur].size()) && queries1[cur][ptr1] <= p1) {
                has1++;
                ptr1++;
            }

            while (ptr2 < int(queries2[cur].size()) && queries2[cur][ptr2] > p2) {
                has2--;
                ptr2++;
            }

            if (possible[cur][p1]) {
                // posso ter chego aqui com [p1, p2]
                dp[cur][p1] = max(dp[cur - 1][p1], (p1 > 0 ? dp[cur - 1][p1 - 1] : 0)) + has1 + has2;
            }

        }

    }

    cout << *max_element(dp[m], dp[m] + M) << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}