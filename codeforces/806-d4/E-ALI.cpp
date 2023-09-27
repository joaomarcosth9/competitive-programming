#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

array<array<int, 2>, 2> a = {{
    {0, 1}, //{-2}
    {-1, 0} //{-2}

}};

array<array<int, 1>, 2> transform(array<array<int, 1>, 2> &b) {
    array<array<int, 1>, 2> c{};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < 2; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int ii = i + (n % 2 == 0 && i >= n / 2);
            int jj = j + (n % 2 == 0 && j >= n / 2);
            char c;
            cin >> c;
            mat[ii][jj] = c - '0';
        }
    }
    n |= 1;
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int one = mat[i][j];
            i -= n / 2;
            j -= n / 2;
            array<array<int, 1>, 2> pos = {{{i}, {j}}};
            db(i, j);
            for (int k = 0; k < 3; k++) {
                pos = transform(pos);
                auto [ii, jj] = pos;
                db(ii[0], jj[0]);
                ii[0] += n / 2;
                jj[0] += n / 2;
                one += mat[ii[0]][jj[0]];
            }
            res += min(one, 4 - one);
            i += n / 2;
            j += n / 2;
            /* auto u = transform(pos); */
            /* db(i, j, u[0][0], u[1][0]); */
        }
    }
    cout << res / 4 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
