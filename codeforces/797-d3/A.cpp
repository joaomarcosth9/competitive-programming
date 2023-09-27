#include <iostream>

using namespace std;

void solve() {
    int blocks;
    cin >> blocks;
    int h1 = 0, h2 = 0, h3 = 0;
    while (blocks > 5) {
        h1++;
        h2++;
        h3++;
        blocks -= 3;
    }
    if (blocks == 5) {
        h2 += 2;
        h1 += 3;
    } else {
        h2++;
        blocks--;
        h1 += blocks;
    }
    cout << h2 << ' ';
    cout << h1 << ' ';
    cout << h3 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve();
    }
    return 0;
}
