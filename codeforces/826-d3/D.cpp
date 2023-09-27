#include <bits/stdc++.h>

using namespace std;

int temtestcase = 1;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;
typedef long long ll;

namespace segmin {
    const int neutral = INT_MAX;
    int comp(int a, int b) { return min(a, b); }
    vector<int> tree;
    int n;
    void build(int *st, int *en) {
        int sz = int(en - st);
        for (n = 1; n < sz; n <<= 1)
            ;
        tree.assign(n << 1, neutral);
        for (int i = 0; i < sz; i++) tree[i + n] = st[i];
        for (int i = n + sz - 1; i; i--) tree[i >> 1] = comp(tree[i >> 1], tree[i]);
    }
    void update(int i, int x) {
        tree[i += n] = x;
        for (i >>= 1; i; i >>= 1) tree[i] = comp(tree[i << 1], tree[1 + (i << 1)]);
    }
    int query(int l, int r) {
        int res = neutral;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = comp(res, tree[l++]);
            if (r & 1) res = comp(res, tree[--r]);
        }
        return res;
    }
} // namespace segmin

namespace segmax {
    const int neutral = INT_MIN;
    int comp(int a, int b) { return max(a, b); }
    vector<int> tree;
    int n;
    void build(int *st, int *en) {
        int sz = int(en - st);
        for (n = 1; n < sz; n <<= 1)
            ;
        tree.assign(n << 1, neutral);
        for (int i = 0; i < sz; i++) tree[i + n] = st[i];
        for (int i = n + sz - 1; i; i--) tree[i >> 1] = comp(tree[i >> 1], tree[i]);
    }
    void update(int i, int x) {
        tree[i += n] = x;
        for (i >>= 1; i; i >>= 1) tree[i] = comp(tree[i << 1], tree[1 + (i << 1)]);
    }
    int query(int l, int r) {
        int res = neutral;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = comp(res, tree[l++]);
            if (r & 1) res = comp(res, tree[--r]);
        }
        return res;
    }
} // namespace segmax
int arr[300000];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    segmin::build(arr, arr + n);
    segmax::build(arr, arr + n);
    bool ok = 1;
    for (int i = 2; i <= n / 2 && ok; i *= 2) {
        for (int j = 0; j < n && ok; j += i) {
            int minn = segmin::query(j, j + i - 1);
            int maxx = segmax::query(j, j + i - 1);
            if (maxx - minn > i - 1) {
                ok = 0;
            }
        }
    }
    if (!ok) {
        cout << -1 << endl;
        return;
    }
    int nop = 0;
    for (int i = 2; i <= n; i *= 2) {
        for (int j = 0; j < n; j += i) {
            // j e j + (i-1)
            if (arr[j] > arr[j + i - 1]) {
                swap(arr[j], arr[j + i - 1]);
                nop++;
            }
        }
    }
    cout << nop << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tsts = 1;
    if (temtestcase) cin >> tsts;
    while (tsts--) solve();
    return 0;
}
