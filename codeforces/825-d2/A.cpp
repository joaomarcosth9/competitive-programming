#include <bits/stdc++.h>
using namespace std;

int temtestcase = 1;
const int INF = 1.05e9;
const long long LINF = 4.5e18;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;
template <typename T> using pql = priority_queue<T>;
template <typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sor(x) sort(all(x))
#define rsor(x) sort(rall(x))
#define pb push_back
#define eb emplace_back
#define FOR(i, x, y) for (int i = x; i < y; i++)
#define ROF(i, x, y) for (int i = x - 1; i >= y; i--)
#define FO(x) FOR(i, 0, x)
#define OF(x) ROF(i, x, 0)
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    for (auto &c : a) cin >> c;
    for (auto &c : b) cin >> c;
    int ig = 1;
    for (int i = 0; i < n; i++) {
        ig &= (a[i] == b[i]);
    }
    if (ig) {
        cout << 0 << endl;
        return;
    }
    int as = 0, bs = 0, df = 0;
    for (int i = 0; i < n; i++) {
        as += a[i];
        bs += b[i];
        df += (a[i] != b[i]);
    }
    if (as == bs) {
        cout << 1 << endl;
        return;
    }
    if (df == abs(as - bs)) {
        cout << abs(as - bs) << endl;
        return;
    }
    cout << (abs(as - bs)) + 1 << endl;
}

int main() {
#ifndef LOCAL_DEBUG
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tsts = 1;
    if (temtestcase) cin >> tsts;
    for (int Testcase = 1; Testcase <= tsts; Testcase++) {
        /* clog << db(Testcase) << endl; */
        solve();
    }
    return 0;
}
