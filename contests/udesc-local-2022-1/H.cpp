#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif
#define endl '\n'
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto& x){ return res; }
#define L2(res...) [&](const auto& x, const auto& y){ return res; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

const int maxn = 2005, maxu = 1e5 + 5;
vector<int> st, a[maxn];
int n, m;
int conv[maxu], mask[maxn];
int K;

// Blossom
//
// Matching maximo em grafo geral
//
// O(n^3)
// Se for bipartido, nao precisa da funcao
// 'contract', e roda em O(nm)

const int MAX = 2005;
vector<int> g[MAX];
int match[MAX]; // match[i] = com quem i esta matchzado ou -1
int pai[MAX], base[MAX], vis[MAX];
queue<int> q;

void contract(int u, int v, bool first = 1) {
    static vector<bool> bloss;
    static int l;
    if (first) {
        bloss = vector<bool>(n, 0);
        vector<bool> teve(n, 0);
        int k = u;
        l = v;
        while (1) {
            teve[k = base[k]] = 1;
            if (match[k] == -1) break;
            k = pai[match[k]];
        }
        while (!teve[l = base[l]]) l = pai[match[l]];
    }
    while (base[u] != l) {
        bloss[base[u]] = bloss[base[match[u]]] = 1;
        pai[u] = v;
        v = match[u];
        u = pai[match[u]];
    }
    if (!first) return;
    contract(v, u, 0);
    for (int i = 0; i < n; i++)
        if (bloss[base[i]]) {
            base[i] = l;
            if (!vis[i]) q.push(i);
            vis[i] = 1;
        }
}

int getpath(int s) {
    for (int i = 0; i < n; i++) base[i] = i, pai[i] = -1, vis[i] = 0;
    vis[s] = 1;
    q = queue<int>();
    q.push(s);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int i : g[u]) {
            if (base[i] == base[u] or match[u] == i) continue;
            if (i == s or (match[i] != -1 and pai[match[i]] != -1))
                contract(u, i);
            else if (pai[i] == -1) {
                pai[i] = u;
                if (match[i] == -1) return i;
                i = match[i];
                vis[i] = 1;
                q.push(i);
            }
        }
    }
    return -1;
}

int blossom() {
    int ans = 0;
    memset(match, -1, sizeof(match));
    for (int i = 0; i < n; i++)
        if (match[i] == -1)
            for (int j : g[i])
                if (match[j] == -1) {
                    match[i] = j;
                    match[j] = i;
                    ans++;
                    break;
                }
    for (int i = 0; i < n; i++)
        if (match[i] == -1) {
            int j = getpath(i);
            if (j == -1) continue;
            ans++;
            while (j != -1) {
                int p = pai[j], pp = match[p];
                match[p] = j;
                match[j] = p;
                j = pp;
            }
        }
    return ans;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        st.eb(x);
    }
    sort(all(st));
    for (int i = 0; i < n; i++) {
        int nn; cin >> nn;
        for (int j = 0; j < nn; j++) {
            int x; cin >> x;
            a[i].eb(x);
        }
        sort(all(a[i]));
    }
    for (int i = 0; i < m; i++) {
        conv[st[i]] = i + 1;
        K |= (1 << (i + 1));
    }
    for (int i = 0; i < n; i++) {
        int nn = size(a[i]);
        for (int j = 0; j < nn; j++) {
            if (conv[a[i][j]]) {
                mask[i] |= (1 << (conv[a[i][j]]));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if ((mask[i] | mask[j]) == K) {
            g[i].eb(j);
        }
    }
    cout << (blossom() >= (n / 2) ? "SIM" : "NAO") << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}

