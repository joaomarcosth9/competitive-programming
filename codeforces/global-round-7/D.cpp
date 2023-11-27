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

const int maxn = 1e6 + 5;
typedef __int128_t LL;
const ll mod = (ll)1e18 + 9;
LL p = 101;
LL pw[maxn], invpw[maxn];
LL binpow(LL a, LL b) {
    LL res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

typedef ll Hash;
template <typename obj = string, typename T = ll, typename U = __int128_t> struct Hashing {
    int N;
    bool inverse = 0;
    vector<U> hsh;
    void build(obj s, bool _inverse = 0) {
        inverse = _inverse;
        if (inverse) reverse(begin(s), end(s));
        N = size(s);
        hsh.assign(N, s[0] % mod);
        for (int i = 1; i < N; i++) {
            hsh[i] = (hsh[i - 1] + pw[i] * s[i]) % mod;
        }
    }
    Hash operator()(int l, int r) {
        if (l > r) return 0;
        if (inverse) {
            l = N - 1 - l, r = N - 1 - r;
            swap(l, r);
        }
        Hash ans = hsh[r];
        if (l > 0) {
            ans = (ans - hsh[l - 1] + mod) % mod;
            ans = (ans * invpw[l]) % mod;
        }
        return ans;
    }
    Hash combine(Hash h1, Hash h2, int len1) {
        h1 = ((U)h1 + ((U)h2 * pw[len1] % mod)) % mod;
        return h1;
    }
};

string solve(string s) {
    int n = size(s);
    Hashing<string> h, rh;
    int it = 0, it2 = n - 1;
    while (s[it] == s[it2] && it < it2) it++, it2--;
    if (it >= it2) return s;
    string t;
    for (int i = it; i <= it2; i++) t += s[i];
    n = size(t);
    h.build(t);
    rh.build(t, 1);
    int bestp = 0;
    for (int i = 0; i < n; i++) {
        Hash h1 = h(0, i), h2 = rh(0, i);
        if (h1 == h2) {
            bestp = i;
        }
    }
    int bests = 0;
    for (int i = 0; i < n; i++) {
        Hash h1 = h(n - 1 - i, n - 1), h2 = rh(n - 1 - i, n - 1);
        if (h1 == h2) {
            bests = i;
        }
    }
    string res = s.substr(0, it);
    if (bestp >= bests) {
        res += t.substr(0, bestp + 1);
    } else {
        res += t.substr(n - 1 - bests);
    }
    res += s.substr(it2 + 1);
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    pw[0] = 1;
    for (int i = 1; i < maxn; i++) pw[i] = (pw[i - 1] * p) % mod;
    invpw[0] = 1;
    invpw[1] = binpow(p, mod - 2);
    for (int i = 1; i < maxn; i++) invpw[i] = (invpw[i - 1] * invpw[1]) % mod;

    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        /* solve(); */
        string s; cin >> s;
        cout << solve(s) << endl;
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
