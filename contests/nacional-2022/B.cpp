#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define endl '\n'
#define cerr                                                                                                           \
    if (false) cerr
#endif

typedef long long ll;
#define LINF ((int)1e9 + 500)
#define int ll

template <ll MI = ll(-1e9), ll MA = ll(1e9)> struct LichaoTree {
    struct line {
        ll a, b;
        array<int, 2> ch;
        line(ll a_ = 0, ll b_ = -LINF) : a(a_), b(b_), ch({-1, -1}) {}
        ll operator()(ll x) { return a * x + b; }
    };
    vector<line> ln;

    int ch(int p, int d) {
        if (ln[p].ch[d] == -1) {
            ln[p].ch[d] = ln.size();
            ln.emplace_back();
        }
        return ln[p].ch[d];
    }
    LichaoTree() { ln.emplace_back(); }

    void add(line s, ll l = MI, ll r = MA, int p = 0) {
        ll m = l + (r - l) / 2;
        bool L = s(l) > ln[p](l);
        bool M = s(m) > ln[p](m);
        bool R = s(r) > ln[p](r);
        debug(m, s.a, M, l, r);
        if (M) swap(ln[p], s), swap(ln[p].ch, s.ch);
        if (s.b == -LINF) return;
        if (L != M)
            add(s, l, m - 1, ch(p, 0));
        else if (R != M)
            add(s, m + 1, r, ch(p, 1));
    }
    ll query(int x, ll l = MI, ll r = MA, int p = 0) {
        ll m = l + (r - l) / 2, ret = ln[p](x);
        // debug(x, ret, l, r);
        if (l > r) return -LINF;
        if (x < m) return max(ret, query(x, l, m - 1, ch(p, 0)));
        return max(ret, query(x, m + 1, r, ch(p, 1)));
    }
};

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
        LichaoTree lichao;
        for (int i = 0; i < n; i++) {
            auto &[lll, rrr] = lines[i];
            lichao.add({lll, rrr});
            /* cout << "Reta " << lll << " " << rrr << endl; */
            for (auto j : q[i]) {
                ok = 0;
                ll Y = lichao.query(x[j]);
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
