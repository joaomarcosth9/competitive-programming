#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
typedef long long ll;

const int N = 300300;
int a[N];
int n;

void solve() {
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];


    ll sum = 0;
    for (int x : a)
        sum += x;



}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC = 1;
    int TEST = 1;
    while (TEST++ <= TC) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}
