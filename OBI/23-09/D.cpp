#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int res = INT_MIN;
    if (l < v[0]) {
        res = max(res, v[0] - l);
    }
    if (r > v[n - 1]) {
        res = max(res, r - v[n - 1]);
    }
    for (int i = 0; i < n - 1; i++) {
        int tres = (v[i + 1] - v[i]) / 2;
        if (v[i] + tres < l && v[i + 1] - tres < l) tres = INT_MIN;
        if (v[i] + tres > r && v[i + 1] - tres > r) tres = INT_MIN;
        res = max(res, tres);
    }
    cout << res << endl;
}
