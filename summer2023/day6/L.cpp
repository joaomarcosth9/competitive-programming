#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

struct node {
    int o = 0, c = 0, res = 0;
    node() {}
    node(char p) : o(0), c(0), res(0) {
        if (p == ')') c++;
        if (p == '(') o++;
    }
    node(node &l, node &r) : o(r.o), c(l.c) {
        res += r.res + l.res;
        res += 2 * min(l.o, r.c);
        if (l.o > r.c) {
            o += (l.o - r.c);
        } else {
            c += (r.c - l.o);
        }
    }
};

vector<node> t;

void solve() {
    string p;
    cin >> p;
    int n = p.size();
    t.assign(2 * n, node());
    for (int i = 0; i < n; i++) {
        t[i + n] = node(p[i]);
    }
    for (int i = n - 1; i; i--) {
        t[i] = node(t[i << 1], t[i << 1 | 1]);
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        node resl, resr, res;
        for (l += n - 1, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resl = node(resl, t[l++]);
            if (r & 1) resr = node(t[--r], resr);
        }
        res = node(resl, resr);
        cout << res.res << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
