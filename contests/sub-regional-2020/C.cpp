#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long ll;
#define int ll

const int maxn = 1e5 + 5, maxa = 1e6 + 5;
const ll mod[] = {(ll)1e9 + 9, 998244353}, p = 31;
ll pot[maxa][2], invpot[maxa][2];

ll binpow(ll b, ll e) {
    ll modulo = e + 2;
    ll res = 1;
    while (e) {
        if (e & 1) res = res * b % modulo;
        b = b * b % modulo;
        e >>= 1;
    }
    return res;
}

string a[maxn], b[maxn];
vector<ll> ha[maxn][2], hb[maxn][2];
map<ll, map<int, bool>> hasA, hasB;   // strings que eu tenho no set
map<ll, map<int, bool>> diffA, diffB; // diferencas que eu tenho no set
map<ll, map<int, bool>> notA, notB;   // strings q nao sao reposta

vector<ll> queryA(int i, int l, int r) {
    l++, r++;
    assert(l <= r);
    ll q1 = (ha[i][0][r] - ha[i][0][l - 1] + mod[0]) * invpot[l - 1][0] % mod[0];
    ll q2 = (ha[i][1][r] - ha[i][1][l - 1] + mod[1]) * invpot[l - 1][1] % mod[1];
    return {q1, q2};
}

vector<ll> queryB(int i, int l, int r) {
    l++, r++;
    assert(l <= r);
    ll q1 = (hb[i][0][r] - hb[i][0][l - 1] + mod[0]) * invpot[l - 1][0] % mod[0];
    ll q2 = (hb[i][1][r] - hb[i][1][l - 1] + mod[1]) * invpot[l - 1][1] % mod[1];
    return {q1, q2};
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        reverse(begin(b[i]), end(b[i]));
    }
    for (int i = 0; i < n; i++) {
        int len = a[i].size();
        ha[i][0].resize(len + 5);
        ha[i][1].resize(len + 5);
        for (int j = 0; j < len; j++) {
            ha[i][0][j + 1] = (ha[i][0][j] + (1ll * (a[i][j] - 'a' + 1) * pot[j + 1][0] % mod[0]) + mod[0]) % mod[0];
            ha[i][1][j + 1] = (ha[i][1][j] + (1ll * (a[i][j] - 'a' + 1) * pot[j + 1][1] % mod[1]) + mod[1]) % mod[1];
        }
    }
    for (int i = 0; i < m; i++) {
        int len = b[i].size();
        hb[i][0].resize(len + 5);
        hb[i][1].resize(len + 5);
        for (int j = 0; j < len; j++) {
            hb[i][0][j + 1] = (hb[i][0][j] + (1ll * (b[i][j] - 'a' + 1) * pot[j + 1][0] % mod[0]) + mod[0]) % mod[0];
            hb[i][1][j + 1] = (hb[i][1][j] + (1ll * (b[i][j] - 'a' + 1) * pot[j + 1][1] % mod[1]) + mod[1]) % mod[1];
        }
    }
    for (int i = 0; i < n; i++) {
        int len = a[i].size();
        auto H = queryA(i, 0, len - 1);
        debug(H);
        hasA[H[0]][0] = 1;
        hasA[H[1]][1] = 1;
    }
    for (int i = 0; i < m; i++) {
        int len = b[i].size();
        auto H = queryB(i, 0, len - 1);
        debug("B", b[i], H);
        hasB[H[0]][0] = 1;
        hasB[H[1]][1] = 1;
    }
    for (int i = 0; i < n; i++) {
        int len = a[i].size();
        for (int r = 0; r < len - 1; r++) {
            auto pref = queryA(i, 0, r);
            auto suff = queryA(i, r + 1, len - 1);
            if (hasA[pref[0]][0] && hasA[pref[1]][1]) {
                diffA[suff[0]][0] = 1;
                diffA[suff[1]][1] = 1;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int len = b[i].size();
        for (int r = 0; r < len - 1; r++) {
            auto pref = queryB(i, 0, r);
            auto suff = queryB(i, r + 1, len - 1);
            if (hasB[pref[0]][0] && hasB[pref[1]][1]) {
                diffB[suff[0]][0] = 1;
                diffB[suff[1]][1] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int len = a[i].size();
        auto me = queryA(i, 0, len - 1);
        for (int r = 0; r < len - 1; r++) {
            auto pref = queryA(i, 0, r);
            debug(pref);
            auto suff = queryA(i, r + 1, len - 1);
            debug(suff);
            debug(hasA[pref[0]][0], hasA[pref[1]][1]);
            debug(diffB[suff[0]][0], diffB[suff[1]][1]);
            if (hasA[pref[0]][0] && hasA[pref[1]][1] && diffB[suff[0]][0] && diffB[suff[1]][1]) {
                notA[me[0]][0] = 1;
                notA[me[1]][1] = 1;
                notA[pref[0]][0] = 1;
                notA[pref[1]][1] = 1;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int len = b[i].size();
        auto me = queryB(i, 0, len - 1);
        for (int r = 0; r < len - 1; r++) {
            auto pref = queryB(i, 0, r);
            auto suff = queryB(i, r + 1, len - 1);
            if (hasB[pref[0]][0] && hasB[pref[1]][1] && diffA[suff[0]][0] && diffA[suff[1]][1]) {
                notB[me[0]][0] = 1;
                notB[me[1]][1] = 1;
                notB[pref[0]][0] = 1;
                notB[pref[1]][1] = 1;
            }
        }
    }
    int resA = n, resB = m;
    for (int i = 0; i < n; i++) {
        int len = a[i].size();
        auto me = queryA(i, 0, len - 1);
        debug(me);
        resA -= (notA[me[0]][0] && notA[me[1]][1]);
    }
    for (int i = 0; i < m; i++) {
        int len = b[i].size();
        auto me = queryB(i, 0, len - 1);
        debug(me);
        resB -= (notB[me[0]][0] && notB[me[1]][1]);
    }
    cout << resA << " " << resB << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pot[0][0] = pot[0][1] = 1;
    pot[1][0] = pot[1][1] = p;
    debug(mod[0], mod[1]);
    invpot[0][0] = invpot[0][1] = 1;
    invpot[1][0] = binpow(p, mod[0] - 2);
    invpot[1][1] = binpow(p, mod[1] - 2);
    for (int i = 2; i < maxa; i++) {
        pot[i][0] = pot[i - 1][0] * pot[1][0] % mod[0];
        pot[i][1] = pot[i - 1][1] * pot[1][1] % mod[1];
        invpot[i][0] = invpot[i - 1][0] * invpot[1][0] % mod[0];
        invpot[i][1] = invpot[i - 1][1] * invpot[1][1] % mod[1];
    }
    debug(pot[10][0], pot[10][1]);
    solve();
    return 0;
}
