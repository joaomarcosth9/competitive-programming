#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

struct SparseTable {
    int n, LG;
    vector<vector<ll>> st;
    ll merge(ll a, ll b) { return max(a, b); }
    const ll neutral = -1e18;
    void build(const vector<ll> &v) {
        n = (int)v.size();
        LG = 32 - __builtin_clz(n);
        st = vector<vector<ll>>(LG, vector<ll>(n));
        for (int i = 0; i < n; i++) st[0][i] = v[i];
        for (int i = 0; i < LG - 1; i++)
            for (int j = 0; j + (1 << i) < n; j++)
                st[i + 1][j] = merge(st[i][j], st[i][j + (1 << i)]);
    }
    void build(ll *bg, ll *en) { build(vector<ll>(bg, en)); }
    ll query(int l, int r) {
        if (l > r) return neutral;
        int i = 31 - __builtin_clz(r - l + 1);
        return merge(st[i][l], st[i][r - (1 << i) + 1]);
    }
};

void solve() {
    int n, xx;
    cin >> n >> xx;

    vector<ll> a(n);
    for (auto &i : a)
        cin >> i;

    vector<int> f(n);

    vector<ll> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }

    SparseTable st;
    st.build(a);

    auto sum_query = [&](int l, int r) {
        if (l > r) swap(l, r);
        l = max(0, l);
        r = min(n - 1, r);
        return pref[r] - (l > 0 ? pref[l - 1] : 0);
    };

    auto find_left_border = [&] (int i) {
        int l = 0, r = i;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (st.query(mid, i) <= a[i]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };

    auto find_right_border = [&] (int i) {
        int l = i, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (st.query(i, mid) <= a[i]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r;
    };

    vector<bool> can(n);
    set<int> can_set;

    f[0] = 1;
    can[0] = 1;
    can_set.insert(0);

    for (int i = 1; i < n; i++) {
        // [0, 1, ... i - 1] [i]
        // quem conseguia, ainda consegue?
        //      -> basta ver se a[i] < pref[i - 1]
        //      -> ninguem mais consegue ou todo mundo ainda consegue
        if (a[i] < pref[i - 1]) {
            // geral ainda consegue
        } else {
            // ninguem mais consgue, pq ninguem pega o i
            while (can_set.size()) {
                int j = *can_set.begin();
                can[j] = 0;
                can_set.erase(j);
            }
        }

        int R = -1;

        if (can_set.size()) {
            R = *can_set.rbegin();
        }

        // i consegue comer tudo?
        //      -> basta responder (??)
        int j = find_left_border(i);
        assert(j <= i && j >= 0);

        if (j == 0 || (sum_query(j, i) > a[j - 1] && can[j - 1])) {
            can[i] = 1;
            can_set.insert(i);
            // reseta o sufixo todo dos zeros
        } else {
            // i entra no sufixo dos zeros
        }

        // e quem nao conseguia, sera q consegue agora?
        //      -> um sufixo de caras que nao conseguia, pode conseguir agora
        //          -> como ver?
        //          ->  ---1--1-11[0000][i]
        //          e agora??????

        if (R != -1) {
            // tem sufixo de zeros pra ver
        }

        f[i] = can_set.size();
    }

    for (int i = xx - 1; i < n; i++) {
        cout << f[i] << " \n"[i == n - 1];
    }
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
