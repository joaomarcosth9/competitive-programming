#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

string s, t;
const int N = 260;
int n;
bool dp[N][N][N][3];
char res[N][N][N][3];
tuple<int, int, int> par[N][N][N][3];

void solve() {
    cin >> s;
    n = int(s.size());

    bool dr = (n & 1);

    for (int i = 0; i + 1 < n; i += 2) {
        string now = s.substr(i, 2);
        if (now != ">>" && now != "<<") dr = 1;
    }

    if (dr) {
        cout << "Keine Loesung" << endl;
        return;
    }

    t = "$";

    for (int i = 0; i + 1 < n; i += 2) {
        string now = s.substr(i, 2);
        if (now == ">>") {
            t.push_back('2');
        } else if (now == "<<") {
            t.push_back('1');
        } else assert(false);
    }

    s = t;
    n = int(s.size() - 1);

    dp[0][0][0][0] = 1;

    // dp[i][<<][>>][last open]

    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') { // "<<"
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= n; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (j > 0 and dp[i - 1][j - 1][k][l]) {
                            dp[i][j][k][1] = 1;
                            par[i][j][k][1] = {i - 1, j - 1, k};
                            res[i][j][k][1] = '[';
                        }
                        if (dp[i - 1][j][k + 1][2]) {
                            if (j == 0 and k == 0) {
                                dp[i][j][k][0] = 1;
                                par[i][j][k][0] = {i - 1, j, k + 1};
                                res[i][j][k][0] = ']';
                            } else {

                            }
                        }
                    }
                }
            }
        } else { // ">>"
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= n; k++) {
                    if (dp[i - 1][j + 1][k]) {
                        dp[i][j][k] = 1;
                        par[i][j][k] = {i - 1, j + 1, k};
                        res[i][j][k] = ']';
                    }
                    if (k > 0 and dp[i - 1][j][k - 1]) {
                        dp[i][j][k] = 1;
                        par[i][j][k] = {i - 1, j, k - 1};
                        res[i][j][k] = '[';
                    }
                }
            }
        }
    }

    if (dp[n][0][0]) {
        tuple<int, int, int> now = {n, 0, 0};
        string ans;

        while (now != tuple{0, 0, 0}) {
            auto [a, b, c] = now;
            cout << a << " " << b << " " << c << " | " << res[a][b][c] << endl;
            ans.push_back(res[a][b][c]);
            now = par[a][b][c];
        }

        reverse(ans.begin(), ans.end());

        cout << ans << endl;
    } else {
        cout << "Keine Loesung" << endl;
    }

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
