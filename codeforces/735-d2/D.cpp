#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef pair<int, int> ii;
int testcases = 1;
const int INF = 1.05e9;
const ll INFLL = 4.5e18;
#define endl '\n'
#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#define dbarr(x...)
#endif

void solve() {
    int n;
    cin >> n;
    if (n <= 26) {
        for (int i = 0; i < n; i++) {
            cout << (char)('a' + i);
        }
        cout << endl;
        return;
    }
    string sep;
    int n1, n2;
    if (n & 1) {
        n -= 2;
        sep = "yz";
    } else {
        n -= 1;
        sep = "z";
    }
    n1 = n >> 1, n2 = (n >> 1) + 1;
    db(n1, n2);
    for (int i = 0; i < n1; i++) {
        cout << 'a';
    }
    cout << sep;
    for (int i = 0; i < n2; i++) {
        cout << 'a';
    }
    cout << endl;
}

signed main() {
#ifndef LOCAL_DEBUG
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tsts = 1;
    if (testcases) cin >> tsts;
    while (tsts--) solve();
    return 0;
}
