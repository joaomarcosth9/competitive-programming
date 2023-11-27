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

#define int ll

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

struct Dsu {
    vector<int> p;
    int comp = 0;
    vector<ll> sz;
    Dsu(int n) : p(n), sz(n, 1) {
        for (int i = 0; i < n; i++) p[i] = i;
    }
    int find(int a) { return a == p[a] ? a : p[a] = find(p[a]); }
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) assert(false);
        comp--;
        if (sz[a] > sz[b]) swap(a, b);
        sz[b] += sz[a];
        p[a] = b;
        sz[a] = 0;
        return true;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, vector<int>> where;

    for (int i = 0; i < n; i++) {
        where[a[i]].eb(i);
    }

    vector<int> jump(n), lm(n), rm(n);
    ll res = 0;

    set<int> vals;
    for (auto u : a) vals.emplace(u);
    if (*begin(vals) == 0) vals.erase(begin(vals));

    Dsu dsu(n);

    auto apply = [&] (int i) {
        jump[i] = 1;
        if (i > 0 && i < n - 1) dsu.comp++;
        bool l = i > 0 && jump[i - 1] == 1;
        bool r = i < n - 1 && jump[i + 1] == 1;
        if (l && r) {
            dsu.unite(i, i + 1);
            dsu.unite(i, i - 1);
        } else if (l) {
            dsu.unite(i, i - 1);
        } else if (r) {
            dsu.unite(i, i + 1);
        }
    };

    for (auto u : where[0]) apply(u);

    int last = 0;
    for (auto val : vals) {
        res += (val - last) * dsu.comp + (val - last);
        debug(res, val, last, dsu.comp, val - last);

        for (auto u : where[val]) apply(u);

        last = val;

    }

    cout << res - 1 << endl;
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
