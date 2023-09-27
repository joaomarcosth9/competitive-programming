#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef pair<int, int> ii;
int testcases = 1;
const int INF = 1.05e9;
const ll INFLL = 4.5e18;
#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#define dbarr(x...)
#endif

void solve() {
    int n;
    cin >> n;
    int v[n];
    int d = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        d += v[i] == 2;
    }
    if (d & 1) {
        cout << -1 << endl;
    } else {
        int dd = 0;
        for (int i = 0; i < n; i++) {
            dd += v[i] == 2;
            if (dd == (d >> 1)) {
                cout << i + 1 << endl;
                return;
            }
        }
    }
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
