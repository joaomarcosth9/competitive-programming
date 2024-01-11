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
    int n, q; cin >> n >> q;
    string s; cin >> s;
    string rs = s;
    reverse(all(rs));
    s = " " + s;
    rs = " " + rs;

    vector<map<int, set<int>>> where(5 * n + 1);
    vector<map<int, set<int>>> rwhere(5 * n + 1);
    vector<ii> location(n + 1);
    vector<ii> rlocation(n + 1);

    ii now = {n, n};
    where[now.first][now.second].emplace(0);
    location[0] = now;

    for (int i = 1; i <= n; i++) {
        if (s[i] == 'L') now.first--;
        else if (s[i] == 'R') now.first++;
        else if (s[i] == 'U') now.second++;
        else if (s[i] == 'D') now.second--;
        where[now.first][now.second].emplace(i);
        location[i] = now;
    }

    rwhere[now.first][now.second].emplace(0);
    rlocation[0] = now;
    for (int i = 1; i <= n; i++) {
        if (rs[i] == 'L') now.first--;
        else if (rs[i] == 'R') now.first++;
        else if (rs[i] == 'U') now.second++;
        else if (rs[i] == 'D') now.second--;
        rwhere[now.first][now.second].emplace(i);
        rlocation[i] = now;
    }

    while (q--) {
        int x, y, l, r; cin >> x >> y >> l >> r;
        x += n; y += n;

        // reversing [l, r]
        auto loc = location[l - 1];
        auto need = ii(x - loc.first, y - loc.second);

        auto revl = n - r;
        auto revr = n - l;
        auto rloc = rlocation[revl];
        auto rneed = ii(rloc.first + need.first, rloc.second + need.second);
        
        auto [X, Y] = rneed;

        auto it = rwhere[X][Y].lower_bound(revl);
        bool db = 0;

        if (it != end(rwhere[X][Y]) && *it <= revr) {
            db = 1;
        }

        // test outside [l, r]
        // first appearance of (x, y) in [0, l - 1] and last appearance of (x, y) in [r + 1, n]

        auto it1 = where[x][y].begin();
        auto it2 = where[x][y].rbegin();

        if (it1 != end(where[x][y]) && *it1 < l) {
            db = 1;
        }
        if (it2 != rend(where[x][y]) && *it2 > r) {
            db = 1;
        }

        cout << (db ? "Yes" : "No") << endl;
    }

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
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
