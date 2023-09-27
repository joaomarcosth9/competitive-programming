#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define endl '\n'
#define cerr if (false) cerr
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

const int maxn = 1e5;
map<tuple<int, int, int, int>, int> edge, freq;
ld area[maxn];
ld dp[maxn][2];
bool border[maxn];
set<int> adj[maxn];

void dfs(int u, int p = -1) {
    if (!border[u]) dp[u][1] = area[u];
    for (auto &v : adj[u]) if (v != p) {
        dfs(v, u);
        dp[u][1] += dp[v][0];
        dp[u][0] += max(dp[v][0], dp[v][1]);
    }
}

void solve() {
    cout << setprecision(1) << fixed;
    int n; cin >> n;
    ld total = 0;
    for (int i = 0; i < n; i++) {
        vector<array<int, 2>> pts(3);
        for (auto &u : pts) {
            cin >> u[0] >> u[1];
        }
        array<ll, 2> v1, v2;
        v1 = {pts[1][0] - pts[0][0], pts[1][1] - pts[0][1]};
        v2 = {pts[2][0] - pts[0][0], pts[2][1] - pts[0][1]};
        area[i] = abs(ld(v1[0] * v2[1] - v2[0] * v1[1]) / 2);
        total += area[i];
        for (auto &u : pts) {
            for (auto &v : pts) {
                if (u == v) continue;
                auto U = u, V = v;
                if (U > V) swap(U, V);
                tuple<int, int, int, int> t = {u[0], u[1], v[0], v[1]};
                freq[t]++;
                if (edge.count(t)) {
                    int j = edge[t];
                    adj[i].emplace(j);
                    adj[j].emplace(i);
                }
                edge[t] = i;
            }
        }
    }
    for (auto [ed, cnt] : freq) {
        if (cnt == 1) {
            border[edge[ed]] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!border[i]) {
            dfs(i);
            total -= max(dp[i][0], dp[i][1]);
            break;
        }
    }
    cout << total << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
    auto start = chrono::steady_clock::now();
    if (TC) { cin >> TC;
        start = chrono::steady_clock::now();
        int TEST = 0;
        while (TEST < TC) {
            cerr << "[Testcase " << TEST + 1 << "]" << endl;
            solve();
            ++TEST;
            cout << endl;
        }
    } else solve();
#ifdef LOCAL_DEBUG
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "\nTime taken: ";
    cerr << chrono::duration <double, milli> (diff).count() << " ms" << endl;
#endif
}
