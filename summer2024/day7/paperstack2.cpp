#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

const int N = 1050;
int n, a[N];

bool solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) return true;
    for (int i = 0; i <= n; i++) {
        bool dbl = 1;
        for (int j = 0; j < i - 1; j++) {
            dbl &= a[j] <= a[j + 1];
        }
        bool dbr = 1;
        for (int j = i; j < n - 1; j++) {
            dbr &= a[j] <= a[j + 1];
        }
        if (dbl && dbr) {
            if (i > 0 && i < n) {
                if (a[n - 1] <= a[0]) return true; 
                return false;
            }
            return true;
        }
    }
    return false;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout << (solve() ? "Phew" : "Lie") << endl;
}
