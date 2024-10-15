#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

#ifndef ONLINE_JUDGE
const int MAX_N = 4e2 + 5;
#else
const int MAX_N = 1e5 + 5;
#endif

const int S = MAX_N * 2;

array<int, 26> go[S];
int id = 2, last = 1, lnk[S], len[S];
ll tot = 0;

void push(char ch) {
    int c = (int)(ch - 'a');
    int cur = id++;
    len[cur] = len[last] + 1;
    int p = last;
    while (p > 0 && !go[p][c]) {
        go[p][c] = cur;
        p = lnk[p];
    }
    if (p == 0) {
        lnk[cur] = 1;
    } else {
        int s = go[p][c];
        if (len[s] == len[p] + 1) {
            lnk[cur] = s;
        } else {
            int clone = id++;

            tot -= len[s] - len[lnk[s]];

            len[clone] = len[p] + 1;
            lnk[clone] = lnk[s];
            go[clone] = go[s];
            while (p > 0 && go[p][c] == s) {
                go[p][c] = clone;
                p = lnk[p];
            }
            lnk[s] = lnk[cur] = clone;

            tot += len[s] - len[lnk[s]];
            tot += len[clone] - len[lnk[clone]];
        }
    }

    tot += len[cur] - len[lnk[cur]];
    last = cur;
}

int n;
string s;
ll res = 0;

void solve() {
    cin >> s;
    n = (int)s.size();

    map<string, bool> vis;

    vector<ll> total(n + 1), pref(n + 1), add(n + 1);

    for (int i = 1; i <= n; i++) {
        push(s[i - 1]);
        total[i] = tot;
        add[i] = total[i] - total[i - 1];
        pref[i] = pref[i - 1] + total[i];
    }

    res += (total[n] * (total[n] + 1)) / 2;

    for (int i = 1; i <= n; i++) {


    }

    cout << res << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}
