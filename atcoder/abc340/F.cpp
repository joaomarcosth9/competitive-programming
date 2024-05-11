#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = __int128;

template <typename T> tuple<ll, T, T> ext_gcd(ll a, ll b) {
    if (!a) return {b, 0, 1};
    auto [g, x, y] = ext_gcd<T>(b % a, a);
    return {g, y - b / a * x, x};
}

ll abs2(ll x) {
    return x >= 0 ? x : -x;
}

// numero de solucoes de a*[lx, rx] + b*[ly, ry] = c
template <typename T = ll> // usar __int128 se for ate 1e18
pair<ll, ll> diophantine(ll a, ll b, ll c, ll lx, ll rx, ll ly, ll ry) {
    if (lx > rx or ly > ry) return make_pair(0, 0);
    auto [g, x, y] = ext_gcd<T>(abs2(a), abs2(b));
    if (c % g != 0) return make_pair(0, 0);
    x *= a / abs2(a) * c / g, y *= b / abs2(b) * c / g, a /= g, b /= g;

    auto shift = [&](T qt) { x += qt * b, y -= qt * a; };
    auto test = [&](T &k, ll mi, ll ma, ll coef, int t) {
        shift((mi - k) * t / coef);
        if (k < mi) shift(coef > 0 ? t : -t);
        if (k > ma) return pair<T, T>(rx + 2, rx + 1);
        T x1 = x;
        shift((ma - k) * t / coef);
        if (k > ma) shift(coef > 0 ? -t : t);
        return pair<T, T>(x1, x);
    };

    auto [l1, r1] = test(x, lx, rx, b, 1);
    auto [l2, r2] = test(y, ly, ry, a, -1);
    if (l2 > r2) swap(l2, r2);
    T l = max(l1, l2), r = min(r1, r2);
    if (l > r) return make_pair(0, 0);
    ll k = (r - l) / abs2(b) + 1;
    //return k; // solucoes: x = l + [0, k)*|b|
    return make_pair(k, l);
}

void solve() {
    long long x, y; cin >> x >> y;
    if (x == 0) {
        if (y <= 2) {
            cout << 2 / y << " " << 10 << endl;
        } else {
            cout << -1 << endl;
        }
        return;
    }
    if (y == 0) {
        if (x <= 2) {
            cout << 10 << " " << 2 / x << endl;
        } else {
            cout << -1 << endl;
        }
        return;
    }
    const ll INF = 1e18;
    auto [has, b] = diophantine(x, y, 2, -INF, INF, -INF, INF);
    if (!has) {
        cout << -1 << endl;
        return;
    }
    ll a = ((x * b) - 2) / y;
    if (a < -INF || a > INF) {
        cout << -1 << endl;
        return;
    }
    cout << (long long)a << " " << (long long)b << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
