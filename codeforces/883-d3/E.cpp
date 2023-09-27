#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long ll;

ll ssqrt(__int128_t n){
    ll L = 1, R = 1e3;
    __int128_t ans = -1;
    while (L <= R) {
        __int128_t mid = (L + R) / 2;
        if(mid * mid * mid * mid * mid * mid <= n){
            ans = mid;
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    return (ll)ans + 2;
}

ll qsqrt(__int128_t n){
    ll L = 1, R = 1e5;
    __int128_t ans = -1;
    while (L <= R) {
        __int128_t mid = (L + R) / 2;
        if(mid * mid * mid * mid * mid <= n){
            ans = mid;
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    return (ll)ans + 2;
}

ll fsqrt(__int128_t n){
    ll L = 1, R = 1e5;
    __int128_t ans = -1;
    while (L <= R) {
        __int128_t mid = (L + R) / 2;
        if(mid * mid * mid * mid <= n){
            ans = mid;
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    return (ll)ans + 2;
}

ll mycbrt(ll n){
    ll L = 1, R = 1e6;
    ll ans = -1;
    while (L <= R) {
        ll mid = (L + R) / 2;
        if(mid * mid * mid <= n){
            ans = mid;
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    return ans + 2;
}

ll mysqrt(ll n){
    ll L = 1, R = 1e9;
    ll ans = -1;
    while (L <= R) {
        ll mid = (L + R) / 2;
        if(mid * mid <= n){
            ans = mid;
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    return ans + 2;
}

int mx = 380;

void solve() {
    ll N; cin >> N;
    __int128_t n = N;
    ll sq = mysqrt(n);
    ll cb = mycbrt(n);
    ll fq = fsqrt(n);
    ll qq = qsqrt(n);
    ll sxq = ssqrt(n);
    for (__int128_t i = sq; i > 1; i--) {
        __int128_t ac = 1 + i + (i * i);
        if(ac == n){
            cout << "YES" << '\n';
            return;
        }
        if(ac < n){
            break;
        }
    }
    for (__int128_t i = cb; i > 1; i--) {
        __int128_t ac = 1 + i + (i * i) + (i * i * i);
        if(ac == n){
            cout << "YES" << '\n';
            return;
        }
        if(ac < n){
            break;
        }
    }
    for (__int128_t i = fq; i > 1; i--) {
        __int128_t ac = 1 + i + (i * i) + (i * i * i) + (i * i * i * i);
        if(ac == n){
            cout << "YES" << '\n';
            return;
        }
        if(ac < n){
            break;
        }
    }
    for (__int128_t i = qq; i > 1; i--) {
        __int128_t ac = 1 + i + (i * i) + (i * i * i) + (i * i * i * i) + (i * i * i * i * i);
        if(ac == n){
            cout << "YES" << '\n';
            return;
        }
        if(ac < n){
            break;
        }
    }
    for (__int128_t i = sxq; i > 1; i--) {
        __int128_t ac = 1 + i + (i * i) + (i * i * i) + (i * i * i * i) + (i * i * i * i * i) + (i * i * i * i * i * i);
        if(ac == n){
            cout << "YES" << '\n';
            return;
        }
        if(ac < n){
            break;
        }
    }
    for (__int128_t i = 2; i <= mx; i++) {
        __int128_t ac = 1 + i;
        __int128_t pot = i * i;
        for (int it = 0; it < 60; it++) {
            ac += pot;
            pot *= i;
            if(ac == n) {
                cout << "YES" << '\n';
                return;
            }
            if(ac > n || pot > n || pot < 0) break;
        }
    }
    cout << "NO" << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if (TC) { cin >> TC;
        while (TC--) solve();
    } else solve();
    return 0;
}
