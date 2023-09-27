#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define int long long
long long mysqrt(long long u) {
    long long l = 1, r = u;
    long long ans = -1;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (mid * mid <= u) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

void solve() {
    long long n, k;
    cin >> n >> k;
    vector<long long> sqs(2 * n);
    int mark = -1;
    for (long long i = 1; i <= (2 * n); i++) {
        sqs[i - 1] = i * i;
        if (sqs[i - 1] == k) {
            mark = i;
        }
    }
    assert(mark != -1);
    debug(sqs, mark);
    cout << sqs[2 * n - mark] << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
