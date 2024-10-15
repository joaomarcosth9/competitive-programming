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
    cout << 1 << endl;
    srand(time(0));
    cout << 5 << " " << 8 << endl;
    for (int i = 0; i < 5; i++) {
        cout << (rand() % 15) + 1 << " ";
    }
    cout << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
