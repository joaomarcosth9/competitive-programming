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
    static const int SIGMA = 26;
    static const char norm = 'a';
    inline int get(int c) { return c - norm; }

    struct node {
        int link, out_link, par;
        char pch;
        vector<int> next;
        bool out;
        vector<int> output;
        node(int link = -1, int out_link = -1, int par = - 1, char pch = -1, bool out = 0) :
            link(link), out_link(out_link), par(par), pch(pch), next(SIGMA, -1), out(out) { }
    };

    vector<node> t = {node(0, 0, 0, -1, 0)};
    int T = 0;

    int insert(const string& s) {
        int u = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            auto v = t[u].next[get(s[i])];
            if (v == -1) {
                t.eb(-1, -1, u, s[i], 0);
                v = (int)t.size() - 1;
                t[u].next[get(s[i])] = v;
            }
            u = v;
        }
        t[u].out = 1;
        t[u].output.emplace_back(T);
        return T++;
    }

    int get_link(int u) {
        if (t[u].link == -1) {
            t[u].link = t[u].par ? go(get_link(t[u].par), t[u].pch) : 0;
        }
        return t[u].link;
    }

    int go(int u, char c) {
        if (t[u].next[get(c)] == -1) {
            t[u].next[get(c)] = u ? go(get_link(u), c) : 0;
        }
        return t[u].next[get(c)];
    }

    int exit(int u) {
        if (t[u].out_link == -1) {
            int v = get_link(u);
            t[u].out_link = (t[v].out || !v) ? v : exit(v);
        }
        return t[u].out_link;
    }

} aho;

void solve() {
    string s; cin >> s;
    int n = size(s);
    int k; cin >> k;
    vector<vector<int>> matches(k);
    vector<int> need(k), sz(k);
    for (int i = 0; i < k; i++) {
        int nd; cin >> nd;
        string b; cin >> b;
        int idx = aho.insert(b);
        sz[idx] = size(b);
        need[idx] = nd;
    }
    int u = 0;
    vector<int> res(k, -1);
    for (int i = 0; i < n; i++) {
        u = aho.go(u, s[i]);
        int v = u;
        while (v != 0) {
            for (auto idx : aho.t[v].output) {
                matches[idx].eb(i);
                if ((int)size(matches[idx]) >= need[idx]) {
                    int first = end(matches[idx])[-need[idx]] - sz[idx] + 1;
                    if (res[idx] == -1) res[idx] = i - first + 1;
                    else res[idx] = min(res[idx], i - first + 1);
                }
            }
            v = aho.exit(v);
        }
    }
    for (int i = 0; i < k; i++) cout << res[i] << endl;
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
