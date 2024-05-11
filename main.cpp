#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

struct node {
    array<int, 32> pref, suff, id_pref, id_suff;
    int sz_pref, sz_suff;
    ll ans;
    int l, r;
    node() : ans(-1) { }
    node(int x, int i) : sz_pref(0), sz_suff(0), ans(0), l(i), r(i) {
        pref[sz_pref] = x;
        id_pref[sz_pref] = i;
        sz_pref++;
        suff[sz_suff] = x;
        id_suff[sz_suff] = i;
        sz_suff++;
        ans = x > 1;
    }
    node(const node &L, const node &R) : sz_pref(0), sz_suff(0), ans(L.ans + R.ans), l(L.l), r(R.r) {
        if (L.ans == -1) {
            *this = R;
            return;
        }
        if (R.ans == -1) {
            *this = L;
            return;
        }
        int mid = L.r;
        int prev_r = mid;
        for (int i = L.sz_suff - 1, j = 0; j < R.sz_pref; j++) {
            while (i >= 0 && gcd(L.suff[i], R.pref[j]) == 1) {
                i--;
            }
            if (i < 0) break;
            if (gcd(L.suff[i], R.pref[j]) > 1) {
                ans += 1LL * (mid - L.id_suff[i] + 1) * (R.id_pref[j] - prev_r);
            }
            prev_r = R.id_pref[j];
        }

        int g = 0;
        for (int i = 0; i < L.sz_pref; i++) {
            id_pref[sz_pref] = L.id_pref[i];
            pref[sz_pref] = L.pref[i];
            g = gcd(g, pref[sz_pref]);
            sz_pref++;
        }
        for (int i = 0; i < R.sz_pref; i++) {
            int ng = gcd(g, R.pref[i]);
            if (ng != g) {
                g = ng;
                id_pref[sz_pref] = R.id_pref[i];
                pref[sz_pref] = g;
                sz_pref++;
            } else {
                id_pref[sz_pref - 1] = R.id_pref[i];
            }
        }

        g = 0;
        for (int i = 0; i < R.sz_suff; i++) {
            id_suff[sz_suff] = R.id_suff[i];
            suff[sz_suff] = R.suff[i];
            g = gcd(g, suff[sz_suff]);
            sz_suff++;
        }
        for (int i = 0; i < L.sz_suff; i++) {
            int ng = gcd(g, L.suff[i]);
            if (ng != g) {
                g = ng;
                id_suff[sz_suff] = L.id_suff[i];
                suff[sz_suff] = g;
                sz_suff++;
            } else {
                id_suff[sz_suff - 1] = L.id_suff[i];
            }
        }
    }
};

const int N = 1e5 + 5;

node seg[2 * N];
int n, q, a[N];

void build() {
    for (int i = 0; i < n; i++) {
        seg[i + n] = node(a[i], i);
    }
    for (int i = n - 1; i > 0; i--) {
        seg[i] = node(seg[i << 1], seg[i << 1 | 1]);
    }
}

void update(int i, int x) {
    a[i] = x;
    seg[i + n] = node(a[i], i);
    i += n;
    for (i >>= 1; i > 0; i >>= 1) {
        seg[i] = node(seg[i << 1], seg[i << 1 | 1]);
    }
}

ll query(int l, int r) {
    node ansl, ansr;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            ansl = node(ansl, seg[l++]);
        }
        if (r & 1) {
            ansr = node(seg[--r], ansr);
        }
    }
    return node(ansl, ansr).ans;
}

void solve() {
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  build();
  while (q--) {
    int t; cin >> t;
    if (t == 1) {
      int i, x; cin >> i >> x;
      i--;
      update(i, x);
    } else {
      int l, r; cin >> l >> r;
      l--; r--;
      cout << query(l, r) << endl;
    }
    continue;
  }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
