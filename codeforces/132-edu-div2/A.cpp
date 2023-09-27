#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;

void solve() {
    int key;
    cin >> key;
    int doors[3];
    cin >> doors[0] >> doors[1] >> doors[2];
    if (doors[key - 1] != 0) {
        if (doors[doors[key - 1] - 1] != 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    _ int tscf;
    cin >> tscf;
    while (tscf--) solve();
    return 0;
}
