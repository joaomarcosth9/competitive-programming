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

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    string s; cin >> s;
    for (int i = 0; i < n; i++) a[i] = s[i] == '1';
    cin >> s;
    for (int i = 0; i < n; i++) b[i] = s[i] == '1';
    a.insert(begin(a), 0);
    b.insert(begin(b), 0);
    b.emplace_back(0);
    a.emplace_back(0);
    debug(a, b);
    int last1 = 0;
    bool inone = 0;
    vector<ii> op;
    for (int i = 1; i <= n + 1; i++) {
        if (a[i]) {
            if (!inone) {
                inone = 1;
                last1 = i;
            }
        } else {
            if (inone) {
                op.eb(last1, i - 1);
                inone = 0;
            }
        }
    }
    vector<int> B(n + 5);
    for (auto [l, r] : op) {
        B[1]++;
        B[l]--;
        B[r + 1]++;
    }
    int ac = 0;
    for (int i = 1; i <= n; i++) {
        ac = (ac + B[i]) % 2;
        if (ac) b[i] ^= 1;
    }
    if (all_of(begin(b) + 1, begin(b) + n, L1(x == 1))) {
        op.eb(1, 1);
        for (int i = 2; i <= n; i++) b[i] ^= 1;
        op.eb(2, n);
        b[1] ^= 1;
        op.eb(1, n);
    }
    if (any_of(all(b), L1(x == 1))) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    cout << size(op) << endl;
    for (auto [l, r] : op) cout << l << " " << r << endl;
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
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
