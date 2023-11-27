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

typedef long long ll;

const int maxn = 4e5 + 5;
int n, k;
ll a[maxn], conv[maxn];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    if (k == 1) {
        cout << n << endl;
        return;
    }

    ll sum = 0;
    for (int i = 1; i < k; i++) {
        conv[i] = (rng() % (ll)1e12) + 5;
        sum += conv[i];
    }
    conv[k] = -sum;

    for (int i = 0; i < n; i++) a[i] = conv[a[i]];

    map<ll, int> id;
    sum = 0;
    int res = 0;

    id[0] = -1;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (id.count(sum)) {
            res = max(res, i - id[sum]);
        } else id[sum] = i;
    }

    cout << res << endl;

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
}

