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
    srand(time(NULL));
    int n; cin >> n;
    cout << 1 << endl;
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        cout << 1000000000000 << " ";
    }
    cout << endl;
    for (int node = 2; node <= n; node++) {
        int par = rand() % (node - 1);
        par++;
        cout << par << " " << node << endl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
