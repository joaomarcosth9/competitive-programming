#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);

using namespace std;

void solve() {
    int a, l, n;
    cin >> a >> l >> n;
    int area_res = INT_MAX;
    int res = -1;
    for (int i = 0; i < n; i++) {
        int am, lm;
        cin >> am >> lm;
        if (am * lm < a * l || max(am, lm) < max(a, l) || min(lm, am) < min(a, l)) continue;
        int area = lm * am - a * l;
        if (area < area_res) {
            res = i + 1;
            area_res = area;
        }
    }
    cout << res << endl;
}

int main() {
    _ solve();
    return 0;
}
