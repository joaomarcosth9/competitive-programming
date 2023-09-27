#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
typedef long long ll;

ll L[3], R[3];

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

ll inv(ll u) { return binpow(u, mod - 2); }

ll dp[41][2][2][2][2][2][2];

ll dpp(int p, int l0, int r0, int l1, int r1, int l2, int r2) {
    if (p == -1) return 1;
    if (dp[p][l0][r0][l1][r1][l2][r2] != -1) return dp[p][l0][r0][l1][r1][l2][r2];
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
            int new_l1 = l1 && (L[1] >> p & 1) == u[1];
            int new_r1 = r1 && (R[1] >> p & 1) == u[1];
            int new_l2 = l2 && (L[2] >> p & 1) == u[2];
            int new_r2 = r2 && (R[2] >> p & 1) == u[2];
            ret = (ret + dpp(p - 1, new_l0, new_r0, new_l1, new_r1, new_l2, new_r2)) % mod;
        }
    }
    return dp[p][l0][r0][l1][r1][l2][r2] = ret;
}

void solve(){
    ll p = 1;
    for (int i = 0; i < 3; i++) {
        cin >> L[i] >> R[i];
        p = p * (R[i] - L[i] + 1) % mod;
    }
    ll u = dpp(40, 1, 1, 1, 1, 1, 1);
    u = (p - u + mod) % mod;
    cout << (u * inv(p)) % mod << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(dp, -1, sizeof(dp));
    solve();
}
