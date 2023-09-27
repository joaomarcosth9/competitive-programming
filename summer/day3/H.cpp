#include <bits/stdc++.h>

using namespace std;

int testcases = 0;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;

void solve(int n, int c) {
    map<int, int> vis, where;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    where[0] = 0;
    vis[0] = 1;
    /* cout << "C: " << c << endl; */
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (arr[i] % c);
        sum %= c;
        /* cout << "sum: " << sum << " | vis[sum]: " << vis[sum] << " | where[sum]: " << where[sum] << endl; */
        if (vis[sum]) {
            for (int j = where[sum] + 1; j <= i + 1; j++) {
                cout << j << " ";
            }
            cout << endl;
            return;
        }
        vis[sum] = 1;
        where[sum] = i + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tsts = 1;
    while (1) {
        int n, c;
        cin >> c >> n;
        if (n != 0)
            solve(n, c);
        else
            break;
    }
    return 0;
}
