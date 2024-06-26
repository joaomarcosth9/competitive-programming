struct Dsu {
    vector<int> p;
    vector<ll> sz;
    Dsu(int n) : p(n), sz(n, 1) {
        for (int i = 0; i < n; i++) p[i] = i;
    }
    int find(int a) { return a == p[a] ? a : p[a] = find(p[a]); }
    bool unite(int a, int b) {
        if ((a = find(a)) == (b = find(b))) return false;
        if (sz[a] > sz[b]) swap(a, b);
        sz[b] += sz[a];
        p[a] = b;
        return true;
    }
};
