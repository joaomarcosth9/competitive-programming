#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;

const int MAX = 2e5 + 500;
int arr[MAX], n;

void solve() {
    cin >> n;
    int media;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        media += arr[i];
    }
}

int main() {
    _ int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; i++) {
        solve();
    }
    return 0;
}
