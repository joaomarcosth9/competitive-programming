#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    vector<int> a(n + 2, 1);
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == 'L') {
            a[i] = 1;
        } else if (s[i - 1] == 'W') {
            a[i] = 2;
        } else if (s[i - 1] == 'C') {
            a[i] = 0;
        }
    }
    vector<int> nxt(n + 2, n + 1);
    for (int i = n; i >= 0; i--) {
        nxt[i] = nxt[i + 1];
        if (a[i] != 2) {
            nxt[i] = i;
        }
    }
    int i = 0;
    while (i < n + 1) {
        assert(a[i] == 1);
        bool done = 0;
        for (int jump = 1; jump <= m; jump++) {
            if (i + jump <= n + 1 && a[i + jump] == 1) {
                i = i + jump;
                done = 1;
                break;
            }
        }
        if (done) {
            continue;
        }
        // cannot jump to any safe place
        for (int jump = m; jump >= 1; jump--) {
            if (i + jump <= n + 1) {
                int nxt_ = nxt[i + jump];
                int dist = nxt_ - (i + jump);
                if (a[nxt_] == 0 || dist > k) {
                    continue;
                } else {
                    k -= dist;
                    i = nxt_;
                    done = 1;
                    break;
                }
            }
        }
        if (done) {
            continue;
        }
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}
