#include <bits/stdc++.h>

using namespace std;

const int MAX = 505;

int n, m, it;

int age[MAX];
int ftr[MAX];
int rtf[MAX];

void change(int a, int b) {
    int oldrtfa = rtf[a];
    int oldrtfb = rtf[b];
    rtf[a] = oldrtfb;
    rtf[b] = oldrtfa;
    ftr[rtf[a]] = a;
    ftr[rtf[b]] = b;
}

vector<vector<int>> V(MAX);

int smaller;

void dfs(int pessoa) {
    int len = V[pessoa].size();
    for (int i = 0; i < len; i++) {
        if (smaller > age[ftr[V[pessoa][i]]]) {
            smaller = age[ftr[V[pessoa][i]]];
        }
        dfs(V[pessoa][i]);
    }
}

void solve() {
    cin >> n >> m >> it;
    for (int i = 1; i <= n; i++) {
        cin >> age[i];
    }
    for (int i = 1; i <= n; i++) {
        rtf[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        ftr[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        V[t2].push_back(t1);
    }
    for (int k = 0; k < it; k++) {
        char op;
        cin >> op;
        if (op == 'P') {
            int pessoa;
            cin >> pessoa;
            smaller = 105;
            dfs(pessoa);
            if (smaller == 105) {
                cout << '*' << endl;
            } else {
                cout << smaller << endl;
            }
        } else if (op == 'T') {
            int pessoa1, pessoa2;
            cin >> pessoa1 >> pessoa2;
            change(pessoa1, pessoa2);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
