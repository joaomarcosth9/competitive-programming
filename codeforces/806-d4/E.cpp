#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 1e2;

// (i,j) -> (j, n-i-1) -> (n-i-1, n-j-1) -> (n-j-1, i) -> (i,j)
// n = 4; (0,1) -> (1,3) -> (3,2) -> (2,0)

int n;
char M[MAX][MAX];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> M[i][j];
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int zeros = 0, uns = 0;
            if (M[i][j] == '0')
                zeros++;
            else
                uns++;
            if (M[j][n - i - 1] == '0')
                zeros++;
            else
                uns++;
            if (M[n - i - 1][n - j - 1] == '0')
                zeros++;
            else
                uns++;
            if (M[n - j - 1][i] == '0')
                zeros++;
            else
                uns++;
            res += 4 - max(zeros, uns);
        }
    }
    cout << res / 4 << endl;
}

int main() {
    _ int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; i++) {
        solve();
    }
    return 0;
}
