#include <iostream>
#include <vector>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;
int n, m;

void solve() {
    cin >> n >> m;
    vector<char> S(m + 1, 'B');
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a > m / 2) {
            if (S[m + 1 - a] == 'B') {
                S[m + 1 - a] = 'A';
            } else {
                S[a] = 'A';
            }
        } else {
            if (S[a] == 'B') {
                S[a] = 'A';
            } else {
                S[m + 1 - a] = 'A';
            }
        }
    }
    for (int i = 1; i <= m; i++) cout << S[i];
    cout << endl;
}

int main() {
    _ int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; i++) {
        solve();
    }
    return 0;
}
