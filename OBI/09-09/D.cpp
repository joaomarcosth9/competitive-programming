#include <bits/stdc++.h>

using namespace std;
#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back
#define eb emplace_backond
const int INF = 1.05e9;
const long long LINF = 4.5e18;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

void solve() {
    int e1, e2, e3, x;
    cin >> e1 >> e2 >> e3 >> x;
    if (abs(e1 - e2) <= x) {
        cout << e2 << endl;
    } else {
        cout << e3 << endl;
    }
}

int main() {
    _ solve();
    return 0;
}
