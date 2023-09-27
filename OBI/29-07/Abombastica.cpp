#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 20;
int n, m, a, b, x, y;
int M[MAX][MAX];
int vis[MAX][MAX];
int res = INT_MAX;

pair<int, int> moves[] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void dfs(int i, int j, int n) {
    vis[i][j]++;
    if (n > res) return;
    if(i == x 
    for(auto [ii,jj] : moves){
        if (!vis[i + ii][j + jj]) dfs(i + ii, j + jj, n + 1);
    }
}

void solve() {
    cin >> n >> m >> a >> b >> x >> y;
    for (int i = 0; i <= n + 1; i += n + 1)
        for (int j = 0; j <= m + 1; j++) vis[i][j] = 1;
    for (int i = 0; i <= m + 1; i += m + 1)
        for (int j = 0; j <= n + 1; j++) vis[j][i] = 1;
    cout << "Delta x: " << x - a << endl;
    cout << "Delta y: " << y - b << endl;
    for (int i = 2; i <= n; i += 2)
        for (int j = 2; j <= m; j += 2) M[i][j] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << M[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            cout << vis[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    _ solve();
    return 0;
}
