#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define int long long 

const int maxn = (1 << 10);
vector<pair<int,int>> adj[maxn];

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    int source = 0;
    for (int i = n - 1, j = 0; i >= 0; i--, j++) {
        if (s[i] == '1') source |= (1 << j);
    }
    for (int c = 0; c < m; c++) {
        int w; cin >> w;
        int entra = 0, sai = 0; 
        cin >> s;
        for (int i = n - 1, j = 0; i >= 0; i--, j++) {
            if (s[i] == '0') sai |= (1 << j); // sintoma se mantem
        }
        cin >> s;
        for (int i = n - 1, j = 0; i >= 0; i--, j++) {
            if (s[i] == '1') entra |= (1 << j); 
        }
        for (int i = 0; i < maxn; i++) {
            int go = (i & sai) | entra;
            adj[i].emplace_back(w, go);
        }
    }
    const int INF = 2e9;
    vector<int> dis(maxn, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.emplace(0, source);
    dis[source] = 0;
    while (!pq.empty()) {
        auto [W, U] = pq.top();
        pq.pop();
        if(W > dis[U]) continue;
        for (auto [w, v] : adj[U]) {
            if(dis[v] <= W + w) continue;
            dis[v] = W + w;
            pq.emplace(W + w, v);
        }
    }
    cout << (dis[0] == INF ? -1 : dis[0]) << '\n';
    for (int i = 0; i < maxn; i++) adj[i].clear();
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if (TC) { cin >> TC;
        while (TC--) solve();
    } else solve();
    return 0;
}
