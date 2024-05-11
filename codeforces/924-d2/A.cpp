#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

bool solve() {
    ll a, b; cin >> a >> b;
    pair<ll, ll> o = {min(a, b), max(a, b)};

    if ((a & 1) && (b & 1)) return 0;

    bool db = 0;
    if ((a & 1) == 0) {
        ll A = a / 2;
        ll B = 2 * b;
        pair<ll, ll> poss = {min(A, B), max(A, B)};
        db |= poss != o;
    }

    swap(a, b);

    if ((a & 1) == 0) {
        ll A = a / 2;
        ll B = 2 * b;
        pair<ll, ll> poss = {min(A, B), max(A, B)};
        db |= poss != o;
    }

    return db;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        /* solve(); */
        /* cout << solve() << endl; */
        cout << (solve() ? "Yes" : "No") << endl;
    }
}
