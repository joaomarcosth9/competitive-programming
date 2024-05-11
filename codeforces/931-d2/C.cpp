#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
using ll = long long;

int n, m, X, Y, X2, Y2;

int ask(int x, int y) {
    /* int res = min(abs(x - X) + abs(y - Y), abs(x - X2) + abs(y - Y2)); */
    cout << "? " << x + 1 << " " << y + 1 << endl;
    int res; cin >> res;
    return res;
}

int diag(int i, int j) {
    return i + j;
}

pair<int, int> find(int i, int j, int d) {
    int mi = diag(i, j);
    int dis = mi - d;
    return {i - dis / 2, j - dis / 2};
}

bool valid(pair<int, int> p) {
    return p.first >= 0 && p.first < n && p.second >= 0 && p.second < m;
}

void guess(pair<int, int> p) {
    cout << "! " << p.first + 1 << " " << p.second + 1 << endl;
}

void solve() {
    cin >> n >> m;

    int f = ask(0, 0);
    int s = ask(n - 1, m - 1);
    int t = ask(0, m - 1);

    debug(f, s, t);

    if (n >= m) {
        int xx = 0 + t, yy = m - 1;
        auto p1 = find(xx, yy, diag(0 + f, 0));
        auto p2 = find(xx, yy, diag(n - 1 - s, m - 1));
        debug(xx, yy);
        debug(p1, p2);
        if (valid(p1) && valid(p2)) {
            int ver = ask(p1.first, p1.second);
            if (ver == 0) {
                guess(p1);
            } else {
                guess(p2);
            }
        } else if (valid(p1)) {
            guess(p1);
        } else if (valid(p2)) {
            guess(p2);
        } else assert(false);
    } else {
        int xx = 0, yy = m - 1 - t;
        auto p1 = find(xx, yy, diag(0 + f, 0));
        auto p2 = find(xx, yy, diag(n - 1 - s, m - 1));
        if (valid(p1) && valid(p2)) {
            int ver = ask(p1.first, p1.second);
            if (ver == 0) {
                guess(p1);
            } else {
                guess(p2);
            }
        } else if (valid(p1)) {
            guess(p1);
        } else if (valid(p2)) {
            guess(p2);
        } else assert(false);
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        /* cin >> n >> m; */
        /* cin >> X >> Y; */
        /* cin >> X2 >> Y2; */
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
