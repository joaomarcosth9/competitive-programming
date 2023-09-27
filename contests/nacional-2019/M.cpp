#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    vector<int> diff(n);
    for (auto &a : v) cin >> a;
    for (int i = 0; i < n - 1; i++) {
        diff[i] = v[i + 1] - v[i];
    }
    int res = 0;
    int sq = 0;
    for (int i = 0; i < n - 1; i++) {
        if (diff[i] <= x) {
            sq++;
        } else {
            sq = 0;
        }
        res = max(sq, res);
    }
    cout << res + 1 << endl;
}

int main() { solve(); }
