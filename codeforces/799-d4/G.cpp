#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<bool> a(n - 1);
    for (int i = 1; i < n; i++) {
        a[i - 1] = (v[i - 1] < v[i] * 2);
    }
    int res = 0;
    int wsize = 1;
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += a[i];
        if (wsize == k) {
            res += (sum == k);
            sum -= a[i - k + 1];
        } else {
            wsize++;
        }
    }
    cout << res << endl;
}

signed main() {
#ifdef LOCAL_DEBUG
    freopen("/tmp/input.txt", "r", stdin);
    freopen("/tmp/output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tt;
    cin >> tt;
    while (tt--) solve();
    return 0;
}