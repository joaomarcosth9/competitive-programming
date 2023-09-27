#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 1e5 + 10;
int n;
string V[MAX];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> V[i];
    for (int i = 0; i < n; i++) {
        map<char, set<char>> M;
        for (int j = 0; j < 9 && (j + i) < n; j++) {
            char valor = V[i + j][0];
            char naipe = V[i + j][1];
            M[valor].insert(naipe);
            if (M[valor].size() == 3) {
                cout << i + j + 1 << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    _ solve();
    return 0;
}
