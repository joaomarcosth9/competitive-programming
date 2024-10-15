#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
const int MAX = 5e6 + 5, INF = 1e9;

template <int MINL = (int)0, int MAXR = (int)MAX + 500>
struct SegTree {
    int merge(int a, int b) { return min(a, b); }
    const int neutral = INF;

    vector<int> t;
    vector<int> Lc, Rc;

    inline int newnode() {
        t.push_back(neutral);
        Lc.push_back(-1);
        Rc.push_back(-1);
        return (int)t.size() - 1;
    }

    inline int lc(int p) {
        if (Lc[p] == -1) Lc[p] = newnode();
        return Lc[p];
    }

    inline int rc(int p) {
        if (Rc[p] == -1) Rc[p] = newnode();
        return Rc[p];
    }

    SegTree() { newnode(); }

    int query(int p, int l, int r, int L, int R) {
        if (l > R || r < L) return neutral;
        if (l >= L && r <= R) return t[p];
        int mid = l + (r - l) / 2;
        auto ql = query(lc(p), l, mid, L, R);
        auto qr = query(rc(p), mid + 1, r, L, R);
        return merge(ql, qr);
    }
    int query(int l, int r) { return query(0, MINL, MAXR, l, r); }

    void update(int p, int l, int r, int i, int x) {
        if (l == r) {
            t[p] = x; // substitui
            return;
        }
        int mid = l + (r - l) / 2;
        if (i <= mid) update(lc(p), l, mid, i, x);
        else update(rc(p), mid + 1, r, i, x);
        t[p] = merge(t[lc(p)], t[rc(p)]);
    }
    void update(int i, int x) { update(0, MINL, MAXR, i, x); }
};

void solve() {
    int n;
    cin >> n;

    set<int> values;
    values.insert(0);
    values.insert(MAX);
    map<int, set<int>> gaps;
    gaps[MAX - 1].insert(0);

    SegTree<0, MAX + 500> st;
    
    st.update(MAX - 1, 0);

    auto insert = [&] (int x) {
        if (values.count(x)) {
            return;
        }

        auto it = values.lower_bound(x);

        int gap = *it - x - 1;
        gaps[gap].insert(x);
        st.update(gap, *gaps[gap].begin());

        auto it2 = prev(it);
        gap = x - *it2 - 1;
        gaps[gap].insert(*it2);
        st.update(gap, *gaps[gap].begin());

        gaps[*it - *it2 - 1].erase(*it2);

        if (gaps[*it - *it2 - 1].empty()) {
            gaps.erase(*it - *it2 - 1);
            st.update(*it - *it2 - 1, INF);
        } else {
            st.update(*it - *it2 - 1, *gaps[*it - *it2 - 1].begin());
        }

        values.insert(x);
    };

    auto remove = [&] (int x) {
        auto it = values.find(x);

        auto it2 = next(it);
        auto it3 = prev(it);

        gaps[x - *it3 - 1].erase(*it3);
        if (gaps[x - *it3 - 1].empty()) {
            gaps.erase(x - *it3 - 1);
            st.update(x - *it3 - 1, INF);
        } else {
            st.update(x - *it3 - 1, *gaps[x - *it3 - 1].begin());
        }

        gaps[*it2 - x - 1].erase(x);
        if (gaps[*it2 - x - 1].empty()) {
            gaps.erase(*it2 - x - 1);
            st.update(*it2 - x - 1, INF);
        } else {
            st.update(*it2 - x - 1, *gaps[*it2 - x - 1].begin());
        }

        values.erase(x);

        it = values.upper_bound(x);
        it2 = prev(it);

        gaps[*it - *it2 - 1].insert(*it2);
        st.update(*it - *it2 - 1, *gaps[*it - *it2 - 1].begin());
    };
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(x);
    }

    int q;
    cin >> q;

    while (q--) {
        char op;
        cin >> op;
        if (op == '-') {
            int x;
            cin >> x;
            remove(x);
        } else if (op == '+') {
            int x;
            cin >> x;
            insert(x);
        } else {
            int k;
            cin >> k;
            if (values.empty() || *values.begin() > k) {
                cout << 1 << endl;
            } else {
                auto query = st.query(k, MAX);
                cout << query + 1 << " ";
            }
        }
    }
    cout << endl;

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}
