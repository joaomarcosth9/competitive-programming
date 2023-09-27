#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 1e2 + 5;

int l, c;
char M[MAX][MAX];
char vis[MAX][MAX];
pair<int, int> moves[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
pair<int, int> res;

void dfs(int sl, int sc) {
    vis[sl][sc]++;
    int foi = 0;
    for (auto [ml, mc] : moves) {
        if (!vis[sl + ml][sc + mc] && M[sl + ml][sc + mc] == 'H') {
            dfs(sl + ml, sc + mc);
            foi++;
            break;
        }
    }
    if (foi == 0) {
        res = {sl, sc};
    }
}

void solve() {
    cin >> l >> c;
    pair<int, int> st;
    for (int i = 0; i <= l + 1; i++) {
        for (int j = 0; j <= c + 1; j++) {
            M[i][j] = '.';
        }
    }
    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> M[i][j];
            if (M[i][j] == 'o') st = {i, j};
        }
    }
    dfs(st.first, st.second);
    cout << res.first << ' ' << res.second << endl;
}

int main() {
    _ solve();
    return 0;
}
