#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int64_t> a(n);

    for (auto &x : a)
        cin >> x;

    int64_t l = 1, r = int64_t(1) << 60;

    while (l <= r) {
        auto mid = l + (r - l) / 2;

        // maximo eh mid, da pra fazer?
        auto b = a;

        for (int i = 0; i < n - 1; i++) {
            b[i + 1] += max(0LL, b[i] - mid);
            b[i] = min(b[i], mid);
        }

        if (b.back() <= mid) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    int64_t cur_min = a[0], s = 0;

    for (int i = 1; i < n; i++) {
        if (a[i] >= cur_min) {
            s += a[i] - cur_min;
        } else {
            int64_t need = cur_min - a[i];
            if (need <= s) {
                s -= need;
            } else {
                a[i] += s;
                s = 0;
                int64_t total = a[i] + (cur_min * i);
                cur_min = total / (i + 1);
                s = total % (i + 1);
            }
        }
    }

    cout << (l - cur_min) << endl;

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