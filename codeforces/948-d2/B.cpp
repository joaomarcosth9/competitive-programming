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
    int x; cin >> x;
    // x < (2 ^ 30)
    vector<int> a(32);

    // tem que buildar x sem usar bits consecutivos
    // 1 -1 = -1 0
    // 1 1 1 = -1 0 0 1
    // 0 0 0 1 1 1 = -1 0 0 0 0 1 + (1 0 0 -1 0 0)
    // 0 0 0 1 1 1 = 0 0 0 -1 0 1

    for (int i = 0; i < 30; i++) {
        if (x & (1 << i)) a[i] = 1;
    }

    for (int i = 0; i < 31; i++) {
        if (a[i] == 1) {
            int j = i + 1;
            if (a[j] == 0) continue;
            while (j < 32 && a[j] == 1) {
                a[j] = 0;
                j++;
            }
            a[i] = -1;
            a[j] = 1;
            i = j - 1;
        }
    }

    int y = 0;
    for (int i = 0; i < 31; i++) {
        assert(a[i] == 0 || a[i + 1] == 0);
        y += (1 << i) * a[i];
    }
    assert(x == y);

    cout << 32 << endl;
    output_vector(a);
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