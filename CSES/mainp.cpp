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
 
struct AC {
    const int SIGMA = 26;
    const char norm = 'a';
    inline int get(int c) { return c - norm; }
 
    vector<int> link, out_link, par;
    vector<char> pch;
    vector<vector<int>> next;
    vector<bool> out;
    vector<vector<int>> output;
 
    AC() { node(); }
 
    int node(int p = -1, char c = -1) {
        link.emplace_back(-1);
        out_link.emplace_back(-1);
        par.emplace_back(p);
        pch.emplace_back(c);
        next.emplace_back(SIGMA, -1);
        out.emplace_back(0);
        output.emplace_back();
        return (int)link.size() - 1;
    }
 
    int T = 0;
 
    int insert(const string& s) {
        int u = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            auto v = next[u][get(s[i])];
            if (v == -1) {
                next[u][get(s[i])] = v = node(u, s[i]);
            }
            u = v;
        }
        out[u] = true;
        output[u].emplace_back(T);
        return T++;
    }
 
    int get_link(int u) {
        if (link[u] == -1) {
            link[u] = par[u] ? go(get_link(par[u]), pch[u]) : 0;
        }
        return link[u];
    }
 
    int go(int u, char c) {
        if (next[u][get(c)] == -1) {
            next[u][get(c)] = u ? go(get_link(u), c) : 0;
        }
        return next[u][get(c)];
    }
 
    int exit(int u) {
        if (out_link[u] == -1) {
            int v = get_link(u);
            out_link[u] = (out[v] || !v) ? v : exit(v);
        }
        return out_link[u];
    }
 
} aho;
 
const int mod = 1e9 + 7;
 
void solve() {
    string s; cin >> s;
    int q; cin >> q;
    vector<int> len(q);
    for (int i = 0; i < q; i++) {
        string b; cin >> b;
        int x = aho.insert(b);
        len[x] = size(b);
    }
    int n = size(s);
    int v = 0;
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        v = aho.go(v, s[i]);
        int u = v; 
        while (u) {
            for (auto x : aho.output[u]) dp[i + 1] = (dp[i + 1] + dp[i + 1 - len[x]]) % mod;
            u = aho.exit(u);
        }
    }
    cout << dp[n] << endl;
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
