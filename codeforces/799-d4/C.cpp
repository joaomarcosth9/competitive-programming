#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> M(8, vector<char>(8));

void solve() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> M[i][j];
        }
    }
    for (int i = 1; i < 7; i++) {
        for (int j = 1; j < 7; j++) {
            if (M[i - 1][j - 1] == '#' && M[i - 1][j + 1] == '#' && M[i + 1][j - 1] == '#' && M[i + 1][j - 1] == '#') {
                cout << (i + 1) << ' ' << (j + 1) << endl;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; i++) {
        solve();
    }
    return 0;
}
