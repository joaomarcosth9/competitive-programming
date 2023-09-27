#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;

void solve() {
    int arr[4];
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
    sort(begin(arr), end(arr));
    cout << abs(arr[0] + arr[3] - (arr[1] + arr[2])) << endl;
}

int main() {
    _ solve();
    return 0;
}
