#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
#define int ll
using ll = long long;

bool solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), x(n);
    for (int &i : a) cin >> i;
    for (int &i : x) cin >> i;
    int s = 0;
    multiset<tuple<int, int, int>> st;
    for (int i = 0; i < n; i++) {
        st.emplace(abs(x[i]), a[i], i);
    }
    int now = k;
    debug(st);
    while (st.size()) {
        auto [dis, h, id] = *st.begin();
        st.erase(st.begin());
        dis -= s;
        if (dis <= 0) return 0;
        debug(id);
        debug(dis, h, now);
        if (now < h) {
            h -= now;
            now = k;
            s++;
            dis--;
            if (dis <= 0) return 0;
            if (h == k) {
                s++;
            } else if (h < k) {
                now -= h;
            } else if (h > k) {
                s += h / k;
                dis -= h / k;
                if (dis <= 0) return 0;
                h = h % k;
                now -= h;
            }
        } else {
            now -= h;
        }
    }
    return 1;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        /* solve(); */
        /* cout << solve() << endl; */
        cout << (solve() ? "Yes" : "No") << endl;
    }
}
