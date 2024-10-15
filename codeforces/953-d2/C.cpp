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
    int n; ll k; cin >> n >> k;
    ll mx = 0;

    for (int i = 1; i <= n; i++) {
        mx += abs(n + 1 - i - i);
    }

    ll K = k;
    if (k > mx || (k & 1)) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;

    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }

    for (ll add = 2 * (n - 1), num = 1; add > 0 && k > 0; add -= 4, num++) {
        if (add <= k) {
            k -= add;
            swap(p[num], p[n + 1 - num]);
        } else if (add > k) {
            assert(k % 2 == 0);
            swap(p[num], p[num + k / 2]);
            k = 0;
            // bomba
        }
    }

    for (int i = 1; i <= n; i++) {
        K -= abs(p[i] - i);
    }
    assert(K == 0);

    output_vector(p, 0, 1);
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