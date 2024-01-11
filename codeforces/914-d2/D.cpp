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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

struct SparseTableMax {
    int n, e;
    vector<vector<int>> st;
    SparseTableMax(vector<int> &v) : n(v.size()), e(floor(log2(n))) {
        st.assign(e + 1, vector<int> (n));
        for (int i = 0; i < n; i++) st[0][i] = v[i];
        for (int i = 1; i <= e; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int query(int l, int r) {
        int i = ilogb(r - l + 1);
        return max(st[i][l], st[i][r - (1 << i) + 1]);
    }
};

struct SparseTableMin {
    int n, e;
    vector<vector<int>> st;
    SparseTableMin(vector<int> &v) : n(v.size()), e(floor(log2(n))) {
        st.assign(e + 1, vector<int> (n));
        for (int i = 0; i < n; i++) st[0][i] = v[i];
        for (int i = 1; i <= e; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int query(int l, int r) {
        int i = ilogb(r - l + 1);
        return min(st[i][l], st[i][r - (1 << i) + 1]);
    }
};

bool solve() {
    int n; cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < n; j++) cin >> b[j];

    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            return 0;
        }
    }

    SparseTableMax stmax(a);
    SparseTableMin stmin(b);

    vector<int> last(n + 1, -1);
    vector<ii> poss(n, {-1, -1});

    for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) {
            poss[i].first = last[b[i]];
        }
        last[a[i]] = i;
    }

    last.assign(n + 1, -1);
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] < b[i]) {
            poss[i].second = last[b[i]];
        }
        last[a[i]] = i;
    }

    vector<vector<int>> st(n + 1);
    for (int i = 0; i < n; i++) st[b[i]].eb(i);

    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) continue;

        auto [L, R] = poss[i];
        debug(i, a[i], b[i], L, R);

        bool db = 0;

        if (L != -1) {
            auto mxa = stmax.query(L, i);
            auto mnb = stmin.query(L, i);
            bool nowdb = 1;
            nowdb &= mxa == b[i];
            nowdb &= mnb == b[i];
            db |= nowdb;
        }

        if (R != -1) {
            auto mxa = stmax.query(i, R);
            auto mnb = stmin.query(i, R);
            bool nowdb = 1;
            nowdb &= mxa == b[i];
            nowdb &= mnb == b[i];
            db |= nowdb;
        }

        if (!db) return 0;
    }

    return 1;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        /* solve(); */
        /* cout << solve() << endl; */
        cout << (solve() ? "Yes" : "No") << endl;
        TEST += 1;
    }
}
