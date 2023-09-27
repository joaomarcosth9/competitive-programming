#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> V;
    V.push_back(n);
    for (int i = 1; i < n; i++) V.push_back(i);
    for (int i = 0; i < n; i++) cout << V[i] << ' ';
    cout << endl;
}

int main() {
    _ int tscf;
    cin >> tscf;
    while (tscf--) solve();
    return 0;
}
