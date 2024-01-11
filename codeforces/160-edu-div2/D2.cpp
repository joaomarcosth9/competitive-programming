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

struct SparseTable {
    int n, e;
    typedef vector<ii> vii;
    vector<vii> st;
    SparseTable() { }
    SparseTable(vii &v) : n(v.size()), e(32 - __builtin_clz(n)) {
        st.assign(e + 1, vii(n));
        for (int i = 0; i < n; i++) st[0][i] = v[i];
        for (int i = 1; i <= e; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    ii query(int l, int r) {
        int i = ilogb(r - l + 1);
        return min(st[i][l], st[i][r - (1 << i) + 1]);
    }
};

SparseTable st;

const int mod = 998244353;

ll solve(int l, int r, int dir) {
    if (l > r) return 1;
    auto [val, id] = st.query(l, r);
    ll L = solve(l, id - 1, dir | 1);
    ll R = solve(id + 1, r, dir | 2);
    ll ret = L * R % mod;
    if (dir & 1) ret = (ret + L) % mod;
    if (dir & 2) ret = (ret + R) % mod;
    if (dir == 3) ret = (ret - 1 + mod) % mod;
    return ret;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ii> b(n);

    for (int i = 0; i < n; i++) {
        b[i] = {a[i], i};
    }

    st = SparseTable(b);

    auto [mn, id] = st.query(0, n - 1);
    
    cout << (solve(0, id - 1, 1) * solve(id + 1, n - 1, 2) % mod) << endl;
    
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
