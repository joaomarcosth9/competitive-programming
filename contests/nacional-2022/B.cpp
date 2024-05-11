#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

#define endl '\n'
typedef long long ll;
#define LINF ((int)1e9 + 500)
#define int ll

const ll MAXN = 4e5 + 5, INF = (ll)1e18 + 9, MAXR = 2e9;

struct Line {
    ll a, b;
    int L, R;
    Line(ll _a = 0, ll _b = -INF) : a(_a), b(_b), L(-1), R(-1) { }
    ll operator()(ll x) { return a * x + b; }
};
vector<Line> tree;

int le(int n) {
    if (tree[n].L == -1) {
        tree[n].L = tree.size();
        tree.emplace_back();
    }
    return tree[n].L;
}
int ri(int n) {
    if (tree[n].R == -1) {
        tree[n].R = tree.size();
        tree.emplace_back();
    }
    return tree[n].R;
}

void insert(Line line, int n = 0, ll l = -MAXR, ll r = MAXR) {
    ll mid = (l + r) / 2;
    bool bl = line(l) < tree[n](l);
    bool bm = line(mid) < tree[n](mid);
    if (!bm) {
        swap(tree[n], line);
    }
    if (l == r) {
        return;
    }
    if (line.b == -INF) return;
    if (bl != bm) {
        insert(line, le(n), l, mid);
    } else {
        insert(line, ri(n), mid + 1, r);
    }
}

ll query(int x, int n = 0, ll l = -MAXR, ll r = MAXR) {
    if (l > r) return -INF;
    if (l == r) {
        return tree[n](x);
    }
    ll mid = (l + r) / 2;
    if (x < mid) {
        return max(tree[n](x), query(x, le(n), l, mid));
    } else {
        return max(tree[n](x), query(x, ri(n), mid + 1, r));
    }
}

void solve() {
    int t;
    cin >> t;
    vector<int> x(t), y(t);
    for (int i = 0; i < t; i++) {
        int X, Y;
        cin >> X >> Y;
        x[i] = X, y[i] = Y;
    }
    int n;
    cin >> n;
    vector<pair<int, int>> lines(n);
    for (int i = 0; i < n; i++) {
        ll A, B;
        cin >> A >> B;
        lines[i] = {A, B};
    }
    vector<set<int>> res(n);
    vector<int> ans(t, -1);
    vector<vector<int>> q(n);

    for (int i = 0; i < t; i++) q[(n - 1) / 2].emplace_back(i);

    vector<int> l(t), r(t, n - 1);
    while (true) {
        bool ok = 1;
        tree.assign(1, Line());
        for (int i = 0; i < n; i++) {
            auto &[lll, rrr] = lines[i];
            insert({lll, rrr});
            /* cout << "Reta " << lll << " " << rrr << endl; */
            for (auto j : q[i]) {
                ok = 0;
                ll Y = query(x[j]);
                /* cout << "Ponto " << x[j] << " " << y[j] << endl; */
                /* cout << "Query " << Y << endl; */
                if (Y > y[j]) {
                    ans[j] = i;
                    r[j] = i - 1;
                } else {
                    l[j] = i + 1;
                }
                if (l[j] <= r[j]) {
                    int mid = (l[j] + r[j]) / 2;
                    q[mid].emplace_back(j);
                }
            }
            q[i].clear();
        }
        if (ok) break;
    }
    for (int i = 0; i < t; i++)
        if (ans[i] != -1) {
            res[ans[i]].emplace(i + 1);
        }
    for (int i = 0; i < n; i++) {
        cout << res[i].size() << " ";
        for (auto j : res[i]) cout << j << " ";
        cout << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
