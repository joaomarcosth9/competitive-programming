#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int MOD = 998244353, N = 1e5 + 5, M = 21;

string s, t1, t2;
int n, m1, m2;

int res = 0;

int add(int a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
    return a;
}

int dpl[N][M], dpr[N][M];

void rec(int l, int r) {
    if (l > r)
        return;
    if (l == r) {
        if (m1 == 1 && m2 == 1 && s[l] == t1[0] && s[0] == t2[0]) {
            res = add(res, 1);
        }
    } else {
        int mid = (l + r) / 2;

        for (int i = l; i <= r; i++) {

        }

        rec(l, mid);
        rec(mid + 1, r);
    }
}

void solve() {
    cin >> s >> t1 >> t2;
    n = (int)s.size();
    m1 = (int)t1.size();
    m2 = (int)t2.size();



}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}