#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
 
struct base {
    double a, b;
    base(double _a = 0, double _b = 0) : a(_a), b(_b) { }
    const base operator+(const base &c) const { return base(a + c.a, b + c.b); }
    const base operator-(const base &c) const { return base(a - c.a, b - c.b); }
    const base operator*(const base &c) const {
        return base(a * c.a - b * c.b, a * c.b + b * c.a);
    }
};

using poly = vector<base>;
const double PI = acos(-1);

void fft(poly &a, bool inv = 0) {
    int n = (int)a.size();

    for (int i = 0; i < n; i++) {
        int bit = n >> 1, j = 0, k = i;
        while (bit > 0) {
            if (k & 1) j += bit;
            k >>= 1, bit >>= 1;
        }
        if (i < j) swap(a[i], a[j]);
    }

    double angle = 2 * PI / n * (inv ? -1 : 1);
    poly wn(n / 2);
    for (int i = 0; i < n / 2; i++) wn[i] = {cos(angle * i), sin(angle * i)};

    for (int len = 2; len <= n; len <<= 1) {
        int aux = len / 2;
        int step = n / len;
        for (int i = 0; i < n; i += len) {
            for (int j = 0; j < aux; j++) {
                base v = a[i + j + aux] * wn[step * j];
                a[i + j + aux] = a[i + j] - v;
                a[i + j] = a[i + j] + v;
            }
        }
    }

    for (int i = 0; inv && i < n; i++) a[i].a /= n, a[i].b /= n;
}

vector<ll> multiply(vector<int> &ta, vector<int> &tb) {
    int n = int(ta.size()), m = int(tb.size());
    int t = n + m - 1, sz = 1;
    while (sz < t) sz <<= 1;

    poly a(sz), b(sz), c(sz);

    for (int i = 0; i < sz; i++) {
        a[i] = i < n ? base((double)ta[i]) : base(0);
        b[i] = i < m ? base((double)tb[i]) : base(0);
    }

    fft(a, 0), fft(b, 0);
    for (int i = 0; i < sz; i++) c[i] = a[i] * b[i];
    fft(c, 1);

    vector<ll> res(sz);
    for (int i = 0; i < sz; i++) res[i] = ll(round(c[i].a));

    while ((int)res.size() > t && res.back() == 0) res.pop_back();

    return res;
}
 
void solve() {
    int k; cin >> k;
    int n, m; cin >> n >> m;
    vector<int> a(k + 1), b(k + 1);
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        a[c]++;
    }
    for (int i = 0; i < m; i++) {
        int c; cin >> c;
        b[c]++;
    }
    auto c = multiply(a, b);
    c.resize(2 * k + 2);
    for (int i = 2; i <= 2 * k; i++) {
        cout << c[i] << " ";
    }
    cout << endl;
}
 
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}
