#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> p(n), p2(n);
    int it = n;
    for (int i = 0; i <= n - k; i++) {
        p[i] = it--;
    }
    it = m;
    for (int i = n - 1; i >= 0; i--) {
        if (p[i] != 0 || it == 0) {
            break;
        }
        p[i] = it--;
    }
    it = m + 1;
    for (int i = n - 1; i >= 0; i--) {
        if (p[i] == 0) {
            p[i] = it++;
        }
    }
    auto f = [&] (int j, vector<int> a) {
        ll ret = 0;
        for (int i = 0; i <= j; i++) {
            if (a[i] >= k) {
                ret += a[i];
            }
        }
        return ret;
    };
    auto g = [&] (int j, vector<int> a) {
        ll ret = 0;
        for (int i = 0; i <= j; i++) {
            if (a[i] <= m) {
                ret += a[i];
            }
        }
        return ret;
    };
    // ll res1 = 0, res2 = 0;
    // for (int i = 0; i < n; i++) {
    //     res1 += f(i, p) - g(i, p);
    //     res2 += f(i, p2) - g(i, p2);
    // }
    // cout << res1 << " " << res2 << endl;
    output_vector(p);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}
