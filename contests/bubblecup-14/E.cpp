#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

bool rec(int l, int r, int last, vector<int> &v, vector<int> &L, vector<int> &R) {
    if (r == l) {
        return v[l] > last;
    }
    if (v[l] <= last && v[r] <= last) {
        return 0;
    }
    if (v[l] > v[r]) {
        return (v[l] > last && L[l] & 1) || (v[r] > last && !rec(l, r - 1, v[r], v, L, R));
    } else if (v[r] > v[l]) {
        return (v[r] > last && R[r] & 1) || (v[l] > last && !rec(l + 1, r, v[l], v, L, R));
    } else {
        return (v[l] > last && !rec(l + 1, r, v[l], v, L, R)) || (v[r] > last && !rec(l, r - 1, v[r], v, L, R));
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> L(n), R(n);
    int last = 0, size = 1;
    for (int i = 1; i <= n; i++) {
        if (i == n || v[i] <= v[i - 1]) {
            for (int j = i - 1; j >= last; j--) {
                L[j] = size++;
            }
            if (i == n) break;
            size = 1;
            last = i;
        }
    }
    last = n - 1, size = 1;
    for (int i = n - 2; i >= -1; i--) {
        if (i == -1 || v[i] <= v[i + 1]) {
            for (int j = i + 1; j <= last; j++) {
                R[j] = size++;
            }
            if (i == -1) break;
            size = 1;
            last = i;
        }
    }
    db(L);
    db(R);
    bool alice = rec(0, n - 1, -1, v, L, R);
    cout << (alice ? "Alice" : "Bob") << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
