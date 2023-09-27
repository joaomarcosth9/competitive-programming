#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;
typedef long long ll;
const int MAX = 1e5 + 100;
int n, l, r;

void solve() {
    cin >> n >> l >> r;
    vector<int> R;
    map<int, int> M;
    for (int i = 1; i <= n; i++) {
        int nu = l + (i - l % i);
        if (l % i == 0) {
            R.push_back(l);
        } else if (nu <= r) {
            R.push_back(nu);
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < R.size(); i++) cout << R[i] << ' ';
    cout << endl;
    return;
}

int main() {
    _ int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; i++) {
        solve();
    }
    return 0;
}
