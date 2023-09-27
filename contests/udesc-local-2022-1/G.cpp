#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 60;
typedef long long ll;

int n, m;
ll M[MAX][MAX];
ll pref[MAX][MAX];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++) {
            M[i][j] = 0;
            pref[i][j] = 0;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> M[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            pref[i][j] = M[i][j] + pref[i][j - 1];
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            pref[i][j] = pref[i][j] + pref[i - 1][j];
        }
    ll res = LLONG_MIN;
    vector<int> P(4);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            for (int k = 0; (i + k) <= n; k++)
                for (int l = 0; (j + l) <= m; l++) {
                    ll area = pref[i + k][j + l] - pref[i - 1][j + l] - pref[i + k][j - 1] + pref[i - 1][j - 1];
                    if (area > res) {
                        res = area;
                        P = {i, j, i + k, j + l};
                    }
                }
        }
    cout << res << endl;
    cout << P[0] << ' ' << P[1] << endl;
    cout << P[2] << ' ' << P[3] << endl;
}

int main() {
    _ solve();
    return 0;
}
