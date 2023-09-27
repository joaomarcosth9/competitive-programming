#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;

void solve() {
    double f;
    int n, m;
    cin >> n >> m >> f;
    double l = -1;
    for (int d = 0; d < n; d++) {
        double num = m - (d * d * f * f);
        int den = n - d;
        l = max(l, num / den);
    }
    cout << fixed << setprecision(6);
    cout << l << endl;
}

int main() {
    _ solve();
    return 0;
}
