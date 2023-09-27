#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 120;
typedef long long ll;

ll pascal[MAX][MAX];

void solve() {
    ll n;
    cin >> n;
    for (int i = 1; i < MAX; i++)
        for (int j = 1; j < MAX; j++) {
            if (i == j || j == 0)
                pascal[i][j] = 1;
            else if (i < j)
                continue;
            else
                pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
            if (pascal[i][j] >= n) {
                cout << i - 1 << endl;
                return;
            }
        }
}

int main() {
    _ int tscf;
    cin >> tscf;
    while (tscf--) solve();
    return 0;
}
