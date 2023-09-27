#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve() {
    int n, m, i, j, ii, jj;
    cin >> n >> m >> i >> j >> ii >> jj;
    string dir;
    cin >> dir;
    i--, j--, ii--, jj--;
    /* vector<vector<int>> v(n, vector<int>(m, 0)); */
    auto bottom = [&]() { return i == n  -  1; };
    auto top = [&]() { return i == 0; };
    auto left = [&]() { return j == 0; };
    auto right = [&]() { return j == m  -  1; };
    int res = 0;
    map<pair<pair<int, int>, string>, bool> vis;
    if (i == ii && j == jj) {
        cout << res << endl;
        return;
    }
    while (1) {
        db(i, j, dir, ii, jj);
        if (vis[make_pair(make_pair(i, j), dir)]) {
            cout << -1 << endl;
            return;
        }
        vis[make_pair(make_pair(i, j), dir)] = 1;

        if (dir == "UR") {
            res++;
            if (top() && right()) {
                dir = "DL";
            } else if (top()) {
                dir = "DR";
            } else if (right()) {
                dir = "UL";
            } else {
                res--;
                i--, j++;
            }
        } else if (dir == "UL") {
            res++;
            if (top() && left()) {
                dir = "DR";
            } else if (top()) {
                dir = "DL";
            } else if (left()) {
                dir = "UR";
            } else {
                res--;
                i--, j--;
            }
        } else if (dir == "DR") {
            res++;
            if (bottom() && right()) {
                dir = "UL";
            } else if (bottom()) {
                dir = "UR";
            } else if (right()) {
                dir = "DL";
            } else {
                res--;
                i++, j++;
            }
        } else if (dir == "DL") {
            res++;
            if (bottom() && left()) {
                dir = "UR";
            } else if (bottom()) {
                dir = "UL";
            } else if (left()) {
                dir = "DR";
            } else {
                res--;
                i++, j--;
            }
        }

        if (i == ii && j == jj) {
            cout << res << endl;
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
