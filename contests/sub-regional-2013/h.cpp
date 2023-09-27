#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif
#define mod 1000000ll

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> mat;

mat id(int n) {
    mat res(n, vi(n));
    for (int i = 0; i < n; i++) res[i][i] = 1;
    return res;
}

mat mul(mat &a, mat &b) {
    mat res(a.size(), vi(b[0].size()));
    for (int i = 0; i < (int)a.size(); i++) {
        for (int j = 0; j < (int)b[0].size(); j++) {
            for (int k = 0; k < (int)a[0].size(); k++) {
                res[i][j] = (res[i][j] + (a[i][k] * b[k][j] % mod)) % mod;
            }
        }
    }
    return res;
}

mat binpow(mat a, ll e) {
    mat res = id((int)a.size());
    while (e) {
        if (e & 1) res = mul(a, res);
        a = mul(a, a);
        e >>= 1;
    }
    return res;
}

void solve() {
    ll n, k, l;
    scanf("%lld %lld %lld", &n, &k, &l);
    n /= 5;
    k %= mod;
    l %= mod;
    mat rec = {{k, l}, {1, 0}};
    rec = binpow(rec, n + 1);
    printf("%.6lld\n", rec[1][0]);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    solve();
    return 0;
}
