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

char next(char u) {
    return u + 1;
}

int dist[6] = {
    3, 1, 4, 1, 5, 9
};

void solve() {
    char st = 'A';
    char p, q; cin >> p >> q;
    if (q < p) swap(p, q);
    if (p == q) {
        cout << 0 << endl;
        return;
    }
    int it = 0;
    while (st != p) {
        st = next(st);
        it++;
    }
    ll dis = 0;
    while (st < q) {
        st = next(st);
        dis += dist[it++];
    }
    cout << dis << endl;
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
