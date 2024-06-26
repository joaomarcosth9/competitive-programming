#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 1e6 + 6, S = 2 * N;
array<int, 26> to[S];
vector<int> adj[S];
int lnk[S], len[S], firstpos[S];
int id = 2, last = 1;
int it = 1;
void push(char ch) {
    int c = ch - 'a';
    int cur = id++;
    len[cur] = len[last] + 1;
    firstpos[cur] = it++;
    int p = last;
    while (p > 0 && !to[p][c]) {
        to[p][c] = cur;
        p = lnk[p];
    }
    if (p == 0) {
        lnk[cur] = 1;
    } else {
        int s = to[p][c];
        if (len[s] == len[p] + 1) {
            lnk[cur] = s;
        } else {
            int clone = id++;
            firstpos[clone] = firstpos[s];
            len[clone] = len[p] + 1;
            while (p > 0 && to[p][c] == s) {
                to[p][c] = clone;
                p = lnk[p];
            }
            to[clone] = to[s];
            lnk[clone] = lnk[s];
            lnk[cur] = lnk[s] = clone;
        }
    }
    last = cur;
}
 
void solve() {
    string s; cin >> s;
    ll k; cin >> k;
}
 
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}