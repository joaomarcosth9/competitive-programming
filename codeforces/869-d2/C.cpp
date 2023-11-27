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

const int maxn = 200200;
int a[maxn], n, q;
int mark[maxn];
int R[maxn];
int pref[maxn];

int query(int l, int r) {
    if (l > r) return 0;
    return pref[r + 1] - pref[l];
}

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n - 2; i++) {
        if (a[i] >= a[i + 1] && a[i + 1] >= a[i + 2]) {
            mark[i + 1] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + mark[i - 1];
    }
    while (q--) {
        int l, r; cin >> l >> r;
        l--; r--;
        cout << (r - l + 1) - query(l + 1, r - 1) << endl;
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
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
