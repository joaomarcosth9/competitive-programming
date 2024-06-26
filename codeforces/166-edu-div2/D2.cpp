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

struct SparseTable {
    int n, LG;
    vector<vector<ll>> st;
    ll merge(ll a, ll b) { return max(a, b); }
    const ll neutral = -1e18;
    void build(const vector<ll> &v) {
        n = (int)v.size();
        LG = 32 - __builtin_clz(n);
        st = vector<vector<ll>>(LG, vector<ll>(n));
        for (int i = 0; i < n; i++) {
            st[0][i] = v[i];
        }
        for (int i = 0; i < LG - 1; i++) {
            for (int j = 0; j + (1 << i) < n; j++) {
                st[i + 1][j] = merge(st[i][j], st[i][j + (1 << i)]);
            }
        }
    }
    void build(ll *bg, ll *en) { build(vector<ll>(bg, en)); }
    ll query(int l, int r) {
        if (l > r)
            return neutral;
        int i = 31 - __builtin_clz(r - l + 1);
        return merge(st[i][l], st[i][r - (1 << i) + 1]);
    }
};

void solve() {
    string s; cin >> s;
    int n = int(s.size());
    debug(s);
    int balance = 0;
    vector<int> pref(n + 1), bal(n + 1);
    for (int i = 0; i < n; i++) {
        balance += (s[i] == '(' ? 1 : -1);
        pref[i + 1] = pref[i] + balance;
        bal[i + 1] = balance;
    }

    SparseTable st;
    st.build(bal);
    vector<int> first_greater(n + 1, n);
    for (int i = 1; i <= n; i++) {
        // first greather than 2 * bal[i]
        int l = i + 1, r = n;
        int ans = n;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (st.query(i, mid) > 2 * bal[i]) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        first_greater[i] = ans;
    }

    ll res = 0;
    map<int, multiset<int>> can_help;

    for (int i = 1; i <= n; i++) {
        ll x = bal[i];
        while (!can_help[x].empty() && *can_help[x].begin() < i) {
            can_help[x].erase(can_help[x].begin());
        }
        res += can_help[x].size();
        can_help[x].insert(first_greater[i]);
    }

    cout << res << endl;
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
