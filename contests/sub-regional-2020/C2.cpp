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
const ll mod[] = {1000000009, 998244353}, p = 101;
ll pot[2][maxa], invpot[2][maxa];

ll binpow(ll b, ll e){
    ll modulo = e + 2;
    ll res = 1;
    while (e) {
        if(e & 1) res = res * b % modulo;
        b = b * b % modulo;
        e >>= 1;
    }
    return res;
}

string a[maxn], b[maxn];
vector<ll> ha[2][maxn], hb[2][maxn];
unordered_map<ll, bool> hasA[2], hasB[2]; // strings que eu tenho no set
unordered_map<ll, bool> diffA[2], diffB[2]; // diferencas que eu tenho no set
unordered_map<ll, bool> notA[2], notB[2]; // strings q nao sao reposta
vector<pair<vector<ll>, vector<ll>>> queriesA[maxn], queriesB[maxn];

vector<ll> queryA(int i, int l, int r) {
    l++, r++;
    vector<ll> ret(2);
    for (int k = 0; k < 2; k++) {
        ret[k] = (ha[k][i][r] - ha[k][i][l - 1] + mod[k]) * invpot[k][l - 1] % mod[k];
    }
    return ret;
}

vector<ll> queryB(int i, int l, int r) {
    l++, r++;
    vector<ll> ret(2);
    for (int k = 0; k < 2; k++) {
        ret[k] = (hb[k][i][r] - hb[k][i][l - 1] + mod[k]) * invpot[k][l - 1] % mod[k];
    }
    return ret;
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        int len = a[i].size();
        for (int k = 0; k < 2; k++) {
            ha[k][i].resize(len + 5);
            for (int j = 0; j < len; j++) {
                ha[k][i][j + 1] = (ha[k][i][j] + (1ll * (a[i][j] - 'a' + 1) * pot[k][j + 1] % mod[k]) + mod[k]) % mod[k];
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int len = b[i].size();
        for (int k = 0; k < 2; k++) {
            hb[k][i].resize(len + 5);
            for (int j = 0; j < len; j++) {
                hb[k][i][j + 1] = (hb[k][i][j] + (1ll * (b[i][j] - 'a' + 1) * pot[k][j + 1] % mod[k]) + mod[k]) % mod[k];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int len = a[i].size();
        auto H = queryA(i, 0, len - 1);
        for (int k = 0; k < 2; k++) hasA[k][H[k]] = 1;
    }
    for (int i = 0; i < m; i++) {
        int len = b[i].size();
        auto H = queryB(i, 0, len - 1);
        for (int k = 0; k < 2; k++) hasB[k][H[k]] = 1;
    }
    for (int i = 0; i < n; i++) {
        int len = a[i].size();
        for (int r = 0; r < len - 1; r++) {
            auto pref = queryA(i, 0, r);
            auto suff = queryA(i, r + 1, len - 1);
            queriesA[i].emplace_back(pref, suff);
            bool db = 1;
            for (int k = 0; k < 2; k++) db &= hasA[k].count(pref[k]);
            if (db) {
                for (int k = 0; k < 2; k++) diffA[k][suff[k]] = 1;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int len = b[i].size();
        vector<ll> me {hb[0][i][len], hb[1][i][len]};
        for (int l = len - 1; l > 0; l--) {
            auto pref = queryB(i, l, len - 1);
            auto suff = queryB(i, 0, l - 1);
            bool db = 1;
            for (int k = 0; k < 2; k++) db &= hasB[k].count(pref[k]);
            if (db) {
                for (int k = 0; k < 2; k++) diffB[k][suff[k]] = 1;
                for (int k = 0; k < 2; k++) db &= diffA[k].count(suff[k]);
                if(db) for (int k = 0; k < 2; k++) notB[k][me[k]] = notB[k][pref[k]] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int len = a[i].size();
        vector<ll> me {ha[0][i][len], ha[1][i][len]};
        for (int r = 0, it = 0; r < len - 1; r++, it++) {
            auto &[pref, suff] = queriesA[i][it];
            bool db = 1;
            for (int k = 0; k < 2; k++) db &= hasA[k].count(pref[k]) && diffB[k].count(suff[k]);
            if (db) {
                for (int k = 0; k < 2; k++) notA[k][me[k]] = notA[k][pref[k]] = 1;
            }
        }
    }
    int resA = n, resB = m;
    for (int i = 0; i < n; i++) {
        int len = a[i].size();
        vector<ll> me {ha[0][i][len], ha[1][i][len]};
        resA -= (notA[0].count(me[0]) && notA[1].count(me[1]));
    }
    for (int i = 0; i < m; i++) {
        int len = b[i].size();
        vector<ll> me {hb[0][i][len], hb[1][i][len]};
        resB -= (notB[0].count(me[0]) && notB[1].count(me[1]));
    }
    cout << resA << " " << resB << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int k = 0; k < 2; k++){
        pot[k][0] = 1;
        pot[k][1] = p;
        invpot[k][0] = 1;
        invpot[k][1] = binpow(p, mod[k] - 2);
        for (int i = 2; i < maxa; i++) {
            pot[k][i] = pot[k][i - 1] * pot[k][1] % mod[k];
            invpot[k][i] = invpot[k][i - 1] * invpot[k][1] % mod[k];
        }
    }
    solve();
    return 0;
}
