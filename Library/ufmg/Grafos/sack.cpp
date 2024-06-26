// Sack (DSU em arvores)
//
// Responde queries de todas as sub-arvores
// offline
//
// O(n log(n))

int sz[MAX], cor[MAX], cnt[MAX];
vector<int> g[MAX];

void build(int k, int d = 0) {
    sz[k] = 1;
    for (auto &i : g[k]) {
        build(i, d + 1);
        sz[k] += sz[i];
        if (sz[i] > sz[g[k][0]]) swap(i, g[k][0]);
    }
}

void compute(int k, int x, bool dont = 1) {
    cnt[cor[k]] += x;
    for (int i = dont; i < g[k].size(); i++) compute(g[k][i], x, 0);
}

void solve(int k, bool keep = 0) {
    for (int i = int(g[k].size()) - 1; i >= 0; i--) solve(g[k][i], !i);
    compute(k, 1);

    // agora cnt[i] tem quantas vezes a cor
    // i aparece na sub-arvore do k

    if (!keep) compute(k, -1, 0);
}
