#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int long long

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int dv = a * b;
    for (int i = a + 1; i <= c; i++) {
        int falta = dv / (__gcd(i, dv));
        int proxmut;
        if ((b + 1) % falta == 0) {
            proxmut = b + 1;
        } else
            proxmut = ((b + 1) - ((b + 1) % falta)) + falta;
        if (proxmut <= d && proxmut > b) {
            if ((i * proxmut) % dv == 0) {
                cout << i << ' ' << proxmut << endl;
                return;
            }
        }
    }
    cout << -1 << ' ' << -1 << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
