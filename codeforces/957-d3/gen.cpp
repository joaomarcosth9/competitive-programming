#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 1e5 + 5;
int cnt[N];

void solve() {
    srand(time(0));
    cout << 10 << endl;
    int t = 10;
    while (t--) {
        int n = 1e3;
        int m = rand() % 10 + 1;
        int k = rand() % n + 1;
        cout << n << ' ' << m << ' ' << k << endl;
        vector<char> poss = {'W', 'L', 'C'};
        for (int i = 0; i < n; i++) {
            cout << poss[rand() % 3];
        }
        cout << endl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
