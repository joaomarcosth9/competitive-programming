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

bool solve() {
    int n; cin >> n;
    ll x; cin >> x;
    vector a(3, vector<ll> (n));
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < n; i++) {
            cin >> a[j][i];
        }
    }
    set<int> st;
    for (int j = 0; j < 3; j++) {
        ll u = 0;
        for (int i = 0; i < n; i++) {
            u |= a[j][i];
            st.emplace(u);
        }
    }
    vector<int> b(begin(st), end(st));
    b.eb(0);
    n = size(b);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ll u = b[i] | b[j] | b[k];
                if (u == x) return true;
            }
        }
    }
    return false;
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
        cout << (solve() ? "YES" : "NO") << endl;
        TEST += 1;
    }
}
