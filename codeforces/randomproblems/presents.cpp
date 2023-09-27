#include <bits/stdc++.h>

using namespace std;

int testcases = 0;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        cout << v[i].second << ' ';
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tsts = 1;
    if (testcases) cin >> tsts;
    while (tsts--) solve();
    return 0;
}
