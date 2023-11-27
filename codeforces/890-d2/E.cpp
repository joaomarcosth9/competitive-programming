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

template<int len> ll solve(vector<int>& a, int sz) {
    if (len <= sz) {
        return solve<min(1000006, len << 1)> (a, sz);
    }
    bitset<len> dp;
    dp[0] = 1;
    for (int i = 0; i < (int)size(a); i++) {
        dp = dp | (dp << a[i]);
    }
    ll best = 0;
    for (int i = 0; i <= sz; i++) {
        if (dp[i]) {
            best = max(best, (ll)i * ((ll)sz - 1 - i));
        }
    }
    return best;
}

const int maxn = 1001006;
vector<int> adj[maxn];;
ll res = 0;
int sz[maxn];

void dfs(int u) {
    sz[u] = 1;
    vector<int> a;
    for (int v : adj[u]) {
        dfs(v);
        sz[u] += sz[v];
        a.emplace_back(sz[v]);
    }
    if (a.empty()) return;
    sort(all(a));
    if (a.back() >= accumulate(all(a), 0) - a.back()) {
        res += (ll)a.back() * (accumulate(all(a), 0) - a.back());
        return;
    }
    vector<ii> b = {{a[0], 1}};
    for (int i = 1; i < (int)a.size(); i++) {
        if (b.back().first == a[i]) {
            b.back().second++;
        } else {
            b.eb(a[i], 1);
        }
    }
    a.clear();
    for (auto [x, f] : b) {
        int pot = 1;
        while (f >= pot) {
            a.eb(x * pot);
            f -= pot;
            pot *= 2;
        }
        if (f) {
            a.eb(x * f);
        }
    }
    res += solve<1>(a, (size_t)sz[u]);
}

void solve() {
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int p; cin >> p;
        adj[p - 1].emplace_back(i);
    }
    dfs(0);
    cout << res << endl;
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
