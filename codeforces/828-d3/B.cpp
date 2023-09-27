#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int long long

void solve() {
    int n, q;
    cin >> n >> q;
    int e = 0, o = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int nu;
        cin >> nu;
        res += nu;
        e += !(nu & 1);
        o += (nu & 1);
    }
    for (int i = 0; i < q; i++) {
        int t, nu;
        cin >> t >> nu;
        int ee = 0;
        if (t == 0) {
            ee++;
            res += (e * nu);
        } else {
            res += (o * nu);
        }
        cout << res << endl;
        if (nu & 1) {
            if (ee) {
                o += e;
                e = 0;
            } else {
                e += o;
                o = 0;
            }
        }
    }
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
