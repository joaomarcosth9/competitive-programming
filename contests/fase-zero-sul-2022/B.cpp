#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

/* #define int long long */

const int maxm = 1e3 + 5, mod = 1e9 + 9;

long long t;
int m;
long long arr[maxm];

typedef array<array<int, 3>, 3> mat3;
typedef array<array<int, 2>, 2> mat2;

mat3 neutral3 = {{
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
}};

mat3 id3 = {{
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1},
}};

mat3 mul3(mat3 &a, mat3 &b) {
    mat3 res = neutral3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                res[i][j] = ((1ll * res[i][j] + 1ll * a[i][k] * b[k][j]) + mod) % mod;
            }
        }
    }
    return res;
}

mat2 neutral2 = {{
    {0, 0},
    {0, 0},
}};

mat2 id2 = {{
    {1, 0},
    {0, 1},
}};

mat2 mul2(mat2 &a, mat2 &b) {
    mat2 res = neutral2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                res[i][j] = ((1ll * res[i][j] + 1ll * a[i][k] * b[k][j]) + mod) % mod;
            }
        }
    }
    return res;
}

mat3 binpow3(mat3 b, long long e) {
    mat3 res = id3;
    while (e) {
        if (e & 1) res = mul3(res, b);
        b = mul3(b, b);
        e >>= 1;
    }
    return res;
}

mat2 binpow2(mat2 b, long long e) {
    mat2 res = id2;
    while (e) {
        if (e & 1) res = mul2(res, b);
        b = mul2(b, b);
        e >>= 1;
    }
    return res;
}

int binpow(long long b, long long e) {
    int res = 1;
    while (e) {
        if (e & 1) res = 1ll * res * b % mod;
        b = 1ll * b * b % mod;
        e >>= 1;
    }
    return res;
}

void solve() {
    cin >> t >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }
    int G = (4ll * t - 1) % mod;
    sort(arr, arr + m);
    reverse(arr, arr + m);
    mat3 base3 = {{
        {1, 0, 0},
        {1, 0, 0},
        {1, 0, 0},
    }};
    mat3 rec3 = {{
        {(mod + 1) / 2, (mod + 1) / 2, 0},
        {1ll * (mod - G) * (mod + 1) / 2 % mod, (mod + 1) / 2, 0},
        {1, 0, 1},
    }};
    debug(rec3);
    rec3 = mul3(rec3, id3);
    debug(rec3);
    mat2 base2 = {{
        {1, 0},
        {1, 0},
    }};
    mat2 rec2 = {{{1, 1}, {mod - G, 1}}};
    debug(G);
    auto REC3 = binpow3(rec3, arr[0] - 1);
    mat3 resL = mul3(REC3, base3);
    debug(resL);
    int res = (1ll * resL[2][0] - 1 + mod) % mod;
    for (int i = 1; i < m; i++) {
        auto REC2 = binpow2(rec2, arr[i] - 1);
        mat2 resm = mul2(REC2, base2);
        debug(resm);
        res = (1ll * res - (1ll * resm[0][0] * binpow((mod + 1) / 2, arr[i] - 1) % mod) + mod) % mod;
    }
    cout << res << '\n';
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
