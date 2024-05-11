#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <int mod> struct Mint {
    using m = Mint;
    int val;
    Mint() : val(0) { }
    Mint(ll v) {
        if (v < -mod || v >= 2 * mod) {
            v %= mod;
        }
        if (v >= mod) {
            v -= mod;
        }
        if (v < 0) {
            v += mod;
        }
        val = int(v);
    }
    bool operator==(const m& o) const { 
        return val == o.val;
    }
    m pwr(m b, ll e) {
        m res = 1;
        while (e) {
            if (e & 1)
                res *= b;
            b *= b, e >>= 1;
        }
        return res;
    }
    m &operator+=(const m &o) {
        if ((val += o.val) >= mod) {
            val -= mod;
        }
        return *this;
    }
    m &operator-=(const m &o) {
        if ((val -= o.val) < 0) {
            val += mod;
        }
        return *this;
    }
    m &operator*=(const m &o) {
        val = int((ll)val * o.val % mod);
        return *this;
    }
    m &operator/=(const m &o) { return *this *= pwr(o, mod - 2); }
    m &operator^=(ll e) {
        assert(e >= 0);
        return *this = pwr(*this, e);
    }
    friend m operator+(m a, const m &b) { return a += b; }
    friend m operator-(m a, const m &b) { return a -= b; }
    friend m operator*(m a, const m &b) { return a *= b; }
    friend m operator/(m a, const m &b) { return a /= b; }
    friend m operator^(m a, ll e) { return a ^= e; }
    friend ostream &operator<<(ostream &os, const m &a) { return os << a.val; }
    friend istream &operator>>(istream &is, m &a) {
        ll x;
        is >> x, a = m(x);
        return is;
    }
    friend string to_string(const m& o) {
        return to_string(o.val); 
    }
};

const int MOD = 998244353;
using Hash = Mint<MOD>;

const int ORD = 2e6;
mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());
const int PRIME = ORD + (rng() % ORD); // nao necessariamente primo

const int MAXN = ORD;

Hash P = PRIME;
Hash invP = Hash(1) / PRIME;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'

Hash p[MAXN], invp[MAXN];

void initPrime() {
    p[0] = invp[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        p[i] = p[i - 1] * P;
        invp[i] = invp[i - 1] * invP;
    }
}

template<typename obj = string> struct Hashing {
    int N;
    vector<Hash> hsh;
    Hashing () {}
    Hashing(obj s) : N((int)size(s)), hsh(N + 1) {
        for (int i = 0; i < N; i++) {
            hsh[i + 1] = hsh[i] + (p[i + 1] * Hash(s[i] - 'a' + 1));
        }
    }
    Hash operator()(int l, int r) const {
        if (l > r) return 0;
        return (hsh[r + 1] - hsh[l]) * invp[l];
    }
};

const int N = 3005;
string a[N][N], res[N];
Hashing<string> h[N][N];
int n, sz[N][N], mn;
pair<int, int> who;

void solve() {
    cin >> n;
    
    mn = -1, who = {-1, -1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            h[i][j] = Hashing<string>(a[i][j]);
            sz[i][j] = (int)a[i][j].size();
            if (sz[i][j] > mn) {
                mn = sz[i][j];
                who = {i, j};
            }
        }
    }

    int id = who.first;
    int db = 0;

    for (int l = 0; l < sz[who.first][who.second] - 1; l++) {

        bool now = 1;
        vector<Hash> vh(n);
        vector<int> len(n);

        vh[id] = h[id][who.second](0, l);
        len[id] = l + 1;

        for (int j = 0; j < n; j++) if (j != id) {
            int L = l + 1, R = sz[id][j] - 1;
            vh[j] = h[id][j](L, R);
            len[j] = sz[id][j] - len[id];
            now &= len[j] > 0;
        }
        if (not now) continue;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) if (i != j) {
                auto has = vh[i] + (vh[j] * p[len[i]]);
                now &= has == h[i][j](0, sz[i][j] - 1);
            }
        }

        if (now && db == 0) {
            res[id] = a[id][who.second].substr(0, len[id]);
            for (int j = 0; j < n; j++) if (j != id) {
                res[j] = a[id][j].substr(len[id]);
            }
            db = 1;
        } else if (now && db > 0) {
            db = 2;
            break;
        }
    }

    if (db == 0) {
        cout << "NONE" << endl;
    } else if (db == 1) {
        cout << "UNIQUE" << endl;
        for (int i = 0; i < n; i++) {
            cout << res[i] << endl;
        }
    } else {
        cout << "MANY" << endl;
    }

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 0;
    initPrime();
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
