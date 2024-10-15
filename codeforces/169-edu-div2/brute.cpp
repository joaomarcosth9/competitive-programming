#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
#define int ll

map<int, int> dp;

int grundy(int i) {
    if (dp.count(i)) return dp[i];
    if (i == 0) {
        return dp[0] = 0;
    }
    set<int> st;
    for (int j = 1; j <= i; j++) {
        if (gcd(j, i) == 1) {
            st.insert(grundy(i - j));
        }
    }
    int cmex = 0;
    while (st.size() && *st.begin() == cmex) {
        st.erase(st.begin());
        cmex++;
    }
    return dp[i] = cmex;
}

const int MAX = 1e7 + 5;
int g[MAX], spf[MAX];

bool is_prime[MAX];

void solve() {
    int n;
    cin >> n;

    int x = 0;

    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;
        x ^= g[y];
    }

    cout << (x ? "Alice" : "Bob") << endl;

    return;
    const int M = 500;
    vector<vector<int>> facts(M + 1);
    for (int i = 1; i <= M; i++) {
        if (is_prime[i]) {
            for (int j = i + i; j <= M; j += i) {
                facts[j].push_back(i);
            }
        }
    }
    map<int, vector<int>> all;
    for (int i = 1; i <= M; i++) {
        cout << i << ": " << grundy(i) << endl;
        all[grundy(i)].push_back(i);
        /* cout << "{ "; */
        /* for (int j = 1; j <= i; j++) { */
        /*     if (gcd(j, i) == 1) { */
        /*         cout << j << " "; */
        /*     } */
        /* } */
        /* cout << "}"; */
        /* cout << endl << endl; */
    }
    for (auto [k, v] : all) {
        cout << endl;
        cout << k << ": " << endl;
        cout << "{ ";
        for (auto u : v) {
            cout << u << " ";
            cout << "( ";
            for (auto f : facts[u]) {
                cout << f << " ";
            }
            cout << ") ";
        }
        cout << "}";
        cout << endl;
    }
    for (int i = 0; i < MAX; i++) {
        if (g[i] != grundy(i)) {
            cout << i << ": " << g[i] << " " << grundy(i) << endl;
            exit(0);
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    g[0] = 0;
    g[1] = 1;

    for (int i = 2; i < MAX; i++) {
        is_prime[i] = true;
    }

    int it = 2;
    for (int i = 2; i < MAX; i++) {
        if (is_prime[i]) {
            spf[i] = i;
            if (i >= 3) {
                g[i] = it++;
            }
            for (int j = i + i; j < MAX; j += i) {
                is_prime[j] = false;
                if (spf[j] == 0) {
                    spf[j] = i;
                    g[j] = g[i];
                }
            }
        }
    }

    /* g[0] = 0; */
    /* g[1] = 1; */
    /* for (int i = 2; i < MAX; i++) { */
    /*     is_prime[i] = true; */
    /* } */
    /* int it = 2; */
    /* for (int i = 1; i < MAX; i++) { */
    /*     if (i % 2 == 0) { */
    /*         g[i] = 0; */
    /*     } */
    /*     if (is_prime[i]) { */
    /*         if (i >= 3) { */
    /*             g[i] = it++; */
    /*         } */
    /*         for (int j = i + i; j < MAX; j += i) { */
    /*             is_prime[j] = false; */
    /*         } */
    /*     } */
    /* } */
    /* for (int i = 3; i < MAX; i += 6) { */
    /*     g[i] = 2; */
    /* } */
    /* vector<int> step = {20, 10}; */
    /* it = 0; */
    /* for (int i = 5; i < MAX; i += step[it], it = (it + 1) % 2) { */
    /*     g[i] = 3; */
    /* } */
    /* g[7] = g[49] = 4; */
    /* step = {28, 14}; */
    /* it = 0; */
    /* for (int i = 49; i < MAX; i += step[it], it = (it + 1) % 2) { */
    /*     g[i] = 4; */
    /* } */
    /* g[11] = g[121] = 5; */
    /* step = {22, 44}; */
    /* it = 0; */
    /* for (int i = 121; i < MAX; i += step[it], it = (it + 1) % 2) { */
    /*     g[i] = 5; */
    /* } */

    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}
