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

bool check(ii &a) { return a.first == 1 && a.second == 1; }

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    pair<int, int> coord = {0, 0};
    for (char c : s) {
        if (c == 'U') {
            coord.second++;
        } else if (c == 'R') {
            coord.first++;
        } else if (c == 'D') {
            coord.second--;
        } else if (c == 'L') {
            coord.first--;
        }
        if (check(coord)) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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
