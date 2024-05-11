#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
typedef tuple<int, int, int, char> i4;
const int maxn = 1e5 + 5;

pair<char, int> res[maxn];
pair<char, int> lazy[320][320][320];

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int SQRT = sqrt(n);
    int q;
    cin >> q;
    for (int i = 0; i < n; i++) {
        res[i] = make_pair(s[i], 0);
    }
    for (int t = 1; t <= q; t++) {
        int p, a, k;
        char c;
        cin >> p >> a >> k >> c;
        p--;
        int last = p + (a * k);
        if (k > SQRT) {
            int f_block = p / SQRT;
            int l_block = last / SQRT;
            for (int i = p; i / SQRT == f_block && i <= last; i += a) {
                res[i] = make_pair(c, t);
            }
            for (int b = f_block + 1; b < l_block; b++) {
                lazy[b][p % a][a] = make_pair(c, t);
            }
            for (int i = last; i / SQRT == l_block && i >= p; i -= a) {
                res[i] = make_pair(c, t);
            }
        } else {
            for (int i = p; i <= last; i += a) {
                res[i] = make_pair(c, t);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        char u = res[i].first;
        int t = res[i].second;
        int i_block = i / SQRT;
        for (int a = 1; a < SQRT + 3; a++) {
            auto [cc, tt] = lazy[i_block][i % a][a];
            if (tt > t) {
                u = cc;
                t = tt;
            }
        }
        cout << u;
    }
    cout << '\n';
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
