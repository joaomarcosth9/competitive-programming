#include <bits/stdc++.h>

using namespace std;

void solve() {
    int l = 1, r = 1e6;
    int mid = l + ceil((r - l) / 2.0);
    while (l < r) {
        mid = l + ceil((r - l) / 2.0);
        // cout << mid << ' ' << l << ' ' << r << endl;
        cout << mid << endl;
        string res;
        cin >> res;
        if (res == "<") {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    mid = l + ceil((r - l) / 2.0);
    cout << "! " << mid << endl;
}

int main() {
    solve();
    return 0;
}
