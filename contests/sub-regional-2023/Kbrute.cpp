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

typedef long long ll;
typedef vector<ll> poly;

ll mod[3] = {998244353LL, 1004535809LL, 1092616193LL};
ll root[3] = {102292LL, 12289LL, 23747LL};
ll root_1[3] = {116744195LL, 313564925LL, 642907570LL};
ll root_pw[3] = {1LL << 23, 1LL << 21, 1LL << 21};

ll modInv(ll b, ll m) {
    ll e = m - 2;
    ll res = 1;
    while (e) {
        if (e & 1) res = (res * b) % m;
        e /= 2;
        b = (b * b) % m;
    }
    return res;
}

void ntt(poly &a, bool invert, int id) {
    ll n = (ll)a.size(), m = mod[id];
    for (ll i = 1, j = 0; i < n; ++i) {
        ll bit = n >> 1;
        for (; j >= bit; bit >>= 1) j -= bit;
        j += bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (ll len = 2, wlen; len <= n; len <<= 1) {
        wlen = invert ? root_1[id] : root[id];
        for (ll i = len; i < root_pw[id]; i <<= 1) wlen = (wlen * wlen) % m;
        for (ll i = 0; i < n; i += len) {
            ll w = 1;
            for (ll j = 0; j < len / 2; j++) {
                ll u = a[i + j], v = (a[i + j + len / 2] * w) % m;
                a[i + j] = (u + v) % m;
                a[i + j + len / 2] = (u - v + m) % m;
                w = (w * wlen) % m;
            }
        }
    }
    if (invert) {
        ll inv = modInv(n, m);
        for (ll i = 0; i < n; i++) a[i] = (a[i] * inv) % m;
    }
}

poly convolution(poly a, poly b, int id = 0) {
    ll n = 1LL, len = (1LL + a.size() + b.size());
    while (n < len) n *= 2;
    a.resize(n);
    b.resize(n);
    ntt(a, 0, id);
    ntt(b, 0, id);
    poly answer(n);
    for (ll i = 0; i < n; i++) answer[i] = (a[i] * b[i]);
    ntt(answer, 1, id);
    return answer;
}

const int maxn = 1e5 + 10;
int n, k;
vector<ll> t, p, res;
vector<ll> A, B, K;
ll fat[maxn], invfat[maxn], pk[maxn];

ll binpow(ll b, ll e) {
    ll ret = 1;
    while (e) {
        if (e & 1) ret = ret * b % mod[0];
        b = b * b % mod[0];
        e >>= 1;
    }
    return ret;
}

void compute() {
    pk[0] = fat[0] = 1;
    for (int i = 1; i < maxn; i++) pk[i] = pk[i - 1] * k % mod[0];
    for (int i = 1; i < maxn; i++) fat[i] = fat[i - 1] * i % mod[0];
    invfat[maxn - 1] = binpow(fat[maxn - 1], mod[0] - 2);
    for (int i = maxn - 2; i >= 0; i--) invfat[i] = invfat[i + 1] * (i + 1) % mod[0];
}

void solve() {
    cin >> n >> k;
    n++;

    compute();

    t.resize(n); p.resize(n);
    res.resize(n); A.resize(n); B.resize(n);
    K.resize(n);

    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 0; i < n; i++) t[i] = t[i] * fat[i] % mod[0];
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) p[i] = p[i] * fat[i] % mod[0];

    reverse(all(t));
    reverse(all(p));
    
    for (int i = 0; i < n; i++) {
        K[i] = pk[i] * invfat[i] % mod[0];
    }

    A = convolution(t, K);
    while ((int)A.size() > n) A.pop_back();

    reverse(all(A));

    debug(A);

    for (int i = 0; i < n; i++) A[i] = A[i] * invfat[i] % mod[0];

    for (int i = 0; i < n; i++) if (i & 1) K[i] = -K[i];

    B = convolution(p, K);
    while ((int)B.size() > n) B.pop_back();

    reverse(all(B));

    for (int i = 0; i < n; i++) B[i] = B[i] * invfat[i] % mod[0];

    debug(B);

    for (int i = 0; i < n; i++) res[i] = (A[i] + B[i] + mod[0]) % mod[0];

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
