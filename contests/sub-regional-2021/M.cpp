#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 1e5 + 10;
pair<int, int> qe[MAX];
int q, pf, sk, cq, ck, dd[MAX], vis[MAX];
vector<int> Adj[MAX];

void dfs(int n) {
    vis[n]++;
    if (!dd[n]) {
        if (sk) {
            sk = 0;
            cout << n << endl;
        }
        while (cq < q) {
            auto [t, d] = qe[cq];
            if (t == 1) {
                // alguem teve filho
                Adj[d].push_back(pf);
                pf++;
                cq++;
            } else if (t == 2) {
                // alguem foi de base
                dd[d]++;
                cq++;
                if (d == n) {
                    sk = 1;
                    break;
                } else {
                    cout << n << endl;
                }
            }
        }
    }
    for (int i = 0; i < (int)Adj[n].size(); i++) {
        if (!vis[Adj[n][i]]) dfs(Adj[n][i]);
    }
}

void solve() {
    cin >> q;
    pf = 2;
    for (int i = 0; i < q; i++) {
        cin >> qe[i].first >> qe[i].second;
    }
    dfs(1);
}

int main() {
    _ solve();
    return 0;
}
