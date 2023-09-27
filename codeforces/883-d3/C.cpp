#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define int long long 

int h;
vector<vector<int>> mat;

pair<int,int> optimal(vector<int>& u) {
    int pts = 0, penalty = 0;
    int ctime = 0;
    for (int v : u) {
        if (ctime + v <= h) {
            pts++;
            debug(penalty + v);
            ctime += v;
            penalty += ctime;
        }
    }
    return {pts, penalty};
}

void solve() {
    int n, m; 
    cin >> n >> m >> h;
    debug(h);
    mat = vector (n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
        sort(begin(mat[i]), end(mat[i]));
    }
    vector<tuple<int,int,int>> ranks(n);
    for (int i = 0; i < n; i++) {
        auto [a, b] = optimal(mat[i]);
        ranks[i] = {a, b, i};
    }
    sort(begin(ranks), end(ranks), [&] (tuple<int,int,int>& l, tuple<int,int,int>& r) {
            int u = get<0>(l);
            int v = get<0>(r);
            int p1 = get<1>(l);
            int p2 = get<1>(r);
            int c1 = get<2>(l);
            int c2 = get<2>(r);
            return u > v || (u == v && p1 < p2) || (u == v && p1 == p2 && c1 == 0);
            });
    debug(ranks);
    for (int i = 0; i < n; i++) {
        if (get<2>(ranks[i]) == 0) {
            cout << i + 1 << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if (TC) { cin >> TC;
        while (TC--) solve();
    } else solve();
    return 0;
}
