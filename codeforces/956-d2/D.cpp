#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T, typename U>
using ordered_map = tree<T, U, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll cnt(vector<int> a, int n) {
    ordered_set<pair<int, int>> st;

    for (int i = 0; i < n; i++) {
        st.insert({a[i], i});
    }

    ll ret = 0;

    for (int i = 0; i < n; i++) {
        ret += st.order_of_key({a[i], -1});
        st.erase(st.find({a[i], i}));
    }

    return ret;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int &i : a)
        cin >> i;
    for (int &i : b)
        cin >> i;

    auto sa = a, sb = b;
    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());

    ll cnt_a = cnt(a, n);
    ll cnt_b = cnt(b, n);
    bool dr = (cnt_a % 2) != (cnt_b % 2);

    if (sa != sb || dr) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
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