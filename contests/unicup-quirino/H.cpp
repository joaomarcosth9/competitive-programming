#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 1e5 + 5;
vector<int> adj[N];

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for (int i = 1; i < n; i++) {
        cin >> p[i];
        p[i]--;
        adj[p[i]].push_back(i);
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}