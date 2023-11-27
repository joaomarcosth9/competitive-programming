#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif
#define endl '\n'
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto& x){ return res; }
#define L2(res...) [&](const auto& x, const auto& y){ return res; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

// Aritmetica Modular
//
// O mod tem q ser primo

template <int p> struct mod_int {
    ll expo(ll b, ll e) {
        ll ret = 1;
        while (e) {
            if (e % 2) ret = ret * b % p;
            e /= 2, b = b * b % p;
        }
        return ret;
    }
    ll inv(ll b) { return expo(b, p - 2); }

    using m = mod_int;
    int v;
    mod_int() : v(0) {}
    mod_int(ll v_) {
        if (v_ >= p or v_ <= -p) v_ %= p;
        if (v_ < 0) v_ += p;
        v = v_;
    }
    m &operator+=(const m &a) {
        v += a.v;
        if (v >= p) v -= p;
        return *this;
    }
    m &operator-=(const m &a) {
        v -= a.v;
        if (v < 0) v += p;
        return *this;
    }
    m &operator*=(const m &a) {
        v = v * ll(a.v) % p;
        return *this;
    }
    m &operator/=(const m &a) {
        v = v * inv(a.v) % p;
        return *this;
    }
    m operator-() { return m(-v); }
    m &operator^=(ll e) {
        if (e < 0) {
            v = inv(v);
            e = -e;
        }
        v = expo(v, e % (p - 1));
        return *this;
    }
    bool operator==(const m &a) { return v == a.v; }
    bool operator!=(const m &a) { return v != a.v; }

    friend istream &operator>>(istream &in, m &a) {
        ll val;
        in >> val;
        a = m(val);
        return in;
    }
    friend ostream &operator<<(ostream &out, m a) { return out << a.v; }
    friend m operator+(m a, m b) { return a += b; }
    friend m operator-(m a, m b) { return a -= b; }
    friend m operator*(m a, m b) { return a *= b; }
    friend m operator/(m a, m b) { return a /= b; }
    friend m operator^(m a, ll e) { return a ^= e; }
};

// NTT
//
// Precisa do mint (primitivas de aritmetica modular)
//
// O(n log (n))

const int MOD = 998244353;
typedef mod_int<MOD> mint;

void ntt(vector<mint> &a, bool rev) {
    int n = a.size();
    auto b = a;
    assert(!(n & (n - 1)));
    mint g = 1;
    while ((g ^ ((MOD - 1) / 2)) == mint(1)) g += 1;
    if (rev) g = 1 / g;

    for (int step = n / 2; step; step /= 2) {
        mint w = g ^ ((MOD - 1) / (n / step)), wn = 1;
        for (int i = 0; i < n / 2; i += step) {
            for (int j = 0; j < step; j++) {
                auto u = a[2 * i + j], v = wn * a[2 * i + j + step];
                b[i + j] = u + v;
                b[i + n / 2 + j] = u - v;
            }
            wn = wn * w;
        }
        swap(a, b);
    }
    if (rev) {
        auto n1 = mint(1) / n;
        for (auto &x : a) x *= n1;
    }
}

vector<ll> convolution(vector<ll> &a, vector<ll> &b) {
    vector<mint> l(a.begin(), a.end()), r(b.begin(), b.end());
    int N = l.size() + r.size() - 1, n = 1;
    while (n <= N) n *= 2;
    l.resize(n);
    r.resize(n);
    ntt(l, false);
    ntt(r, false);
    for (int i = 0; i < n; i++) l[i] *= r[i];
    ntt(l, true);
    l.resize(N);
    vector<ll> ret(l.size());
    for (int i = 0; i < N; i++) ret[i] = l[i].v;
    return ret;
}

const int maxn = 1e5 + 10;
const int mod = 998244353;
int n, k;
vector<ll> t, p, res;
vector<ll> A, B, K;
ll fat[maxn], invfat[maxn], pk[maxn];

ll binpow(ll b, ll e) {
    ll ret = 1;
    while (e) {
        if (e & 1) ret = ret * b % mod;
        b = b * b % mod;
        e >>= 1;
    }
    return ret;
}

void compute() {
    pk[0] = fat[0] = 1;
    for (int i = 1; i < maxn; i++) pk[i] = pk[i - 1] * k % mod;
    for (int i = 1; i < maxn; i++) fat[i] = fat[i - 1] * i % mod;
    invfat[maxn - 1] = binpow(fat[maxn - 1], mod - 2);
    for (int i = maxn - 2; i >= 0; i--) invfat[i] = invfat[i + 1] * (i + 1) % mod;
}

void solve() {
    cin >> n >> k;
    n++;

    compute();

    t.resize(n); p.resize(n);
    res.resize(n); A.resize(n); B.resize(n);
    K.resize(n);

    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 0; i < n; i++) t[i] = t[i] * fat[i] % mod;
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) p[i] = p[i] * fat[i] % mod;

    reverse(all(t));
    reverse(all(p));
    
    for (int i = 0; i < n; i++) {
        K[i] = pk[i] * invfat[i] % mod;
    }

    A = convolution(t, K);
    while ((int)A.size() > n) A.pop_back();

    reverse(all(A));

    debug(A);

    for (int i = 0; i < n; i++) A[i] = A[i] * invfat[i] % mod;

    for (int i = 0; i < n; i++) if (i & 1) K[i] = -K[i];

    B = convolution(p, K);
    while ((int)B.size() > n) B.pop_back();

    reverse(all(B));

    for (int i = 0; i < n; i++) B[i] = B[i] * invfat[i] % mod;

    debug(B);

    for (int i = 0; i < n; i++) res[i] = (A[i] + B[i] + mod) % mod;

    for (auto u : res) cout << u << " ";
    cout << endl;

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
