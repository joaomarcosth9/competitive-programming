#include <bits/stdc++.h>
using namespace std;

int temtestcase = 0;
const int INF = 1.05e9;
const long long LINF = 4.5e18;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<int, int>;
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
#define ROF(i, x, y) for (int i = x; i >= y; i--)
#define FO(x) FOR(i, 0, x)
#define OF(x) ROF(i, x, 0)
#define endl '\n'
#ifdef LOCAL_DEBUG
#define _
#else
#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#endif

void printpq(pqg<tuple<int, int, int>> pq) {
    while (!pq.empty()) {
        auto [s, l, r] = pq.top();
        cout << s << ' ' << l << ' ' << r << endl;
        pq.pop();
    }
}

void solve() {
    int n, k, c;
    cin >> n >> k >> c;
    vi v(n);
    FO(n) cin >> v[i];
    vi pref(n + 1);
    FO(n) { pref[i + 1] = pref[i] + v[i]; }
    pqg<tuple<int, int, int>> pq;
    for (int i = 0; i + c - 1 < n; i++) {
        int sum = 0;
        sum += pref[i + c] - pref[i];
        pq.emplace(sum, i, i + c - 1);
    }
    map<int, int> vis;
    /* printpq(pq); */
    int res = 0;
    while (k && !pq.empty()) {
        auto [s, l, r] = pq.top();
        int somevis = 0;
        FOR(i, l, r + 1) { somevis |= vis[i]; }
        if (somevis) {
            pq.pop();
        } else {
            FOR(i, l, r + 1) { vis[i]++; }
            res += s;
            pq.pop();
            k--;
        }
    }
    cout << pref[n] - res << endl;
}

int main() {
    _ int tsts = 1;
    if (temtestcase) cin >> tsts;
    for (int Testcase = 1; Testcase <= tsts; Testcase++) {
        /* clog << db(Testcase) << endl; */
        solve();
    }
    return 0;
}
