#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;

const int MAX = 1010;

int n, m, M[MAX][MAX], MM[MAX][MAX], pref[MAX][MAX];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> M[i][j];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (M[i][j] + M[i - 1][j - 1] <= M[i - 1][j] + M[i][j - 1]) {
                MM[i][j] = 1;
                MM[i - 1][j] = 1;
                MM[i][j - 1] = 1;
                MM[i - 1][j - 1] = 1;
            }
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << MM[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pref[i][j] = MM[i - 1][j - 1] + pref[i - 1][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pref[i][j] = pref[i][j] + pref[i][j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << pref[i][j] << ' ';
        }
        cout << endl;
    }
    int res = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            for (int a = i + 1; a <= n; a++) {
                for (int l = j + 1; l <= m; l++) {
                    int s = pref[a][l] + pref[i - 1][j - 1] - pref[i - 1][l] - pref[a][j - 1];
                    if (s == (a - i + 1) * (l - j + 1)) res = max(res, s);
                }
            }
        }
    }
    cout << res << endl;
}

int main() {
    _ solve();
    return 0;
}
