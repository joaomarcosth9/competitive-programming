#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
typedef long long ll;

ll L[3], R[3], A[3];

array<int, 3> poss[] = {
    {0, 0, 0},
    {1, 0, 1},
    {0, 1, 1},
    {1, 1, 0},
};

ll binpow(ll u, ll e) {
    ll ret = 1;
    while (e) {
        if (e & 1) ret = ret * u % mod;
        u = u * u % mod;
        e >>= 1;
    }
    return ret;
}

ll mods2[3][64];

ll inv(ll u) { return binpow(u, mod - 2); }

ll dp[64][2][2][10][2][2][10][2][2][10];

ll dpp(int p, int l0, int r0, int mod0, int l1, int r1, int mod1, int l2, int r2, int mod2) {
    if (p == -1) return (mod0 == 0 && mod1 == 0 && mod2 == 0);
    if (dp[p][l0][r0][mod0][l1][r1][mod1][l2][r2][mod2] != -1) return dp[p][l0][r0][mod0][l1][r1][mod1][l2][r2][mod2];
    ll ret = 0;
    for (auto u : poss) {
        // sei que u[0] ^ u[1] == u[2];
        bool db0 = !l0 || ((L[0] >> p & 1) <= u[0]);
        db0 &= !r0 || ((R[0] >> p & 1) >= u[0]);
        bool db1 = !l1 || ((L[1] >> p & 1) <= u[1]);
        db1 &= !r1 || ((R[1] >> p & 1) >= u[1]);
        bool db2 = !l2 || ((L[2] >> p & 1) <= u[2]);
        db2 &= !r2 || ((R[2] >> p & 1) >= u[2]);
        if (db0 && db1 && db2) {
            int new_l0 = l0 && (L[0] >> p & 1) == u[0];
            int new_r0 = r0 && (R[0] >> p & 1) == u[0];
            int new_mod0 = (mod0 + mods2[0][p] * u[0]) % A[0];
            int new_l1 = l1 && (L[1] >> p & 1) == u[1];
            int new_r1 = r1 && (R[1] >> p & 1) == u[1];
            int new_mod1 = (mod1 + mods2[1][p] * u[1]) % A[1];
            int new_l2 = l2 && (L[2] >> p & 1) == u[2];
            int new_r2 = r2 && (R[2] >> p & 1) == u[2];
            int new_mod2 = (mod2 + mods2[2][p] * u[2]) % A[2];
            ret =
                (ret + dpp(p - 1, new_l0, new_r0, new_mod0, new_l1, new_r1, new_mod1, new_l2, new_r2, new_mod2)) % mod;
        }
    }
    return dp[p][l0][r0][mod0][l1][r1][mod1][l2][r2][mod2] = ret;
}

void solve() {
    ll p = 1;
    ll N;
    cin >> N;
    for (int i = 0; i < 3; i++) {
        L[i] = 1;
        R[i] = N;
        cin >> A[i];
    }
    for (int i = 0; i < 3; i++) {
        mods2[i][0] = 1;
        mods2[i][1] = 2 % A[i];
    }
    for (int i = 0; i < 3; i++) {
        int P = 4;
        for (int j = 2; j < 64; j++) {
            mods2[i][j] = P % A[i];
            P = P * 2 % A[i];
        }
    }
    ll u = dpp(63, 1, 1, 0, 1, 1, 0, 1, 1, 0);
    cout << u << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    solve();
}
