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

const int maxn = 1e5 + 10;
const int mod = 998244353;
int n, k;
vector<ll> t, p, res;
vector<ll> A, B;
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

    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 0; i < n; i++) cin >> p[i];


    for (int i = 0; i < n; i++) {
        // [i]A(x)*i! = sum( [j]t(x) * (k ^ (j - i) / (j - i)!);
        for (int j = i; j < n; j++) {
            A[i] += (t[j] * fat[j] % mod) * (pk[j - i] * invfat[j - i] % mod);
            A[i] %= mod;
        }
    }

    debug(A);

    for (int i = 0; i < n; i++) A[i] = A[i] * invfat[i] % mod;

    debug(A);

    for (int i = 0; i < n; i++) {
        // [i]A(x)*i! = sum( [j]t(x) * (k ^ (j - i) / (j - i)!);
        for (int j = i; j < n; j++) {
            B[i] += (p[j] * fat[j] % mod) * (pk[j - i] * invfat[j - i] % mod) * ((j - i) % 2 ? -1 : 1);
            B[i] %= mod;
        }
    }

    debug(B);

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
