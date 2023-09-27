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
    vi v(n);
    vi idx(1005, -1);
    vi nv;
    for (auto &a : v) cin >> a;
    for (int i = n - 1; i >= 0; i--) {
        if (idx[v[i]] == -1) idx[v[i]] = i;
    }
    for (int i = 0; i < 1005; i++) {
        if (idx[i] != -1) nv.pb(i);
    }
    int res = -1;
    for (int i = 0; i < (int)nv.size(); i++) {
        for (int j = 0; j < (int)nv.size(); j++) {
            if (gcd(nv[i], nv[j]) == 1) {
                int nres = idx[nv[i]] + idx[nv[j]];
                res = max(res, nres);
            }
        }
    }
    cout << (res == -1 ? res : res + 2) << endl;
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
