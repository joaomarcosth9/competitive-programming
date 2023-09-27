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

const int mod = 1e9 + 7;

vector<vector<ll>> mul(vector<vector<ll>> a, vector<vector<ll>> b) {
    int n = size(a);
    vector<vector<ll>> ret(n);
    for (int i = 0; i < n; i++) ret[i].resize(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % mod;
            }
        }
    }

    return ret;
}

vector<vector<ll>> binpow(vector<vector<ll>> a, ll e) {
    int n = size(a);
    vector<vector<ll>> ret(n);
    for (int i = 0; i < n; i++) ret[i].resize(n);
    for (int i = 0; i < n; i++) ret[i][i] = 1;

    while (e) {
        if (e & 1) ret = mul(ret, a);
        a = mul(a, a);
        e >>= 1;
    }

    return ret;
}

void solve() {
    int n;
    ll k; 
    cin >> n >> k;
    vector<vector<ll>> adj(n);
    for (int i = 0; i < n; i++) adj[i].resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }
    adj = binpow(adj, k);
    ll res = 0;
    for (int i = 0; i < n; i++) {
        res = (res + accumulate(begin(adj[i]), end(adj[i]), 0ll)) % mod;
    }
    cout << res << endl;
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
            cerr << endl;
        }
    } else solve();
#ifdef LOCAL_DEBUG
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "\nTime taken: ";
    cerr << chrono::duration <double, milli> (diff).count() << " ms" << endl;
#endif
}

