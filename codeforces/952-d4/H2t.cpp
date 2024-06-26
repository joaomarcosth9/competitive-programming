#include <bits/stdc++.h>

using i64 = long long;
struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};
void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    
    const int N = n * m;
    DSU dsu(N);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + 1 < n && s[i][j] == '#' && s[i + 1][j] == '#') {
                dsu.merge(i * m + j, (i + 1) * m + j);
            }
            if (j + 1 < m && s[i][j] == '#' && s[i][j + 1] == '#') {
                dsu.merge(i * m + j, i * m + j + 1);
            }
        }
    }
    
    std::vector<int> er(n), ec(m);
    std::vector<int> mx(N, n), Mx(N, -1), my(N, m), My(N, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.') {
                er[i]++;
                ec[j]++;
            } else {
                int u = dsu.find(i * m + j);
                mx[u] = std::min(mx[u], std::max(0, i - 1));
                Mx[u] = std::max(Mx[u], std::min(n - 1, i + 1));
                my[u] = std::min(my[u], std::max(0, j - 1));
                My[u] = std::max(My[u], std::min(m - 1, j + 1));
            }
        }
    }
    
    std::vector f(n, std::vector<int>(m));
    for (int i = 0; i < N; i++) {
        if (dsu.find(i) == i && s[i / m][i % m] == '#') {
            int s = dsu.size(i);
            f[mx[i]][my[i]] -= s;
            f[mx[i]][0] += s;
            f[0][my[i]] += s;
            if (My[i] + 1 < m) {
                f[mx[i]][My[i] + 1] += s;
                f[0][My[i] + 1] -= s;
            }
            if (Mx[i] + 1 < n) {
                f[Mx[i] + 1][my[i]] += s;
                f[Mx[i] + 1][0] -= s;
                if (My[i] + 1 < m) {
                    f[Mx[i] + 1][My[i] + 1] -= s;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            f[i][j] += f[i][j - 1];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            f[i][j] += f[i - 1][j];
        }
    }
    
    int ans = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            int res = f[r][c] + er[r] + ec[c] - (s[r][c] == '.');
            ans = std::max(ans, res);
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
