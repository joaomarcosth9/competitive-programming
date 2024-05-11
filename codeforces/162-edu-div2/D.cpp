#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
using ii = tuple<int, int, int>;

const int MAX = 3e5 + 5, MAX2 = 20;

int n;
ll pref[MAX];

struct SparseTableMin {
    int n, LG;
    vector<vector<ll>> st;
    ll merge(ll a, ll b) {
        return min(a, b);
    }
    const ll neutral = 1e18;
    void build(vector<ll> &v) {
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
    ll query(int l, int r) {
        if (l > r) return neutral;
        int i = 31 - __builtin_clz(r - l + 1);
        return merge(st[i][l], st[i][r - (1 << i) + 1]);
    }
};

struct SparseTableMax {
    int n, LG;
    vector<vector<ll>> st;
    ll merge(ll a, ll b) {
        return max(a, b);
    }
    const ll neutral = -1e18;
    void build(vector<ll> &v) {
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
    ll query(int l, int r) {
        if (l > r) return neutral;
        int i = 31 - __builtin_clz(r - l + 1);
        return merge(st[i][l], st[i][r - (1 << i) + 1]);
    }
};

ll sumq(int a, int b) {
    assert(a <= b);
    return pref[b + 1] - pref[a];
}

void solve() {
    cin >> n;
    vector<ll> a(n);
    for (ll &i : a) cin >> i;
    for (int i = 0; i <= n; i++) {
        pref[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }
    SparseTableMin m1;
    SparseTableMax m2;
    m1.build(a);
    m2.build(a);

    vector<ll> res(n, LLONG_MAX);

    for (int i = 0; i < n; i++) {

        if (i < n - 1 && a[i + 1] > a[i]) res[i] = 1;
        if (i > 0 && a[i - 1] > a[i]) res[i] = 1;

        int l = i + 2, r = n - 1;
        ll ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            ll mn = m1.query(i + 1, mid);
            ll mx = m2.query(i + 1, mid);
            ll sum = sumq(i + 1, mid);
            if (mn == mx || sum <= a[i]) {
                l = mid + 1;
            } else {
                ans = (mid - i);
                r = mid - 1;
            }
        }
        if (ans != -1) res[i] = min(res[i], ans);
        l = 0, r = i - 2;
        ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            ll mn = m1.query(mid, i - 1);
            ll mx = m2.query(mid, i - 1);
            ll sum = sumq(mid, i - 1);
            if (mn == mx || sum <= a[i]) {
                r = mid - 1;
            } else {
                ans = (i - mid);
                l = mid + 1;
            }
        }
        if (ans != -1) res[i] = min(res[i], ans);
    }

    for (auto u : res) cout << (u < LLONG_MAX ? u : -1) << " ";
    cout << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
