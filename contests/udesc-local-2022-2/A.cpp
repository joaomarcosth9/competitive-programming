#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 100;
int n, c;
int tam[MAX];
int vis[MAX];
vector<int> adj[MAX];
map<int, int> freq;

void dfs(int u) {
    vis[u]++;
    freq[tam[u]]++;
    for (auto v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
}

void solve() {
    cin >> n >> c;
    for (int i = 1; i <= n; i++) cin >> tam[i];
    for (int i = 0; i < c; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            int maxf = INT_MIN;
            int nn = 0;
            for (auto kv : freq) {
                nn += kv.second;
                maxf = max(maxf, kv.second);
            }
            res = max(res, nn - maxf);
            freq.clear();
        }
    }
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}
