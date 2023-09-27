#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 40;
int arr[MAX];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] %= 10;
    }

    map<int, int> has;
    for (int i = 0; i < n; i++) {
        has[arr[i]]++;
    }

    bool res = false;

    for (auto [k0, v0] : has) {
        for (auto [k1, v1] : has) {
            for (auto [k2, v2] : has) {
                if (k0 == k1 && k1 == k2) {
                    if (v0 < 3) continue;
                } else if (k0 == k1) {
                    if (v0 < 2) continue;
                } else if (k1 == k2) {
                    if (v1 < 2) continue;
                } else if (k0 == k2) {
                    if (v2 < 2) continue;
                }
                res |= (((k0 + k1 + k2) % 10) == 3);
            }
        }
    }
    cout << (res ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; i++) {
        solve();
    }
    return 0;
}
