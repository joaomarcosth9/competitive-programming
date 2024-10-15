#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 1005;
char a[N][N];
bool upper[N][N];
int n, m, xa, ya;
int up[N][N], down[N][N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] != '.') {
                upper[i][j] = 1;
                a[i][j] += ('a' - 'A');
            }
            if (a[i][j] == 'a') {
                xa = i, ya = j;
            }
        }
    }

    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            up[i][j] = up[i - 1][j] + 1;
            if (a[i][j] != '.' && a[i][j] != 'a') {
                up[i][j] = 0;
            }
        }
        for (int i = n; i >= 1; i--) {
            down[i][j] = down[i + 1][j] + 1;
            if (a[i][j] != '.' && a[i][j] != 'a') {
                down[i][j] = 0;
            }
        }
    }

    int up_l = 1e9, down_l = 1e9;
    int best_res = 0, best_l = -1, best_r = -1, best_up = -1, best_down = -1;

    for (int la = ya; la >= 1; la--) {
        if (a[xa][la] != '.' && a[xa][la] != 'a') break;

        up_l = min(up_l, up[xa][la]);
        down_l = min(down_l, down[xa][la]);

        int up_r = 1e9, down_r = 1e9;

        for (int ra = ya; ra <= m; ra++) {
            if (a[xa][ra] != '.' && a[xa][ra] != 'a') break;

            up_r = min(up_r, up[xa][ra]);
            down_r = min(down_r, down[xa][ra]);

            // debug(la, up_l, down_l, ra, up_r, down_r);

            int res_now = (min(up_l, up_r) + min(down_l, down_r) - 1) * (ra - la + 1);
            // debug(res_now);

            if (res_now > best_res) {
                best_res = res_now;
                best_l = la, best_r = ra;
                best_up = xa - min(up_l, up_r) + 1, best_down = xa + min(down_l, down_r) - 1;
            }
        }
    }

    // cout << best_l << " " << best_r << " " << best_up << " " << best_down << endl;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i >= best_up && i <= best_down && j >= best_l && j <= best_r) {
                assert(a[i][j] == 'a' || a[i][j] == '.');
                a[i][j] = 'a';
            }
        }
    }

    auto paint = [&] (int i1, int j1, int i2, int j2) {
        if (i1 > i2 || j1 > j2)
            return;

        debug(i1, j1, i2, j2);

        int empty_lines = 0, last_line = i2 + 1;

        for (int i = i1; i <= i2; i++) {
            int last = j2 + 1;
            for (int j = j1; j <= j2; j++) {
                if (a[i][j] != '.') {
                    int k = j - 1;
                    while (a[i][k] == '.') {
                        a[i][k] = a[i][j];
                        k--;
                    }
                    last = j;
                }
            }

            if (last <= j2) {
                for (int j = last + 1; j <= j2; j++) {
                    a[i][j] = a[i][last];
                }
                for (int line = i - empty_lines; line < i; line++) {
                    for (int j = j1; j <= j2; j++) {
                        a[line][j] = a[i][j];
                    }
                }
                empty_lines = 0;
                last_line = i;
            } else {
                empty_lines++;
            }
        }
        for (int line = last_line + 1; line <= i2; line++) {
            for (int j = j1; j <= j2; j++) {
                a[line][j] = a[last_line][j];
            }
        }
    };

    paint(1, 1, best_up - 1, m); // pinta em cima
    paint(best_down + 1, 1, n, m); // pinta embaixo
    paint(best_up, 1, best_down, best_l - 1); // pinta na esquerda
    paint(best_up, best_r + 1, best_down, m); // pinta na direita

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << char(a[i][j] + (upper[i][j] ? ('A' - 'a') : 0));
        }
        cout << endl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}