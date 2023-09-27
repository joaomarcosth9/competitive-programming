#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

typedef vector<vector<long long>> mat;
const int mod = 1e9 + 7;

mat mul(mat &a, mat &b) {
    mat res(a.size(), vector<long long>(b[0].size()));
    for (int i = 0; i < (int)a.size(); i++) {
        for (int j = 0; j < (int)b[0].size(); j++) {
            for (int k = 0; k < (int)a[0].size(); k++) {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % mod;
            }
        }
    }
    return res;
}

mat binpow(mat a, long long e) {
    mat res(a.size(), vector<long long>(a[0].size()));
    for (int i = 0; i < (int)a.size(); i++) res[i][i] = 1;
    while (e) {
        if (e & 1) res = mul(a, res);
        a = mul(a, a);
        e >>= 1;
    }
    return res;
}

void solve() {
    long long n;
    cin >> n;
    mat base = {{1}, {0}, {0}, {0}, {0}};
    vector<long long> first = {16, 9, 4, 1, 0};
    mat rec(5, vector<long long>(5));
    rec[0] = first;
    for (int i = 1; i < 5; i++) {
        rec[i][i - 1] = 1;
    }
    db(rec);
    mat id(5, vector<long long>(5));
    for (int i = 0; i < 5; i++) {
        id[i][i] = 1;
    }
    mat teste = mul(rec, id);
    db(teste);
    rec = binpow(rec, n / 10);
    db(rec);
    mat res = mul(rec, base);
    long long ress = 0;
    db(res);
    for (int i = 0; i < 5; i++) {
        if (i == 4 && n >= 45 && (n % 10 >= 5)) continue;
        ress += res[i][0];
    }
    ress %= mod;
    cout << ress << endl;
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
