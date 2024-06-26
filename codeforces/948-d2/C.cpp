#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

namespace PollardRho {
    typedef long long ll;
    mt19937 rnd((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
    const int P = 5e6 + 10;
    bool inited = false;
    ll seq[P];
    int primes[P], spf[P];
    inline ll add_mod(ll x, ll y, ll m) { return (x += y) < m ? x : x - m; }
    inline ll mul_mod(ll x, ll y, ll m) {
        ll res = ll(__int128(x) * y % m);
        return res;
        // ll res = x * y - (ll)((long double)x * y / m + 0.5) * m;
        // return res < 0 ? res + m : res;
    }
    inline ll pow_mod(ll x, ll n, ll m) {
        ll res = 1 % m;
        for (; n; n >>= 1) {
            if (n & 1) res = mul_mod(res, x, m);
            x = mul_mod(x, x, m);
        }
        return res;
    }
    // O(it * (logn)^3), it = number of rounds performed
    inline bool miller_rabin(ll n) {
        if (n <= 2 || ((n & 1) ^ 1)) return (n == 2);
        if (n < P) return spf[n] == n;
        ll c, d, s = 0, r = n - 1;
        for (; !(r & 1); r >>= 1, s++) {
        }
        // each iteration is a round
        for (int i = 0; primes[i] < n && primes[i] < 32; i++) {
            c = pow_mod(primes[i], r, n);
            for (int j = 0; j < s; j++) {
                d = mul_mod(c, c, n);
                if (d == 1 && c != 1 && c != (n - 1)) return false;
                c = d;
            }
            if (c != 1) return false;
        }
        return true;
    }
    void init() {
        int cnt = 0;
        for (int i = 2; i < P; i++) {
            if (!spf[i]) primes[cnt++] = spf[i] = i;
            for (int j = 0, k; (k = i * primes[j]) < P; j++) {
                spf[k] = primes[j];
                if (spf[i] == spf[k]) break;
            }
        }
    }
    // returns O(n^(1/4))
    ll pollard_rho(ll n) {
        while (1) {
            ll x = rnd() % n, y = x, c = rnd() % n, u = 1, v, t = 0;
            ll *px = seq, *py = seq;
            while (1) {
                *py++ = y = add_mod(mul_mod(y, y, n), c, n);
                *py++ = y = add_mod(mul_mod(y, y, n), c, n);
                if ((x = *px++) == y) break;
                v = u;
                u = mul_mod(u, abs(y - x), n);
                if (!u) return gcd(v, n);
                if (++t == 32) {
                    t = 0;
                    if ((u = gcd(u, n)) > 1 && u < n) return u;
                }
            }
            if (t && (u = gcd(u, n)) > 1 && u < n) return u;
        }
    }
    vector<ll> factorize(ll n) {
        if (!inited) {
            inited = true;
            init();
        }
        if (n == 1) return vector<ll>();
        if (miller_rabin(n)) return vector<ll>{n};
        vector<ll> v, w;
        while (n > 1 && n < P) {
            v.push_back(spf[n]);
            n /= spf[n];
        }
        if (n >= P) {
            ll x = pollard_rho(n);
            v = factorize(x);
            w = factorize(n / x);
            v.insert(v.end(), w.begin(), w.end());
        }
        return v;
    }
}

template <typename T> vector<T> get_divs(T n) {
    vector<T> divs;
    auto factors = PollardRho::factorize(n);
    sort(begin(factors), end(factors));
    vector<pair<T, int>> v;
    for (auto x : factors) {
        if (v.empty() || v.back().first != x) {
            v.emplace_back(x, 1);
        } else {
            v.back().second += 1;
        }
    }
    function<void(int, T)> dfs = [&](int i, T cur) {
        if (i == (int)v.size()) {
            divs.push_back(cur);
            return;
        }
        T p = 1;
        for (int j = 0; j <= v[i].second; j++) {
            dfs(i + 1, cur * p);
            p *= v[i].first;
        }
    };
    dfs(0, 1);
    sort(begin(divs), end(divs));
    return divs;
}

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    map<ll, int> freq;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }

    sort(begin(a), end(a));

    auto b = a;
    b.erase(unique(begin(b), end(b)), end(b));

    int m = (int)b.size();

    const int MX = 1'000'000'000;

    // a has at most 30 distinct elements

    ll L = 1;

    for (int i = 0; i < m; i++) {
        L = lcm(L, b[i]);
        if (L > MX) break;
    }

    if (L > MX || !freq.count(L)) {
        cout << n << endl;
        return;
    }

    // l <= 1e9, e l esta no array

    int l = (int)L;

    auto d = get_divs<int>(l);

    int ans = 0;

    debug(d);

    for (int div : d) {
        L = 1;
        int pos_cnt = 0;
        for (int i = 0; i < m; i++) {
            if (div % b[i] == 0) {
                L = lcm(L, b[i]);
                pos_cnt += freq[b[i]];
            }
        }
        if (!freq.count(L)) {
            ans = max(ans, pos_cnt);
        }
    }

    cout << ans << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    ll prod = 1;
    for (int i = 1; i <= 1000; i++) {
        prod = lcm(prod, i);
        if (prod > 1'000'000'000) {
            //cout << i << endl;
            // 13 <- wrong
            // 23 :(
            break;
        }
    }
    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}