#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

const int N = 2505;
int n, k;
string s;
ll dp[N][26], par[N][26];

void solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 26; j++) {
            dp[i][j] = -1e9;
        }
    }

    cin >> k;
    cin >> s;
    n = (int)size(s);

    if (s[0] == '.') {
        for (int i = 0; i < k; i++) {
            dp[0][i] = 0;
        }
    } else dp[0][s[0] - 'A'] = 0;

    for (int i = 1; i < n; i++) {
        if (s[i] == '.') {
            for (int j = 0; j < k; j++) {
                for (int last = 0; last < k; last++) {
                    bool diff = j != last;
                    if (dp[i - 1][last] + diff > dp[i][j]) {
                        dp[i][j] = dp[i - 1][last] + diff;
                        par[i][j] = last;
                    }
                }
            }
        } else {
            int j = s[i] - 'A';
            for (int last = 0; last < k; last++) {
                bool diff = j != last;
                if (dp[i - 1][last] + diff > dp[i][j]) {
                    dp[i][j] = dp[i - 1][last] + diff;
                    par[i][j] = last;
                }
            }
        }

    }

    string ans;
    ll p = -1, mx = -1, l = -1;
    for (int j = 0; j < k; j++) {
        if (dp[n - 1][j] > mx) {
            mx = dp[n - 1][j];
            l = j;
            p = par[n - 1][j];
        }
    }
    ans += char(l + 'A');
    for (int i = n - 2; i >= 0; i--) {
        ans += char(p + 'A');
        p = par[i][p];
    }
    reverse(begin(ans), end(ans));
    cout << ans << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
