#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
#define int ll

const int N = 5e5 + 5;
pair<int, int> a[N];
int vals[2 * N], sz = 0;
int events[2 * N][2];

void solve() {
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        a[i] = {l, r};
        vals[sz++] = l;
        vals[sz++] = r;
    }

    sort(vals, vals + sz);

    sz = unique(vals, vals + sz) - vals;

    for (int i = 0; i < n; i++) {
        auto &[l, r] = a[i];
        l = lower_bound(vals, vals + sz, l) - vals;
        r = lower_bound(vals, vals + sz, r) - vals;
        events[l][0]++;
        events[r][1]++;
    }

    ll active = 0;
    ll ans = 0;

    for (int i = 0; i < 2 * N; i++) {
        // ans += (ll)events[i][0] * active;
        active += events[i][0];
        for (int j = 0; j < events[i][1]; j++) {
            active--;
            ans += active;
        }
    }

    assert(active == 0);

    cout << ans << endl;

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
