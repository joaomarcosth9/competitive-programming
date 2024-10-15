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
void out(bool ans) { cout << (ans ? "YES" : "NO") << endl; }

vector<ll> multiply2(vector<ll> &a, vector<ll> &b) {
    vector<ll> ans(size(a) + size(b) - 1);
    for (int i = 0; i < size(a); i++)
        for (int j = 0; j < size(b); j++)
            ans[i + j] += a[i] * b[j];
    return ans;
}

vector<vector<ll>> polys;

vector<ll> solve(int l, int r) {
    if (l == r) return polys[l];
    int mid = (l + r) / 2;
    auto u = solve(l, mid);
    auto v = solve(mid + 1, r);
    debug(u, v, multiply2(u, v));
    return multiply2(u, v);
}

void solve() {
    string s; cin >> s;
    int n = size(s);
    vector<ll> roots(0, 0);
    for (int i = 1; i < n; i++) {
        int u = (i + 1) * 2;
        if (s[i] != s[i - 1]) roots.eb(u - 1);
    }
    if (roots.empty()) {
        if (s[0] == 'H') cout << "0\n1\n";
        else cout << "0\n-1\n";
        return;
    }
    int m = size(roots);
    for (auto r : roots) polys.eb(vector<ll>{-r, 1});
    auto res = solve(0, m - 1);
    ll p1 = accumulate(all(res), 0ll);
    if (p1 < 0 && s[0] == 'H') for (auto &i : res) i *= -1;
    if (p1 > 0 && s[0] == 'A') for (auto &i : res) i *= -1;
    debug(res);
    reverse(all(res));
    cout << size(res) - 1 << endl;
    for (int i = 0; i < (int)res.size(); i++) cout << to_string(res[i]) << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
    if (TC) { cin >> TC;
        int TEST = 1; while (TEST <= TC) { cerr << "[Testcase " << TEST << "]" << endl;
            solve();
            /* cout << solve() << endl; */
            /* cout << (solve() ? "YES" : "NO") << endl; */
            ++TEST;
        }
    } else solve();
}
