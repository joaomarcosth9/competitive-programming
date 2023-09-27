#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define endl '\n'
#define cerr if (false) cerr
#endif
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> vis(n + 1);
    for (int &i : a) cin >> i, vis[i] = 1;
    int mex = 0;
    for (int i = 0; i <= n; i++) if (!vis[i]) mex = i;
    a.resize(n + 1);
    a.back() = mex;
    debug(mex);
    k %= (n + 1);
    debug(a);
    debug(k);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = a[(i - k + (n + 1)) % (n + 1)];
    }
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) { cin >> TC;
        int TEST = 1;
        while (TEST <= TC) {
            cerr << "[Testcase " << TEST << "]" << endl;
            solve();
            ++TEST;
        }
    } else solve();
}
