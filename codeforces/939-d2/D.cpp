#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

vector<pair<int, int>> ops;
vector<int> a;

void op(int l, int r) {
    ops.push_back({l, r});
    set<int> mx;
    for (int i = l; i <= r; i++) {
        mx.insert(a[i]);
    }
    int mex = 0;
    auto it = mx.begin();
    while (it != mx.end() && mex == *it) {
        mex++;
        it++;
    }
    for (int i = l; i <= r; i++) {
        a[i] = mex;
    }
    debug(a);
}

void rec(int l, int r) {
    if (l > r) {
        return;
    }
    for (int i = l; i <= r; i++) {
        if (a[i] > 0) {
            op(i, i);
        }
    }
    rec(l, r - 1);
    if (l < r) op(l, r);
    rec(l, r - 1);
}

void solve() {
    int n; cin >> n;
    ops.clear();
    a.resize(n);
    for (int &i : a) cin >> i;

    if (n == 1) {
        if (a[0] >= 1) {
            cout << a[0] << " 0" << endl;
        } else {
            cout << "1 1" << endl;
            cout << "1 1" << endl;
        }
        return;
    }

    vector<ll> dp(n + 1, -1);
    vector<int> back(n + 1, -1);
    dp[0] = 0;
    back[0] = 0;

    for (int i = 0; i < n; i++) {
        if (dp[i] + a[i] > dp[i + 1]) {
            dp[i + 1] = dp[i] + a[i];
            back[i + 1] = 0;
        }
        for (int j = i + 1, num = 1; j <= n; j++, num++) {
            if (dp[i] + (ll)num * num > dp[j]) {
                dp[j] = dp[i] + (ll)num * num;
                back[j] = num;
            }
        }
    }

    vector<bool> mark(n);

    for (int i = n; i >= 1; i--) {
        if (back[i]) {
            int l = i - back[i] + 1, r = i;
            rec(l - 1, r - 1);
            op(l - 1, r - 1);
            i = i - back[i] + 1;
        }
    }

    debug(mark);

    cout << dp[n] << " " << ops.size() << endl;

    for (auto [l, r] : ops) {
        cout << l + 1 << " " << r + 1 << endl;
    }

    debug(accumulate(a.begin(), a.end(), 0ll), dp[n]);

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
