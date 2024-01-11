#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif
#define endl '\n'
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto& x){ return res; }
#define L2(res...) [&](const auto& x, const auto& y){ return res; }
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

template <typename T = int> struct ms_tree {
    vector<tuple<T, T, int>> v;
    int n;
    vector<vector<tuple<T, T, int>>> t; // {y, idx, left}
    vector<T> vy;

    ms_tree(vector<pair<T, T>> &vv) : n(vv.size()), t(4 * n), vy(n) {
        for (int i = 0; i < n; i++) v.push_back({vv[i].first, vv[i].second, i});
        sort(v.begin(), v.end());
        build(1, 0, n - 1);
        for (int i = 0; i < n; i++) vy[i] = get<0>(t[1][i + 1]);
    }
    ms_tree(vector<T> &vv, bool inv = false) { // inv: inverte indice e valor
        vector<pair<T, T>> v2;
        for (int i = 0; i < vv.size(); i++) inv ? v2.push_back({vv[i], i}) : v2.push_back({i, vv[i]});
        *this = ms_tree(v2);
    }
    void build(int p, int l, int r) {
        t[p].push_back({get<0>(v[l]), get<0>(v[r]), 0}); // {min_x, max_x, 0}
        if (l == r) return t[p].push_back({get<1>(v[l]), get<2>(v[l]), 0});
        int m = (l + r) / 2;
        build(2 * p, l, m), build(2 * p + 1, m + 1, r);

        int L = 0, R = 0;
        while (t[p].size() <= r - l + 1) {
            int left = get<2>(t[p].back());
            if (L > m - l or (R + m + 1 <= r and t[2 * p + 1][1 + R] < t[2 * p][1 + L])) {
                t[p].push_back(t[2 * p + 1][1 + R++]);
                get<2>(t[p].back()) = left;
                continue;
            }
            t[p].push_back(t[2 * p][1 + L++]);
            get<2>(t[p].back()) = left + 1;
        }
    }

    int get_l(T y) { return lower_bound(vy.begin(), vy.end(), y) - vy.begin(); }
    int get_r(T y) { return upper_bound(vy.begin(), vy.end(), y) - vy.begin(); }

    int count(T x1, T x2, T y1, T y2) {
        function<int(int, int, int)> dfs = [&](int p, int l, int r) {
            if (l == r or x2 < get<0>(t[p][0]) or get<1>(t[p][0]) < x1) return 0;
            if (x1 <= get<0>(t[p][0]) and get<1>(t[p][0]) <= x2) return r - l;
            int nl = get<2>(t[p][l]), nr = get<2>(t[p][r]);
            return dfs(2 * p, nl, nr) + dfs(2 * p + 1, l - nl, r - nr);
        };
        return dfs(1, get_l(y1), get_r(y2));
    }
    vector<int> report(T x1, T x2, T y1, T y2) {
        vector<int> ret;
        function<void(int, int, int)> dfs = [&](int p, int l, int r) {
            if (l == r or x2 < get<0>(t[p][0]) or get<1>(t[p][0]) < x1) return;
            if (x1 <= get<0>(t[p][0]) and get<1>(t[p][0]) <= x2) {
                for (int i = l; i < r; i++) ret.push_back(get<1>(t[p][i + 1]));
                return;
            }
            int nl = get<2>(t[p][l]), nr = get<2>(t[p][r]);
            dfs(2 * p, nl, nr), dfs(2 * p + 1, l - nl, r - nr);
        };
        dfs(1, get_l(y1), get_r(y2));
        return ret;
    }
    int kth(T y1, T y2, int k) {
        function<int(int, int, int)> dfs = [&](int p, int l, int r) {
            if (k >= r - l) {
                k -= r - l;
                return -1;
            }
            if (r - l == 1) return get<1>(t[p][l + 1]);
            int nl = get<2>(t[p][l]), nr = get<2>(t[p][r]);
            int left = dfs(2 * p, nl, nr);
            if (left != -1) return left;
            return dfs(2 * p + 1, l - nl, r - nr);
        };
        return dfs(1, get_l(y1), get_r(y2));
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);

    vector<int> c;

    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    for (int i = 0; i < n; i++) c.eb(a[i]);
    for (int i = 0; i < n; i++) c.eb(b[i]);

    sort(all(c));

    int mx = 0;
    
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(all(c), a[i]) - begin(c);
        mx = max(mx, a[i]);
    }

    for (int i = 0; i < n; i++) {
        b[i] = lower_bound(all(c), b[i]) - begin(c);
        mx = max(mx, b[i]);
    }

    vector<int> d(mx + 1);

    for (int i = 0; i < n; i++) {
        d[a[i]] = b[i];
    }

    debug(d);

    ms_tree<int> ms(d);

    ll res = 0;

    for (int i = 0; i < n; i++) {
        debug(i, a[i], b[i]);
        res += ms.count(a[i], b[i], a[i] + 1, b[i] - 1);
    }

    cout << res << endl;

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
