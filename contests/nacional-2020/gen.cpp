#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(int N) {
    for (int i = 0; i < N; i++) {
        cout << char('A' + rng() % 4);
    }
    cout << endl;
    cout << "-";
    for (int i = 0; i < N; i++) {
        cout << char('A' + rng() % 4);
    }
    cout << endl;
}

int32_t main(int argc, char* argv[]) {
    cin.tie(0)->sync_with_stdio(0);
    solve(atoi(argv[1]));
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
