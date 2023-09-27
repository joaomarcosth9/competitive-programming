#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

long long fib[50];

string solve2(long long n, long long x, long long y) {
    if (n <= 1) {
        return "YES";
    }
    int fn = fib[n], fna = fib[n - 1];
    if (y > fna) {
        return solve2(n - 1, fib[n - 2] - (y - fna) + 1, x);
    } else if (y <= fn - fna) {
        return solve2(n - 1, y, fib[n - 1] - x + 1);
    } else
        return "NO";
}

void solve() {
    long long n;
    cin >> n;
    long long fn = fib[n], fn1 = fib[n + 1];
    int x, y;
    cin >> x >> y;
    cout << solve2(n + 1, x, y) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < 50; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    int TC = 1;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
