#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 2e5 + 50;
typedef long long ll;

vector<int> V(MAX);

void solve() {
    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> V[i];
        sum += V[i];
    }
    int allz = 1, zeros = 0;
    for (int i = 0; i < n - 1; i++) {
        if (V[i] != 0) {
            allz = 0;
        } else {
            if (!allz) {
                zeros++;
            }
        }
    }
    cout << zeros + sum - V[n - 1] << endl;
}

int main() {
    _ int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; i++) {
        solve();
    }
    return 0;
}
