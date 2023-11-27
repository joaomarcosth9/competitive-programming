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

ll solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    for (ll &i : a) cin >> i;
    for (ll &i : b) cin >> i;
    sort(all(a));
    sort(all(b));
    debug(a);
    debug(b);
    k = min(k, 50 + (k & 1));

    multiset<ll> A(begin(a), end(a));
    multiset<ll> B(begin(b), end(b));

    int curr = 1;
    while (k--) {
        if (curr) {
            ll u = *begin(A);
            ll v = *rbegin(B);
            if (u <= v) {
                A.erase(begin(A));
                B.erase(--end(B));
                A.emplace(v);
                B.emplace(u);
            }
        } else {
            swap(A, B);
            ll u = *begin(A);
            ll v = *rbegin(B);
            if (u <= v) {
                A.erase(begin(A));
                B.erase(--end(B));
                A.emplace(v);
                B.emplace(u);
            }
            swap(A, B);
        }
        curr ^= 1;
    }

    ll ans = 0;
    while (A.size()) ans += *begin(A), A.erase(begin(A));
    return ans;
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
