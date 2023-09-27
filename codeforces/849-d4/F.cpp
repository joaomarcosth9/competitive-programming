#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef pair<int, int> ii;
int testcases = 1;
const int INF = 1.05e9;
const ll INFLL = 4.5e18;
#define endl '\n'
#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#define dbarr(x...)
#endif

int sumd(int n) {
    int res = 0;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

const int maxn = 3e5;
int n;
int bit[maxn], arr[maxn][9];

fenwick(int n) { bit.assign(n + 1, 0); }
int rsq(int i) {
    int res = 0;
    for (; i; i -= (i & -i)) {
        res += bit[i];
    }
    return res;
}
void update_bit(int i, int v) {
    for (; i <= n; i += (i & -i)) {
        bit[i] += v;
    }
}

void update(int l, int r, int v) {
    update_bit(l, v);
    update_bit(r + 1, -v);
}

void solve() {
    int q;
    cin >> n >> q;
    for (int i = 0; i <= n; i++) bit[i] = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0];
        for (int j = 1; j < 9; j++) {
            arr[i][j] = sumd(arr[i][j - 1]);
        }
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            cin >> l >> r;
            update(l, r, 1);
            db(rsq(l), rsq(l + 1), rsq(r), rsq(r + 1));
        } else {
            int i;
            cin >> i;
            int op = min(8, rsq(i));
            cout << arr[i - 1][op] << endl;
        }
    }
}

signed main() {
#ifndef LOCAL_DEBUG
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tsts = 1;
    if (testcases) cin >> tsts;
    while (tsts--) solve();
    return 0;
}
