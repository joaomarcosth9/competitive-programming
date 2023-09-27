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
    int n, k;
    string s;
    cin >> n >> k >> s;
    rsor(s);
    vector<string> res(k);
    map<char, int, greater<char>> qt;
    for (char c : s) {
        qt[c]++;
    }
    map<char, int>::iterator it = qt.begin();
    for (int j = 0; j < k; j++) {
        for (int i = 0; i < n / k; i++) {
            auto &[c, v] = (*it);
            /* cout << "C: " << c << endl; */
            res[j].pb(c);
            v--;
            if (v == 0) it++;
        }
    }
    for (auto ss : res) {
        /* cout << "Ss: " << ss << endl; */
        map<char, int> ap;
        for (char c : ss) {
            ap[c]++;
        }
        for (char st = 'a'; st <= 'z'; st++) {
            if (!ap[st]) {
                cout << st;
                break;
            }
        }
    }
    cout << endl;
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
