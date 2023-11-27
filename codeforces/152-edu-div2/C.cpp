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

void solve() {
    int n; cin >> n;
    int m; cin >> m;
    string s; cin >> s;
    set<ii> st;
    vector<int> len0(n), len1(n), sz0(n), sz1(n);
    len0[0] = s[0] == '0';
    sz1[0] = s[0] == '1';
    for (int i = 1; i < n; i++) {
        len0[i] = len0[i - 1] + 1;
        sz1[i] = sz1[i - 1] + 1;
        if (s[i] == '1') len0[i] = 0;
        if (s[i] == '0') sz1[i] = 0;
    }
    len1[n - 1] = s[n - 1] == '1';
    sz0[n - 1] = s[n - 1] == '0';
    for (int i = n - 2; i >= 0; i--) {
        len1[i] = len1[i + 1] + 1;
        sz0[i] = sz0[i + 1] + 1;
        if (s[i] == '0') len1[i] = 0;
        if (s[i] == '1') sz0[i] = 0;
    }
    int nothing = 0;
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        l--; r--;
        int L = l - (l > 0 ? len0[l - 1] : 0);
        int R = r + (r < n - 1 ? len1[r + 1] : 0);
        if (sz0[L] + sz1[R] >= (R - L + 1)) nothing = 1;
        else st.emplace(L, R);
    }
    debug(st);
    cout << st.size() + nothing << endl;
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
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
