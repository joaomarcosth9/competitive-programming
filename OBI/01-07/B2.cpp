#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);

using namespace std;

const int MAX = 2e3;

vector<int> Adj[MAX];
int alt[MAX];
pair<int, int> res[MAX];
int vis[MAX];

void dfs(int n) {
    vis[n]++;
    res[n].first = 1;
    res[n].second = alt[n];
    for (int i = 0; i < Adj[n].size(); i++) {
        if (!vis[Adj[n][i]]) dfs(Adj[n][i]);
    }
    for (int i = 0; i < Adj[n].size(); i++) {
        if (res[Adj[n][i]].second < res[n].second) {
            res[n].second = res[Adj[n][i]].second;
            res[n].first = res[Adj[n][i]].first + 1;
        } else if (res[Adj[n][i]].second == res[n].second) {
            res[n].first = max(res[n].first, res[Adj[n][i]].first + 1);
        }
    }
}

void solve() {
    int s, t, p;
    cin >> s >> t >> p;
    for (int i = 1; i <= s; i++) {
        cin >> alt[i];
    }
    for (int i = 0; i < t; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        if (alt[t1] > alt[t2]) {
            Adj[t1].push_back(t2);
        } else {
            Adj[t2].push_back(t1);
        }
    }
    dfs(p);
    cout << res[p].first - 1 << endl;
}

int main() {
    _ solve();
    return 0;
}
