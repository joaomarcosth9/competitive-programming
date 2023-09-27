#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

const int maxn = 1005;
const long double EPS = 1e-6;

int v[4][maxn];
int w[4][maxn];

void solve() {
    vector<int> a(4);
    for (int it = 0; it < 4; it++) cin >> a[it];

    long double Wd;
    cin >> Wd;
    int W = floor(Wd * 10 + EPS);
    debug(W);

    for (int it = 0; it < 4; it++) {
        int q = a[it];
        v[it][0] = 0;
        for (int i = 1; i <= q; i++) {
            long double u;
            cin >> u;
            int V = floor(u * 10 + EPS);
            v[it][i] = V;
        }
        w[it][0] = 0;
        for (int i = 1; i <= q; i++) {
            long double u;
            cin >> u;
            int WW = floor(u * 10 + EPS);
            w[it][i] = WW;
        }
    }

    /*     for(int aa = 0; aa < 4; aa++){ */
    /*         int q = a[aa]; */
    /*         cout << "Item " << aa << endl; */
    /*         cout << "Valores: " << endl; */
    /*         for(int i = 0; i <= q; i++){ */
    /*             cout << v[aa][i] << " "; */
    /*         } */
    /*         cout << endl; */
    /*         cout << "Pesos: " << endl; */
    /*         for(int i = 0; i <= q; i++){ */
    /*             cout << w[aa][i] << " "; */
    /*         } */
    /*         cout << endl; */
    /*         cout << endl; */
    /*     } */

    vector<pair<int, int>> max1;
    for (int i = 0; i <= a[0]; i++) {
        for (int j = 0; j <= a[1]; j++) {
            int tv = v[0][i] + v[1][j];
            int tw = w[0][i] + w[1][j];
            if (tw > W) continue;
            max1.emplace_back(tw, tv);
        }
    }

    vector<pair<int, int>> max2;
    for (int i = 0; i <= a[2]; i++) {
        for (int j = 0; j <= a[3]; j++) {
            int tv = v[2][i] + v[3][j];
            int tw = w[2][i] + w[3][j];
            if (tw > W) continue;
            max2.emplace_back(tw, tv);
        }
    }

    sort(begin(max1), end(max1));
    vector<pair<int, int>> maxx1, maxx2;

    int mxv = max1[0].second;
    maxx1.emplace_back(max1[0]);

    for (int i = 1; i < (int)max1.size(); i++) {
        auto [cw, cv] = max1[i];
        if (cv <= mxv) continue;
        if (cw == maxx1.back().first) {
            maxx1.pop_back();
        }
        mxv = cv;
        maxx1.emplace_back(max1[i]);
    }

    sort(begin(max2), end(max2));
    mxv = max2[0].second;
    maxx2.emplace_back(max2[0]);

    for (int i = 1; i < (int)max2.size(); i++) {
        auto [cw, cv] = max2[i];
        if (cv <= mxv) continue;
        if (cw == maxx2.back().first) {
            maxx2.pop_back();
        }
        mxv = cv;
        maxx2.emplace_back(max2[i]);
    }

    debug(max1);
    debug(max2);
    debug(maxx1);
    debug(maxx2);

    int res = 0;

    maxx2.emplace_back(2e9, 0);

    for (int i = 0; i < (int)maxx1.size(); i++) {
        auto [cw, cv] = maxx1[i];
        if (cw > W) continue;
        auto MAX_W = W - cw;
        // procurar em maxx2 o maior cara <= MAX_W
        auto ub = upper_bound(begin(maxx2), end(maxx2), make_pair(MAX_W, 2000000000));
        --ub;
        auto [__, ov] = *ub;
        res = max(res, cv + ov);
    }

    string RES = to_string(res);
    int u = RES.size();
    RES.insert(u - 1, ".");
    cout << RES << endl;
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
