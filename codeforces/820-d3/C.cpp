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
#define endl '\n'

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vi cost(n);
    for (int i = 0; i < n; i++) {
        cost[i] = s[i] - 'a' + 1;
    }
    int current = cost[0];
    if (cost[0] > cost[n - 1]) {
        map<int, set<int>, greater<int>> costdesc;
        /* vector<ii> costdesc; */
        for (int i = 1; i < n; i++) {
            if (cost[i] <= current) {
                costdesc[cost[i]].insert(i);
            }
        }
        /* sort(begin(costdesc), end(costdesc)); */
        /* reverse(begin(costdesc), end(costdesc)); */
        int nump = 1;
        int pathcost = 0;
        int acabou = 0;
        for (auto [k, v] : costdesc) {
            if (acabou) break;
            pathcost += (abs(current - k));
            current = k;
            for (auto i : v) {
                nump++;
                if (i == n - 1) acabou = 1;
            }
        }
        cout << pathcost << ' ' << nump << endl;
        cout << 1 << ' ';
        acabou = 0;
        for (auto [k, v] : costdesc) {
            if (acabou) break;
            for (auto i : v) {
                cout << i + 1 << ' ';
                if (i == n - 1) {
                    acabou = 1;
                }
            }
        }
    } else if (cost[0] < cost[n - 1]) {
        map<int, set<int>> costcres;
        /* vector<ii> costcres; */
        for (int i = 1; i < n; i++) {
            if (cost[i] >= current) {
                costcres[cost[i]].insert(i);
            }
        }
        /* sort(begin(costcres), end(costcres)); */
        int pathcost = 0;
        int nump = 1;
        int acabou = 0;
        for (auto [k, v] : costcres) {
            if (acabou) break;
            pathcost += (abs(current - k));
            current = k;
            for (auto i : v) {
                nump++;
                if (i == n - 1) acabou = 1;
            }
        }
        cout << pathcost << ' ' << nump << endl;
        cout << 1 << ' ';
        acabou = 0;
        for (auto [k, v] : costcres) {
            if (acabou) break;
            for (auto i : v) {
                cout << i + 1 << ' ';
                if (i == n - 1) {
                    acabou = 1;
                }
            }
        }
    } else {
        // CASO FACIL
        // FACIL EH O CARALHO
        int m = 1;
        for (int i = 1; i < n; i++) {
            m += (cost[i] == cost[0]);
        }
        cout << 0 << ' ' << m << endl;
        for (int i = 0; i < n; i++) {
            if (cost[i] == cost[0]) {
                cout << i + 1 << ' ';
            }
        }
    }
    cout << endl;
}

int main() {
    int tsts;
    cin >> tsts;
    for (int Testcase = 1; Testcase <= tsts; Testcase++) {
        /* clog << db(Testcase) << endl; */
        solve();
    }
    return 0;
}
