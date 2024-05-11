#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

ll smallest(ll qnt, ll d) {
    ll num = -1;
    if (d == 0) {
        if (qnt == 1) return 0;
        num = 1;
        for (int i = 0; i < qnt; i++) num *= 10;
    } else {
        num = 0;
        for (int i = 0; i < qnt; i++) {
            num += d;
            d *= 10;
        }
    }
    return num;
}

void solve() {
    ll n; cin >> n;
    map<int, int> minn, maxx;
    for (int d = 0; d <= 9; d++) {
        minn[d] = n >= d;
    }
    for (int d = 0; d <= 9; d++) if (minn[d]) {
        int l = 1, r = 15;
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (smallest(mid, d) <= n) {
                l = mid + 1;
                ans = mid;
            } else r = mid - 1;
        }
        maxx[d] = ans;
    }
    ll ans = 0;
    for (int d = 0; d <= 9; d++) if (minn[d]) {
        ans += maxx[d];
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
