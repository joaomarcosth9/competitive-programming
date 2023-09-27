#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

const int maxn = 105;
bool mat[maxn][maxn];
int grau[maxn];

const int N = 105;
const int INF = 2; // tanto faz

// n -> numero de equacoes, m -> numero de variaveis
// a[i][j] para j em [0, m - 1] -> coeficiente da variavel j na iesima equacao
// a[i][j] para j == m -> resultado da equacao da iesima linha
// ans -> bitset vazio, que retornara a solucao do sistema (caso exista)
int gauss(vector<bitset<N>> a, int n, int m, bitset<N> &ans) {
    vector<int> where(m, -1);

    for (int col = 0, row = 0; col < m && row < n; col++) {
        for (int i = row; i < n; i++) {
            if (a[i][col]) {
                swap(a[i], a[row]);
                break;
            }
        }
        if (!a[row][col]) continue;
        where[col] = row;

        for (int i = 0; i < n; i++) {
            if (i != row && a[i][col]) a[i] ^= a[row];
        }
        row++;
    }

    for (int i = 0; i < m; i++) {
        if (where[i] != -1) {
            ans[i] = a[where[i]][m] / a[where[i]][i];
        }
    }
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += ans[j] * a[i][j];
        }
        if (abs(sum - a[i][m]) > 0) return 0; // Sem solução
    }

    for (int i = 0; i < m; i++) {
        if (where[i] == -1) return INF; // Infinitas solucoes
    }
    return 1; // Unica solucao (retornada no bitset ans)
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        mat[a][b] = mat[b][a] = 1;
        grau[a]++;
        grau[b]++;
    }
    vector<bitset<maxn>> p(n);
    bitset<maxn> ans;

    for (int i = 0; i < n; i++) {
        int g = grau[i] & 1;
        for (int j = 0; j < n; j++) {
            p[i][j] = mat[i][j];
        }
        if (g == 1) { // tem numero impar de amigos
                      // xa ^ xb ... = xi
                      // xi ^ xa ^ xb ... = 0
            p[i][i] = 1;
            p[i][n] = 0;
        } else { // tem numero par de amigos
                 // xa ^ xb ... = 1
            p[i][n] = 1;
        }
        debug(i, p[i]);
    }
    debug(ans);
    auto res = gauss(p, n, n, ans);
    debug(res);
    debug(ans);
    cout << (res ? "Y" : "N") << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
