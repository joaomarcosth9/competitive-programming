#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int ll
using ll = long long;

void solve() {
    int n, a, b; cin >> n >> a >> b;
    ll A = a;
    int first = A % n;
    vector<ll> l(1, 0), r(1, 0);
    for (int i = 0; i < 10 * n; i++) {
        l.emplace_back(A % n);
        A += a;
        if (A % n == first) break;
    }
    ll B = b;
    first = B % n;
    for (int i = 0; i < 10 * n; i++) {
        r.emplace_back(B % n);
        B += b;
        if (B % n == first) break;
    }

    vector<ll> c((l.size() + r.size()) * 2, (ll)1e18);
    for (int i = 0; i < (int)l.size(); i++) {
        for (int j = 0; j < (int)r.size(); j++) {
            c[i + j] = min(c[i + j], ((ll)l[i] + r[j]) % n);
        }
    }

    for (int i = 1; i < (int)c.size(); i++) {
        if (c[i] == 0) {
            cout << i << endl;
            return;
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
