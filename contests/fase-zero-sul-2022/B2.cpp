#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long ll;

const int maxm = 1e3 + 5;
const ll mod = 1e9 + 9;
const ll inv2 = (mod + 1) / 2;

typedef array<array<ll, 3>, 3> mat;

mat neutral = {{
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
}};

mat id = {{
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1},
}};

mat mul(mat &a, mat &b) {
    mat res = neutral;
    for (int i = 0; i < (int)a.size(); i++) {
        for (int j = 0; j < (int)b[0].size(); j++) {
            for (int k = 0; k < (int)a[0].size(); k++) {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % mod;
            }
        }
    }
    return res;
}

mat binpowmat(mat b, ll e) {
    mat res = id;
    while (e) {
        if (e & 1) res = mul(res, b);
        b = mul(b, b);
        e >>= 1;
    }
    return res;
}

ll binpow(ll b, ll e) {
    ll res = 1;
    while (e) {
        if (e & 1) res = res * b % mod;
        b = b * b % mod;
        e >>= 1;
    }
    return res;
}

ll t;
int m;
ll arr[maxm];

void solve() {
    cin >> t >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }
    ll G = (4 * t - 1) % mod;

    sort(arr, arr + m);
    reverse(arr, arr + m);

    mat base = {{
        {1},
        {1},
        {0},
    }};
    mat rec = {{
        {inv2, inv2, 0},
        {(mod - G) * inv2 % mod, inv2, 0},
        {1, 0, 1},
    }};

    auto recL = binpowmat(rec, arr[0] - 1);
    mat resL = mul(recL, base);

    ll res = resL[2][0] % mod;
    for (int i = 1; i < m; i++) {
        auto recm = binpowmat(rec, arr[i] - 1);
        mat resm = mul(recm, base);
        res = (res - resm[0][0] + mod) % mod;
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
