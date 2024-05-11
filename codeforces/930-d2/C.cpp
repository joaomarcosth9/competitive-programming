#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

pair<int, int> best(int n) {
    int f = n - 1;
    int best = n - 1;
    int who = 0;
    for (int j = 1; j < n; j++) {
        if ((f ^ j) > best) {
            best = f ^ j;
            who = j;
        }
    }
    return {f, who};
}

int op = 0;
int n;

vector<int> p;

int gtr(int i, int j) {
    op++;
    assert(op <= 3 * n);
    cout << "? " << i << " " << i << " " << j << " " << j << endl;
    /* assert(j < n && i < n); */
    /* return p[i] > p[j]; */
    char r; cin >> r;
    return r == '>';
}

int comp(int i, int j, int idn) {
    op++;
    assert(op <= 3 * n);
    cout << "? " << idn << " " << i << " " << idn << " " << j << endl;
    /* int R = (p[j] | (n - 1)), L = (p[i] | (n - 1)); */
    /* if (L == R) { */
    /*     return 0; */
    /* } */
    /* if (L > R) { */
    /*     return -1; */
    /* } */
    /* return 1; */
    char r; cin >> r;
    if (r == '=') return 0;
    if (r == '>') return -1;
    return 1;
}

void solve() {
    cin >> n;
    /* p.assign(n, 0); */
    /* iota(p.begin(), p.end(), 0); */
    /* shuffle(p.begin(), p.end(), rng); */
    /* for (auto u : p) cout << u << " "; */
    /* cout << endl; */
    op = 0;
    auto [f, s] = best(n);

    debug(f, s);
    debug(bin(f, 10));
    debug(bin(s, 10));

    int best = 0;
    for (int i = 1; i < n; i++) {
        if (gtr(i, best)) {
            best = i;
        }
    }

    vector<int> pos;
    int now = best;
    pos.push_back(now);
    for (int i = best + 1; i < n; i++) {
        int r = comp(now, i, best);
        if (r == 0) {
            pos.push_back(i);
        } else if (r == -1) {
            continue;
        } else if (r == 1) {
            pos.clear();
            now = i;
            pos.push_back(i);
        }
    }
    for (int i = 0; i < best; i++) {
        int r = comp(now, i, best);
        if (r == 0) {
            pos.push_back(i);
        } else if (r == -1) {
            continue;
        } else if (r == 1) {
            pos.clear();
            now = i;
            pos.push_back(i);
        }
    }

    debug(pos);
    int best2 = pos[0];
    for (int i = 1; i < (int)pos.size(); i++) {
        if (gtr(best2, pos[i])) {
            best2 = pos[i];
        }
    }

    /* int mx = 0; */
    /* for (int i = 0; i < n; i++) { */
    /*     for (int j = 0; j < n; j++) { */
    /*         mx = max(mx, (i ^ j)); */
    /*     } */
    /* } */ 

    /* assert(mx == (p[best] ^ p[best2])); */

    cout << "! " << best << " " << best2 << endl;
}

int32_t main() {
    /* cin.tie(0)->sync_with_stdio(0); */
    int TC; cin >> TC;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}

/* vector<int> seg; */

/* int build(int u, int l, int r) { */
/*     if (l == r) { */
/*         return seg[u] = l; */
/*     } else { */
/*         int mid = (l + r) >> 1; */
/*         int L = build(u << 1, l, mid); */
/*         int R = build(u << 1 | 1, mid + 1, r); */
/*         if (gtr(L, R)) { */
/*             return seg[u] = R; */
/*         } else { */
/*             return seg[u] = L; */
/*         } */
/*     } */
/* } */

/* int find(int u, int l, int r, int x) { */
/*     if (l == r) { */
/*         return l; */
/*     } */ 
/*     int mid = (l + r) >> 1; */
/*     int L = seg[u << 1]; */
/*     int R = seg[u << 1 | 1]; */
/*     return -1; */
/* } */
