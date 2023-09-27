#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    while (k--) {
        if (n % 10)
            n--;
        else
            n /= 10;
    }
    cout << n << endl;
}

int main() {
    _ solve();
    return 0;
}
