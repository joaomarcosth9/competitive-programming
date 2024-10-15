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
    int n;
    cin >> n;
    if (n & 1) {
        vector<int> p(n);
        int num = 1;
        for (int i = 0; i < n; i += 2) {
            p[i] = num;
            num++;
        }
        for (int i = n - 2; i >= 0; i -= 2) {
            assert(p[i] == 0);
            p[i] = num;
            num++;
        }
        output_vector(p);
    } else {
        cout << -1 << endl;
    }
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