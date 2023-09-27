#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
typedef tuple<int, int, int, int> i4;
typedef tuple<int, int, int> i3;
typedef pair<int, int> ii;

void solve() {
    int n;
    cin >> n;
    vector<int> res(n, 1e9);
    vector<i4> seg(n);
    for (int i = 0; i < n; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        c--;
        seg[i] = {l, r, c, i};
    }
    sort(begin(seg), end(seg));
    multiset<i3> last;
    vector<int> what(n, -1);
    vector<int> who(n, -1);
    for (int i = 0; i < n; i++) {
        auto &[l, r, c, id] = seg[i];
        if (what[c] == -1) {
            what[c] = r;
            who[c] = id;
            last.emplace(r, c, id);
        }
        if (what[c] < r) {
            last.erase(i3(what[c], c, who[c]));
            what[c] = r;
            who[c] = id;
            last.emplace(r, c, id);
        }
        last.erase(i3(what[c], c, who[c]));

        auto big = last.rbegin();
        if (big != last.rend()) {

            int R = get<0>(*big);
            debug(R);
            int WHO = get<2>(*big);
            int dis = max(l - R, 0);

            res[id] = min(res[id], dis);
            res[WHO] = min(res[WHO], dis);
        }

        last.emplace(what[c], c, who[c]);
    }
    last.clear();
    what.assign(n, -1);
    who.assign(n, -1);
    for (int i = n - 1; i >= 0; i--) {
        auto &[l, r, c, id] = seg[i];
        if (what[c] == -1) {
            what[c] = l;
            who[c] = id;
            last.emplace(l, c, id);
        }
        if (what[c] > l) {
            last.erase(i3(what[c], c, who[c]));
            what[c] = l;
            who[c] = id;
            last.emplace(l, c, id);
        }
        last.erase(i3(what[c], c, who[c]));

        auto big = last.begin();
        if (big != last.end()) {
            int L = get<0>(*big);
            debug(R);
            int WHO = get<2>(*big);
            int dis = max(L - r, 0);
            res[id] = min(res[id], dis);
            res[WHO] = min(res[WHO], dis);
        }

        last.emplace(what[c], c, who[c]);
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << ' ';
    }
    cout << '\n';
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
