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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

const int maxn = 3e5 + 5;
vector<ll> perm;
int res = 0;
int n, a[maxn];

namespace sparse {
    pair<int, int> m[20][maxn];
    int n;
    void build(int n2, int *v) {
        n = n2;
        for (int i = 0; i < n; i++) m[0][i] = make_pair(v[i], i);
        for (int j = 1; (1 << j) <= n; j++)
            for (int i = 0; i + (1 << j) <= n; i++) m[j][i] = max(m[j - 1][i], m[j - 1][i + (1 << (j - 1))]);
    }
    pair<int, int> query(int a, int b) {
        int j = __builtin_clz(1) - __builtin_clz(b - a + 1);
        return max(m[j][a], m[j][b - (1 << j) + 1]);
    }
}

ll x[maxn], p[maxn];

ll xquery(int l, int r) {
    return p[r + 1] ^ p[l];
}

void f(int l, int r) {
    if (l > r) return;
    auto [mx, i] = sparse::query(l, r);
    int L = i - l, R = r - i;
    if (L <= R) {
        for (int j = l; j <= i; j++) {
            if (j + mx - 1 >= i && j + mx - 1 <= r) {
                if (xquery(j, j + mx - 1) == perm[mx]) {
                    res++;
                }
            }
        }
    } else {
        for (int j = i; j <= r; j++) {
            if (j - mx + 1 <= i && j - mx + 1 >= l) {
                if (xquery(j - mx + 1, j) == perm[mx]) {
                    res++;
                }
            }
        }
    }
    f(l, i - 1);
    f(i + 1, r);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    sparse::build(n, a);

    map<int, ll> conv;

    for (int i = 1; i <= n; i++) {
        conv[i] = rng() % (1ll << 60);
    }

    for (int i = 0; i < n; i++) {
        x[i] = conv[a[i]];
    }

    for (int i = 0; i < n; i++) p[i + 1] = p[i] ^ x[i];

    perm.resize(n + 1);
    ll now = 0;

    for (int i = 1; i <= n; i++) {
        now ^= conv[i];
        perm[i] = now;
        debug(i, perm[i]);
    }

    f(0, n - 1);

    cout << res << endl;

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
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
