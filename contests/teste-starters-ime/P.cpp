#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

struct Manacher {
    int n;
    ll count;
    vector<int> d1, d2, man;
    ll solve(const string &s) {
        n = int(s.size()), count = 0;
        solve_odd(s);
        solve_even(s);
        man.assign(2 * n - 1, 0);
        for (int i = 0; i < n; i++) {
            man[2 * i] = 2 * d1[i] - 1;
        }
        for (int i = 0; i < n - 1; i++) {
            man[2 * i + 1] = 2 * d2[i + 1];
        }
        return count;
    }
    void solve_odd(const string &s) {
        d1.assign(n, 0);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
                k++;
            }
            count += d1[i] = k--;
            if (i + k > r) {
                l = i - k, r = i + k;
            }
        }
    }
    void solve_even(const string &s) {
        d2.assign(n, 0);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
                k++;
            }
            count += d2[i] = k--;
            if (i + k > r) {
                l = i - k - 1, r = i + k;
            }
        }
    }
    bool query(int i, int j) {
        return man[i + j] >= j - i + 1;
    }
} mana;

struct DSU {
    vector<int> par, sz;
    int number_of_sets;
    DSU(int n = 0) : par(n), sz(n, 1), number_of_sets(n) {
        iota(par.begin(), par.end(), 0);
    }
    int find(int a) { return a == par[a] ? a : par[a] = find(par[a]); }
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) {
            return false;
        }
        number_of_sets--;
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        par[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

void solve() {
    string s; cin >> s;
    int n = (int)s.size();

    mana.solve(s);

    debug(mana.d1);
    debug(mana.d2);

    set<int> idx;
    for (int i = 0; i < n; i++) {
        idx.insert(i);
    }

    vector<int> first(n, -1), first2(n, -1);

    for (int i = 0; i < n; i++) {
        int l = i - mana.d1[i] + 1;
        if (l == i)
            continue;
        auto it = idx.lower_bound(l);
        while (it != idx.end() && *it < i) {
            int j = *it;
            int k = i + (i - j);
            first[j] = k;
            assert(s[j] == s[k]);
            it = idx.erase(it);
        }
    }

    for (int i = 0; i < n; i++) {
        idx.insert(i);
    }

    for (int i = 1; i < n; i++) {
        int l = i - mana.d2[i];
        if (l == i)
            continue;
        auto it = idx.lower_bound(l);
        debug(i, l);
        while (it != idx.end() && *it < i) {
            int j = *it;
            int k = i + (i - j) - 1;
            first2[j] = k;
            assert(s[j] == s[k]);
            it = idx.erase(it);
        }
    }

    DSU d(n);

    for (int i = 0; i < n; i++) {
        if (first[i] != -1) {
            d.unite(i, first[i]);
        }
        if (first2[i] != -1) {
            d.unite(i, first2[i]);
        }
    }

    cout << d.number_of_sets << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}
