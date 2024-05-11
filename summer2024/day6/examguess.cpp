#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;

const int N = 5050;
int n, k;
ld dp[N][2 * N + 1000];
ld a[N], e[N];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++) {
        e[i] = 1.0l - a[i];
    }

    dp[0][N] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= N + n; j++) {
            dp[i][j] = a[i] * dp[i - 1][j - 1] + e[i] * dp[i - 1][j + 1];
        }
    }

    ld ans = 0;
    for (int i = 1; i <= n; i++) {
        ld now = 0;
        for (int j = N + k; j <= N + n; j++) {
            now += dp[i][j];
        }
        ans = max(ans, now);
    }
    cout << setprecision(10) << fixed << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
