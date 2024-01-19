#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

vector<string> rotate(vector<string> a) {
    int n = a.size(), m = a[0].size();
    vector<string> res(m, string(n, '.'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[j][n - i - 1] = a[i][j];
        }
    }
    return res;
}

int solve(vector<string> a, int k) {
    int n = a.size(), m = a[0].size();

    int res = 0;

    vector<vector<int>> pref(m, vector<int>(n + 1, 0));
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            pref[j][i + 1] = pref[j][i] + (a[i][j] == '#');
        }
    }
    auto query_column = [&] (int l, int r, int i) {
        return pref[i][min(r + 1, n)] - pref[i][l];
    };

    vector<vector<int>> diag(m + n - 1, vector<int>(1, 0));
    vector<int> min_l(m + n - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == m - 1) {
                min_l[i + j] = i;
            }
            if (j == m - 1 || i == 0) {
                diag[i + j].emplace_back(a[i][j] == '#');
            } else {
                diag[i + j].emplace_back(diag[i + j].back() + (a[i][j] == '#'));
            }
        }
    }
    auto query_diag = [&] (int l, int r, int i) {
        if (i >= m + n - 1) return 0;
        l -= min_l[i];
        r -= min_l[i];
        l = max(l, 0);
        return diag[i][min(r + 1, (int)diag[i].size() - 1)] - diag[i][l];
    };

    for (int i = 0; i < n; i++) {
        int now = 0;
        for (int j = 0; j < min(m, k + 1); j++) {
            now += query_column(i, i + k - j, j);
        }
        res = max(res, now);
        for (int j = 1; j < m; j++) {
            now -= query_column(i, i + k, j - 1);
            now += query_diag(i, i + k, i + j + k);
            res = max(res, now);
        }
    }

    return res;
}

void solve() {
    int n, m, k, res = 0;
    cin >> n >> m >> k;

    vector<string> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    res = max(res, solve(a, k));
    a = rotate(a);
    res = max(res, solve(a, k));
    a = rotate(a);
    res = max(res, solve(a, k));
    a = rotate(a);
    res = max(res, solve(a, k));

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
