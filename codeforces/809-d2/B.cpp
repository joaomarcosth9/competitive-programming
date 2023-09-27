#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 1e5 + 500;
int n, arr[MAX];

void solve() {
    cin >> n;
    map<int, vector<int>> M;
    vector<int> Res(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        M[arr[i]].push_back(i % 2);
    }

    for (int i = 1; i <= n; i++) {
        int sp = 1;
        int si = 1;
        for (int j = 0; j < M[i].size(); j++) {
            if (sp == 1 && M[i][j] == 0) {
                sp = 0;
                si = 1;
                Res[i]++;
            } else if (si == 1 && M[i][j] == 1) {
                si = 0;
                sp = 1;
                Res[i]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << Res[i] << ' ';
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
