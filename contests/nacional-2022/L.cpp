#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long ll;
const int maxn = 2e5 + 5, mod = 1e9 + 7;

ll binpow(ll u, ll e) {
    ll res = 1;
    while (e) {
        if (e & 1) res = res * u % mod;
        u = u * u % mod;
        e >>= 1;
    }
    return res;
}

ll P = 91;

ll p[maxn], invp[maxn], h[maxn];

ll query(int l, int r) {
    l++, r++;
    assert(r < maxn);
    ll ans = (h[r] - h[l - 1] + mod) * invp[l - 1] % mod;
    return ans;
}

void solve() {
    string s;
    cin >> s;
    for (auto &c : s) c = c - 'a' + 1;
    int d;
    cin >> d;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] + (s[i] * p[i + 1] % mod) + mod) % mod;
    }
    int res = 0;
    for (int i = 0; i < n;) {
        int BEST = -1;
        debug(i);
        for (int u = 1; u <= d && i + u - 1 < n; u++) {
            ll val = query(i, i + u - 1);
            int MAX = i + u - 1;
            debug("----------------------------------");
            debug(u);
            debug(val);
            int j;
            for (j = i + u; (j + u - 1) < n; j += u) {
                if (query(j, j + u - 1) != val) break;
                MAX = max(MAX, j + u - 1);
            }
            // ja sei que de [i, j - 1] eh igual
            int L = j, R = min(j + u - 1, n - 1);
            int LB = j;
            while (L < n && L <= R) {
                int mid = (L + R) / 2;
                debug(L, R, mid);
                debug(LB, mid, i, i + (mid - LB));
                if (query(LB, mid) == query(i, i + (mid - LB))) {
                    L = mid + 1;
                    MAX = max(MAX, mid);
                } else {
                    R = mid - 1;
                }
            }
            debug(i, u, MAX);
            BEST = max(BEST, MAX);
        }
        i = BEST + 1;
        debug(BEST + 1);
        res++;
    }
    cout << res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    p[0] = invp[0] = 1;
    p[1] = P;
    invp[1] = binpow(P, mod - 2);
    for (int i = 2; i < maxn; i++) {
        p[i] = p[i - 1] * p[1] % mod;
        invp[i] = invp[i - 1] * invp[1] % mod;
    }
    solve();
}
