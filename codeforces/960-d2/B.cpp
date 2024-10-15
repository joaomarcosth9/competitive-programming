#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

void solve() {
    /* int n, x, y; cin >> n >> x >> y; */
    /* x--; y--; */
    /*
        construir um array de tamanho N, em que 
        o maior prefixo de soma ocorre na posicao x e o maior sufixo ocorre na posicao y

        y < x !!!

        1 1 1 1 1
        x = 5, y = 1

        -1 -1 -1 -1 -1
        x = 1, y = 5

        1 -1 -1 -1 1
        x = 1, y = 5

        1 1 1 1 1, x = 5, y = 1
        1 1 1 1 -1, x = 4, y = 1
        1 1 1 -1 -1, x = 3, y = 1
        1 1 -1 -1 -1, x = 2, y = 4
        1 -1 -1 -1 -1, x = 2, y = 4

    */
    for (int n = 2; n <= 8; n++) {
        cout << endl << endl;
        for (int y = 1; y <= n; y++) {
            for (int x = y + 1; x <= n; x++) {
                bool db = 0;
                vector<int> ans(n, 0);
                for (int i = 0; !db && i < (1 << n); i++) {
                    int sum = 0;
                    for (int j = 0; j < n; j++) {
                        if (i & (1 << j)) {
                            ans[j] = 1;
                        } else {
                            ans[j] = -1;
                        }
                    }
                    int mx_pref = 0, mx_suf = 0;
                    int index_mx_pref = -1, index_mx_suf = -1;
                    for (int j = 0; j < n; j++) {
                        sum += ans[j];
                        if (sum > mx_pref) {
                            mx_pref = sum;
                            index_mx_pref = j;
                        }
                    }
                    sum = 0;
                    for (int j = n - 1; j >= 0; j--) {
                        sum += ans[j];
                        if (sum > mx_suf) {
                            mx_suf = sum;
                            index_mx_suf = j + 1;
                        }
                    }
                    if (index_mx_pref == x && index_mx_suf + 1 == y) {
                        cout << "n = " << n << ", x = " << x << ", y = " << y << endl;
                        for (int j = 0; j < n; j++) {
                            cout << ans[j] << " ";
                        }
                        cout << endl;
                        db = true;
                        break;
                    }
                }
            }
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}
