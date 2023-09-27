#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve() {
    int n, x;
    cin >> n >> x;
    string T;
    cin >> T;
    vector<int> sz(3);
    for (auto &a : sz) cin >> a;
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        if (T[i] == 'P')
            t[i] = sz[0];
        else if (T[i] == 'M')
            t[i] = sz[1];
        else
            t[i] = sz[2];
    }
    map<int, set<int>> maps;
    vector<int> POS(n);
    iota(begin(POS), end(POS), 0);
    vector<int> walls(n, x);
    for (auto a : sz) {
        maps[a] = set<int>(begin(POS), end(POS));
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        set<int> &curr = maps[t[i]];
        int &w = t[i];
        int wall = *(curr.begin());
        res = max(res, wall);
        walls[wall] -= w;
        for (auto a : sz)
            if (walls[wall] < a) {
                maps[a].erase(wall);
            }
    }
    cout << res + 1 << endl;
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
