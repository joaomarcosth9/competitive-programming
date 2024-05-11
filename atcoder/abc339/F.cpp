#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

ll mul(ll a, ll b, ll m) {
    ll ret = a * b - ll((long double)1 / m * a * b + 0.5) * m;
    return ret < 0 ? ret + m : ret;
}

ll pow(ll x, ll y, ll m) {
    if (!y) return 1;
    ll ans = pow(mul(x, x, m), y / 2, m);
    return y % 2 ? mul(x, ans, m) : ans;
}

bool prime(ll n) {
    if (n < 2) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0) return 0;
    ll r = __builtin_ctzll(n - 1), d = n >> r;

    for (int a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        ll x = pow(a, d, n);
        if (x == 1 or x == n - 1 or a % n == 0) continue;

        for (int j = 0; j < r - 1; j++) {
            x = mul(x, x, n);
            if (x == n - 1) break;
        }
        if (x != n - 1) return 0;
    }
    return 1;
}

const ll M = 1e9;

vector<ll> primes;

vector<ll> mods(string num) {
    vector<ll> ret(10);
    for (int i = 0; i < 10; i++) {
        ll now = 0;
        ll b = 1;
        for (int j = int(num.size()) - 1; j >= 0; j--) {
            int c = num[j] - '0';
            now = (now + c * b) % primes[i];
            b = b * 10 % primes[i];
        }
        ret[i] = now;
    }
    return ret;
}

vector<ll> mult(vector<ll> a, vector<ll> b) {
    for (int i = 0; i < 10; i++) {
        a[i] = a[i] * b[i] % primes[i];
    }
    return a;
}

void solve() {
    int n; cin >> n;
    vector<vector<ll>> a(n);
    map<vector<ll>, ll> freq;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        a[i] = mods(s);
        freq[a[i]]++;
    }
    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            auto now = mult(a[i], a[j]);
            res += freq[now];
        }
    }
    cout << res << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = M; int(primes.size()) < 10; i++) {
        if (prime(i)) primes.push_back(i);
    }
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
