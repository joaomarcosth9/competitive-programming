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
#define int long long

int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (auto &a : v) cin >> a;
    int db = 1;
    if (n > 2) {
        for (int i = 1; i < n - 1; i++) {
            int mx = max(v[i - 1], v[i + 1]);
            int mn = min(v[i - 1], v[i + 1]);
            if (v[i] % gcd(mx, mn)) db = 0;
        }
    }
    cout << (db ? "YES" : "NO") << endl;
}

int32_t main() {
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
