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
    int n; cin >> n;
    string s; cin >> s;

    if (n == 1) {
        return 1;
    }

    vector<int> f(26);

    for (int i = 0; i < n; i++) f[s[i] - 'a']++;

    debug(f);

    multiset<int> st(all(f));

    if (st.find(0) != end(st)) st.erase(0);

    while (st.size() > 1) {
        debug(st);
        auto mn = *begin(st);
        auto mx = *rbegin(st);
        st.erase(begin(st));
        st.erase(--end(st));
        if (mn > 1) st.emplace(mn - 1);
        if (mx > 1) st.emplace(mx - 1);
    }
    if (st.size()) return *begin(st);
    else return 0;
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
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
