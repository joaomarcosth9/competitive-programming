#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;

double pi = acos(-1);

double circun(int r) { return 2 * pi * (double)r; }

void solve() {
    int n, b;
    cin >> n >> b;
    int res = 0;
    vector<pair<int, int>> v;
    for (int i = 0; i < b; i++) {
        int q, r;
        cin >> q >> r;
        v.emplace_back(r, q);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < b; i++) {
        double k = circun(v[i].first);
        int q = v[i].second;
        if ((double)n / k >= q) {
            res += q;
            n -= (k * q);
        } else {
            res += (int)(n / k);
            break;
        }
    }
    cout << res << endl;
}

int main() {
    _ solve();
    return 0;
}
