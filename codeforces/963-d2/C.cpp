#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
#define int ll

pair<int, int> intersect(pair<int, int> a, pair<int, int> b) {
    if (a.first == -1 || b.first == -1) return {-1, -1};

    if (a.second <= b.first) return {-1, -1};
    if (b.second <= a.first) return {-1, -1};

    if (a.first >= b.first && a.second <= b.second) return a;
    if (b.first >= a.first && b.second <= a.second) return b;

    if (a.first <= b.first) {
        return {b.first, a.second};
    } else {
        return {a.first, b.second};
    }
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    sort(begin(a), end(a));

    vector<pair<int, int>> b(n);

    b.back() = {0, k};

    for (int i = n - 2; i >= 0; i--) {
        int qnt = (a.back() - a[i]) / k;
        a[i] += qnt * k;
        if (qnt & 1) {
            b[i] = {a[i] - a.back() + k, a[i] - a.back() + 2 * k};
        } else {
            b[i] = {0, a[i] - a.back() + k};
        }
    }

    pair<int, int> inter = {0, k};

    for (int i = 0; i < n; i++) {
        inter = intersect(inter, b[i]);
    }

    if (inter.first == -1) {
        cout << -1 << endl;
    } else {
        cout << inter.first + a.back() << endl;
    }

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