#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

bool triangle(int a, int b, int c) {
    return a + b > c && a + c > b && b + c > a;
}

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<array<int, 6>> poss;

    for (int i = 0; i < (1 << 6); i++) {
        if (__builtin_popcount(i) == 3) {
            array<int, 6> p;
            int it = 0;
            for (int j = 0; j < 6; j++) {
                if (i & (1 << j)) {
                    p[it++] = j;
                }
            }
            for (int j = 0; j < 6; j++) {
                if (~i & (1 << j)) {
                    p[it++] = j;
                }
            }
            poss.push_back(p);
        }
    }

    while (q--) {
        int l, r; cin >> l >> r;
        l--; r--;
        int m = (r - l + 1);
        if (m <= 60) {
            vector<int> b(a.begin() + l, a.begin() + r + 1);
            sort(b.begin(), b.end());
            int cnt = 0;
            bool db = 0;

            for (int i = 0; i + 5 < (int)b.size(); i++) {
                for (auto [j, k, l, o, p, q] : poss) {
                    if (triangle(b[i + j], b[i + k], b[i + l]) && triangle(b[i + o], b[i + p], b[i + q])) {
                        db = 1;
                        break;
                    }
                }
            }

            cout << (db ? "YES" : "NO") << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}

