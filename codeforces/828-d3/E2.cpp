#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int long long

vector<int> div(int n) {
    vector<int> res;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (n != i * i) res.push_back(n / i);
        }
    }
    sort(begin(res), end(res));
    return res;
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int dv = a * b;
    vector<int> dva = div(a);
    vector<int> dvb = div(b);
    set<int> poss;
    if (dv == 1) {
        cout << c << ' ' << d << endl;
        return;
    }
    for (int x : dva) {
        for (int y : dvb) {
            int prod = x * y;
            int falta = dv / prod;
            int resx = (c / prod) * prod;
            int resy = (d / falta) * falta;
            if (resx > a && resx <= c && resy > b && resy <= d) {
                cout << resx << ' ' << resy << endl;
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
