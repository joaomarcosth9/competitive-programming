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
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    sort(begin(a), end(a));
    sort(begin(b), end(b));

    a.erase(unique(begin(a), end(a)), end(a));
    b.erase(unique(begin(b), end(b)), end(b));
    n = (int)a.size();
    m = (int)b.size();

    if (n < k / 2) return 0;
    if (m < k / 2) return 0;

    map<int, int> fa, fb;
    for (int i = 0; i < n; i++) {
        fa[a[i]]++;
    }
    for (int i = 0; i < m; i++) {
        fb[b[i]]++;
    }

    debug(a);
    debug(b);

    int cnta = k / 2, cntb = k / 2, extra = 0;

    for (int i = 1; i <= k; i++) {
        if (fa[i] == 0 && fb[i] == 0) return 0;
        if (fa[i] == 0) cntb--;
        else if (fb[i] == 0) cnta--;
        else extra++;
    }

    if (extra > cnta + cntb) return 0;
    if (cnta < 0 || cntb < 0) return 0;

    return 1;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        /* solve(); */
        /* cout << solve() << endl; */
        cout << (solve() ? "Yes" : "No") << endl;
    }
}
