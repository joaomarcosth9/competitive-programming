#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

#define int long long
const int maxn = 1.1e5, INF = 1e18;
int dp[maxn][200], n;
string s;
vector<int> v;
string hard = "hard";

int dpp(int i, int j) {
    if (i == n) return dp[i][j] = 0;
    if (dp[i][j] != -1) return dp[i][j];
    // s[i] eh a letra q eu to agora
    // j eh a letra q eu to procurando
    int tirar = v[i] + dpp(i + 1, j);
    int next = j;
    if (s[i] == j) {
        if (s[i] == 'd') {
            return dp[i][j] = tirar;
        }
        for (int k = 0; k < 3; k++) {
            if (hard[k] == s[i]) {
                next = hard[k + 1];
            }
        }
    }
    int ficar = dpp(i + 1, next);
    return dp[i][j] = min(tirar, ficar);
}

void solve() {
    cin >> n >> s;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 200; j++) dp[i][j] = -1;
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    dpp(0, 'h');
    cout << dp[0]['h'] << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
