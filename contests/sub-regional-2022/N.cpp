#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif
typedef long long ll;

namespace seg {
    const ll ESQ = 0, DIR = 1e9 + 7;
    struct node {
        ll v = 0;
        node *l = NULL, *r = NULL;
        node() {}
        node(ll v) : v(v) {}
        node(node *l, node *r) : l(l), r(r) { v = l->v + r->v; }
        void apply() {
            if (l == NULL) l = new node();
            if (r == NULL) r = new node();
        }
    };
    vector<node *> roots;
    void build() { roots.push_back(new node()); }
    void push(node *n, int esq, int dir) {
        if (esq != dir) n->apply();
    }

    node *update(node *n, int esq, int dir, int x, int v) {
        push(n, esq, dir);
        if (esq == dir) return new node(n->v + v);
        int mid = (esq + dir) >> 1;
        if (x <= mid)
            return new node(update(n->l, esq, mid, x, v), n->r);
        else
            return new node(n->l, update(n->r, mid + 1, dir, x, v));
    }
    int update(int root, int pos, int val) {
        node *novo = update(roots[root], ESQ, DIR, pos, val);
        roots.push_back(novo);
        return roots.size() - 1;
    }
    ll query(node *n, int esq, int dir, int l, int r) {
        push(n, esq, dir);
        if (esq > r || dir < l) return 0;
        if (l <= esq && dir <= r) return n->v;
        int mid = (esq + dir) >> 1;
        return query(n->l, esq, mid, l, r) + query(n->r, mid + 1, dir, l, r);
    }
    ll query(int root, int l, int r) { return query(roots[root], ESQ, DIR, l, r); }
    int kth(node *L, node *R, int esq, int dir, int k) {
        push(L, esq, dir);
        push(R, esq, dir);
        if (esq == dir) return esq;
        int mid = (esq + dir) >> 1;
        int cont = R->r->v - L->r->v;
        if (cont < k)
            return kth(L->l, R->l, esq, mid, k - cont);
        else
            return kth(L->r, R->r, mid + 1, dir, k);
    }
    int kth(int l_root, int r_root, int k) { return kth(roots[l_root], roots[r_root], ESQ, DIR, k); }
} // namespace seg

void solve() {
    int n;
    cin >> n;
    vector<int> aa(n), bb(n), a, b;
    for (auto &u : aa) cin >> u;
    for (auto &u : bb) cin >> u;
    int k, l;
    cin >> k >> l;
    for (int i = n - k; i < n; i++) {
        a.push_back(aa[i]);
        b.push_back(bb[i]);
    }
    for (int i = 0; i < k; i++) {
        a.push_back(aa[i]);
        b.push_back(bb[i]);
    }
    ll res = 0, current = 0;
    db(a, b);
    seg::build();
    for (int i = 0; i < k; i++) current += a[i];
    for (int i = 0; i < k; i++) seg::update(i, b[i], 1);
    for (int i = 0; i < k; i++) {
        db(b[i], seg::query(i + 1, b[i], b[i]));
    }
    for (int i = 1; i <= l; i++) {
        int temp = seg::kth(0, k, i);
        current += temp;
        db(i, seg::kth(0, k, i));
    }
    n = a.size();
    res = current;
    int last_root = k;
    for (int i = k; i < n; i++) {
        current -= a[i - k];
        current += a[i];
        int temp = seg::kth(0, last_root, l);
        seg::update(last_root++, b[i], 1);
        int newtemp = seg::kth(0, last_root, l);
        if (newtemp != temp) {
            current += b[i];
            current -= temp;
        }
        temp = newtemp;
        seg::update(last_root++, b[i - k], -1);
        newtemp = seg::kth(0, last_root, l);
        if (newtemp != temp) {
            current -= b[i - k];
            current += newtemp;
        }

        res = max(res, current);
    }
    cout << res << endl;
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
