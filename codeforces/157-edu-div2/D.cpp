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

vector<int> on, off;

void insert(int num) {
    int u = 0;
    for (int i = 21; i >= 0; i--) {
        if (num & (1 << i)) {
            if (on[u] == -1) {
                int v = size(on);
                on.eb(-1);
                off.eb(-1);
                on[u] = v;
            }
            u = on[u];
        } else {
            if (off[u] == -1) {
                int v = size(off);
                on.eb(-1);
                off.eb(-1);
                off[u] = v;
            }
            u = off[u];
        }
    }
}

int search(int num) {
    int res = 0;
    int u = 0;
    for (int i = 21; i >= 0; i--) {
        if (num & (1 << i)) {
            if (off[u] != -1) {
                u = off[u];
                res ^= (1 << i);
            } else {
                u = on[u];
            }
        } else {
            if (on[u] != -1) {
                u = on[u];
                res ^= (1 << i);
            } else {
                u = off[u];
            }
        }
    }
    return res;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n - 1);
    for (int &i : a) cin >> i;
    insert(a[0]);
    for (int i = 0; i < n - 2; i++) {
        a[i + 1] ^= a[i];
        insert(a[i + 1]);
    }
    debug(a);
    debug(on);
    debug(off);
    for (int i = 0; i < n; i++) {
        int q = search(i);
        debug(i, q);
        if (q < n) {
            cout << i << " ";
            for (auto u : a) cout << (u ^ i) << " ";
            cout << endl;
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
    on.eb(-1);
    off.eb(-1);
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
