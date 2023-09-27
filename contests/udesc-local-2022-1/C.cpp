#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;
typedef long long ll;
int d;

vector<ll> phi1n(int n) {
    vector<ll> phi(n + 1);
    for (int i = 0; i <= n; i++) phi[i] = i;
    for (int i = 2; i <= n; i++)
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i) phi[j] -= phi[j] / i;
        }
    return phi;
}

void solve() {
    cin >> d;
    vector<ll> R = phi1n(d);
    ll res = 0;
    for (int i = 2; i <= d; i++) {
        res += R[i];
    }
    cout << res % (int)(1e9 + 7) << endl;
}

int main() {
    _ solve();
    return 0;
}
