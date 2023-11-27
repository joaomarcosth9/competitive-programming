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

typedef long long ll;
typedef __int128_t LL;

const int maxn = 4e5 + 5;
const ll p = 1001003;
const ll mod = (ll)1e18 + 9;
int a[maxn];
LL pw[maxn];
int n, k;

void solve() {
    cin >> n >> k;

    pw[0] = 1;
    for (int i = 1; i < maxn; i++) pw[i] = pw[i - 1] * p % mod;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

    ll Hash = 0;
    int res = 0;
    map<ll, int> has;
    has[0] = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] > 1) Hash = ((LL)Hash + pw[a[i]]) % mod;
        if (a[i] < k) Hash = ((LL)Hash - pw[a[i] + 1] + mod) % mod;
        if (has.count(Hash)) {
            res = max(res, i - has[Hash]);
        } else {
            has[Hash] = i;
        }
    }

    cout << res << endl;

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
}

