#include <bits/stdc++.h>

using namespace std;
const int INF = 1.05e9;
const long long LINF = 4.5e18;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back
#define eb emplace_back
#define int long long

void solve() {
    int a, b;
    for (int i = 1; i < 8; i++) {
        for (int j = i + 1; j < 8; j++) {
            cout << "? " << j << ' ' << i << endl;
            cin >> a;
            cout << "? " << i << ' ' << j << endl;
            cin >> b;
            if (a == -1) {
                cout << "! " << max(i, j) - 1 << endl;
                return;
            } else if (a != b) {
                cout << "! " << a + b << endl;
                return;
            }
        }
    }
}

int32_t main() {
    solve();
    return 0;
}
