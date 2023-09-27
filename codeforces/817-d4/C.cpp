#include <bits/stdc++.h>

using namespace std;
const int INF = 1.05e9;
const int MAX = 1e5;
const long long LINF = 4.5e18;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

void solve() {
    int n;
    cin >> n;
    map<string, vector<int>> m;
    vector<vector<string>> v(3, vector<string>(n));
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < n; i++) {
            cin >> v[k][i];
        }
    }
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < n; i++) {
            m[v[k][i]].push_back(k);
        }
    }
    vector<int> pts(3, 0);
    for (auto [s, v] : m) {
        if (v.size() == 1) {
            pts[v[0]] += 3;
        } else if (v.size() == 2) {
            for (auto i : v) pts[i]++;
        }
    }
    for (auto i : pts) cout << i << ' ';
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
