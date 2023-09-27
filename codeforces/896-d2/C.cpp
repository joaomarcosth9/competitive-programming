#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define endl '\n'
#define cerr                                                                                                           \
    if (false) cerr
#endif
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto &x) { return res; }
#define L2(res...) [&](const auto &x, const auto &y) { return res; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

void solve() {
    int n, m;
    cin >> n >> m;
    vector mat(n, vector<int>(m));
    int next = 0;
    for (int i = 0; i < n; i++) {
        int num = next;
        for (int j = 0; j < m; j++) {
            mat[i][j] = num;
            num += 1;
            num %= m;
        }
        debug(mat[i]);
        next += 1;
        next %= m;
    }
    /* cout << "Antes" << endl; */
    /* for (int i = 0; i < n; i++) { */
    /*     for (int j = 0; j < m; j++) { */
    /*         cout << mat[i][j] << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */
    /* cout << "---" << endl; */

    if (m <= n) {
        for (int j = 0; j < m - 1; j += 1) {
            swap(mat[0][j], mat[0][j + 1]);
        }
        for (int i = m; i < n; i++) {
            mat[i] = mat[i - 1];
        }
    }

    vector<int> vis2(m + 5);

    for (int j = 0; j < m; j++) {
        set<int> st;
        for (int i = 0; i < n; i++) {
            st.emplace(mat[i][j]);
        }
        int mex = 0;
        debug(st);
        while (st.size() && *st.begin() == mex) {
            mex += 1;
            st.erase(st.begin());
        }
        vis2[mex] = 1;
    }
    int res = -1;

    for (int i = 0; i < m + 5; i++) {
        if (!vis2[i]) {
            res = i;
            break;
        }
    }

    cout << res << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        int TEST = 1;
        while (TEST <= TC) {
            cerr << "[Testcase " << TEST << "]" << endl;
            solve();
            ++TEST;
        }
    } else
        solve();
}
