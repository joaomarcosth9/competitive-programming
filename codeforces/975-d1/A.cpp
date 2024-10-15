#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 200200; 

int n;
int64_t k, a[N], sum, mx;

void solve() {
    cin >> n >> k;

    sum = 0, mx = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }

    // maior tamanho de um grupo eh n

    debug(sum, mx);

    auto o_sum = sum;

    sum += k;

    for (int g = n; g >= 1; g--) {
        int64_t maximum = sum - (sum % g);
        if (maximum >= o_sum) {
            // da pra fazer maximum / g grupos de tamanho g
            // ok, mas da pra organizar os caras? se alguem tem frequencia > maximum nao da
            if (maximum / g < mx) continue;
            cout << g << endl;
            return;
        }
    }

    assert(false);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}