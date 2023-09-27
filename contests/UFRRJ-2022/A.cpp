#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7, p = 2;
const int MAXN = 3e5 + 5;
int arr[MAXN], n;

int inv_mod(int a) {
    int x, y;
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = MOD;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    int g = a1;
    x = (x % MOD + MOD) % MOD;
    return x;
}

void add(int &a, int b) {
    a = (a + b) % MOD;
    if (a < 0) a += MOD;
}
void mult(int &a, int b) {
    a = (a * b) % MOD;
    if (a < 0) a += MOD;
}

int bin_pow(int b, int e) {
    int v = b;
    int res = 1;
    while (e) {
        if (e & 1) mult(res, v);
        mult(v, v);
        e >>= 1;
    }
    return res;
}

struct fenwick_hash {
    int ft[MAXN];
    fenwick_hash() { memset(ft, 0, sizeof(ft)); }
    int query(int i) {
        int res = 0;
        for (; i; i -= (i & -i)) {
            add(res, ft[i]);
        }
        return res;
    }
    int query(int l, int r) {
        int res = query(r) - query(l - 1);
        int inv = inv_mod(bin_pow(p, l));
        mult(res, inv);
        return res;
    }
    void update(int i) {
        int val = bin_pow(p, i);
        for (; i <= MAXN - 3; i += (i & -i)) {
            add(ft[i], val);
        }
    }
};

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    auto rev = [&](int i) { return n - i + 1; };

    fenwick_hash ft1, ft2;

    for (int i = 0; i < n; i++) {
        ft1.update(arr[i]);
        ft2.update(rev(arr[i]));

        int k = min(arr[i] - 1, n - arr[i]);
        int l = arr[i] - k, r = arr[i] + k;

        if (ft1.query(l, arr[i] - 1) != ft2.query(rev(r), rev(arr[i] + 1))) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
