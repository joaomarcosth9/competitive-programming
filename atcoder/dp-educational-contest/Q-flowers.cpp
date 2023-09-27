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

const int maxn = 2e5 + 5;
int n;
ll dp[2 * maxn];
ll a[maxn], h[maxn];

ll query(int i) {
    ll res = 0;
    int l = 0;
    for (l += n, i += n + 1; l < i; l >>= 1, i >>= 1) {
        if (l & 1) res = max(res, dp[l++]);
        if (i & 1) res = max(res, dp[--i]);
    }
    return res;
}

void update(int i, ll val) {
    dp[i += n] = val;
    for (i >>= 1; i > 0; i >>= 1) dp[i] = max(dp[i << 1], dp[i << 1 | 1]);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        h[i] -= 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        update(h[i], a[i] + query(h[i] - 1));
    }
    cout << query(n - 1) << endl;
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

