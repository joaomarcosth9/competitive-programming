#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 4e5 + 5;
int a, b, n, m;
int x[N], y[N], k[N];
char cmv[N];
vector<pair<int, int>> vals;
int ix, fx, iy, fy;
tuple<int, int, int, int> query[N];

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
    cin >> a >> b >> n >> m;
    vals.clear();

    ix = 1;
    iy = 1;
    fx = a;
    fy = b;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        vals.push_back({y[i], x[i]});
    }
    for (int i = 0; i < m; i++) {
        cin >> cmv[i] >> k[i];
    }

    sort(vals.begin(), vals.end());

    int l = 0, r = n - 1;

    debug(vals);
    debug(iy, fy);
    debug(l, r);
    for (int i = 0; i < m; i++) {
        // [l, r, a, b] for each i
        debug(cmv[i], k[i]);
        if (cmv[i] == 'D' || cmv[i] == 'U') { // [a, b] will change
            if (cmv[i] == 'D') fx -= k[i];
            else if (cmv[i] == 'U') ix += k[i];
        } else { // [l, r] will change
            if (cmv[i] == 'L') {
                iy += k[i];
            } else if (cmv[i] == 'R') {
                fy -= k[i];
            }
            while (l < n && vals[l].first < iy) {
                l++;
            }
            while (r >= 0 && vals[r].first > fy) {
                r--;
            }
        }
        assert(ix <= fx);
        assert(iy <= fy);
        query[i] = {l, r, ix, fx};
        debug(i, query[i]);
    }

    vector<int> aux;
    for (int i = 0; i < n; i++) {
        aux.push_back(vals[i].second);
    }

    /* MergeSortTree ms; */
    /* ms.build(aux); */

    ms_tree ms(aux);

    int has = n;
    vector<int> p(2);
    int t = 0;
    for (int i = 0; i < m; i++) {
        auto [L, R, aa, bb] = query[i];
        int old = has;
        has = ms.count(L, R, aa, bb);
        p[t] += old - has;
        t ^= 1;
    }
    cout << p[0] << " " << p[1] << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        vals.clear();
        for (int i = 0; i <= n; i++) {
            x[i] = y[i] = 0;
        }
        for (int i = 0; i <= m; i++) {
            cmv[i] = char(k[i] = 0);
            query[i] = {0, 0, 0, 0};
        }
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
