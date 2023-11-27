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

const ll mod = 998244353;

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    vector<ll> pref_xor(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pref_xor[i + 1] = pref_xor[i] ^ a[i];
    }
    auto query = [&](int l, int r) {
        return pref_xor[r + 1] ^ pref_xor[l];
    };
    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            res = (res + (query(i, j) * (j - i + 1)) % mod) % mod;
        }
    }
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
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
