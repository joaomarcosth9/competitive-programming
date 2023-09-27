#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> V(n);
    for (int i = 0; i < n; i++) cin >> V[i];
    int dr = 0;
    int pdc = 1;
    for (int i = 1; i < n; i++) {
        if (V[i] < V[i - 1]) {
            pdc = 0;
        } else if (V[i] > V[i - 1] && !pdc) {
            dr++;
            break;
        }
    }
    if (dr) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    _ int tscf;
    cin >> tscf;
    while (tscf--) solve();
    return 0;
}
