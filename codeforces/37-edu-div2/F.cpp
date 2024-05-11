#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 3e5 + 5, NUM = 1e6 + 5;
int n, q, a[N];
set<int> id;
int sieve[NUM], divi[NUM], divs[NUM];

ll seg[2 * N];

void update(int i, int x) {
    a[i] = x;
    seg[i += n] = (ll)x;
    for (i >>= 1; i > 0; i >>= 1) {
        seg[i] = seg[i << 1] + seg[i << 1 | 1];
    }
}

ll query(int l, int r) {
    ll ans = 0;
    for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
        if (l % 2 == 1) ans += seg[l++];
        if (r % 2 == 0) ans += seg[r--];
    }
    return ans;
}

vector<int> factorize(int x) {
    vector<int> ans;
    while (x > 1) {
        ans.push_back(divi[x]);
        x /= divi[x];
    }
    return ans;
}

void solve() {
    cin >> n >> q;

    for (int i = 3; i < NUM; i++) {
        map<int, int> f;
        for (auto x : factorize(i)) {
            f[x]++;
        }
        int ans = 1;
        for (auto [k, v] : f) {
            ans *= (v + 1);
        }
        divs[i] = ans;
    }
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > 2) {
            id.insert(i);
        }
        update(i, a[i]);
    }

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int l, r; cin >> l >> r;
            l--; r--;
            auto bg = id.lower_bound(l);
            while (bg != id.end() && *bg <= r) {
                update(*bg, divs[a[*bg]]);
                bool erase = a[*bg] == 1 || a[*bg] == 2;
                bg++;
                if (erase) {
                    auto pre = bg;
                    id.erase(--pre);
                }
            }
        } else {
            int l, r; cin >> l >> r;
            l--; r--;
            cout << query(l, r) << endl;
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 2; i < NUM; i++) {
        if (sieve[i]) continue;
        for (int j = i; j < NUM; j += i) {
            sieve[j] = 1;
            if (divi[j] == 0) divi[j] = i;
        }
    }

    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
