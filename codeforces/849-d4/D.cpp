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

int id(char c) { return c - 'a'; }

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> fl(26), fr(26);
    fl[id(s[0])]++;
    int fa = 1, fb = 0;
    for (int i = 1; i < n; i++) {
        if (fr[id(s[i])] == 0) fb++;
        fr[id(s[i])]++;
    }
    int tres, res;
    res = tres = fa + fb;
    for (int i = 1; i < n; i++) {
        char c = s[i];
        if (fl[id(c)] == 0) {
            tres++;
        }
        fl[id(c)]++;
        fr[id(c)]--;
        if (fr[id(c)] == 0) {
            tres--;
        }
        res = max(res, tres);
    }
    cout << res << endl;
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
