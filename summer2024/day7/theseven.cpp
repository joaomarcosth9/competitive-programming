#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int ll
using ll = long long;

const int N = 100100;
int n, a[N], b[N];

void solve() {
    n = 7;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    a[0] = -1;
    sort(a, a + n);
    set<int> res;
    for (int i = 0; i < n; i++) {
        int r = -1;
        assert(a[i] == -1);
        if (i > 2) {
            r = a[1] - a[0];
            a[i] = a[i - 1] + r;
        } else {
            r = a[6] - a[5];
            a[i] = a[i + 1] - r;
        }
        bool db = 1;
        for (int j = 1; j < n; j++) {
            db &= a[j] - a[j - 1] == r;
        }
        if (db) {
            if (a[i] > 0) res.emplace(a[i]);
        }
        a[i] = -1;
        swap(a[i], a[i + 1]);
    }
    for (auto u : res) cout << u << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
