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

int solve() {
    int t, n; cin >> t >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    sort(all(a));

    debug(t, n);
    debug(a);

    int res = 0;
    multiset<int, greater<int>> st;
    for (int i = 0; i < n - 1; i++) {
        st.emplace(abs(a[i + 1] - a[i]) - 1);
    }
    st.emplace((a[0] - 1) + (t - a[n - 1]));
    debug(st);

    for (int time = 0; st.size();) {
        auto u = *begin(st);
        st.erase(begin(st));
        u -= 2 * time;
        if (u <= 0) break;
        res += 1;
        time++;
        u -= 2;
        if (u <= 0) continue;
        res += u;
        time++;
    }

    debug(t, res);

    return t - res;
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
        cout << solve() << endl;
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
