#include <bits/stdc++.h>

using namespace std;
const int INF = 1.05e9;
const int MAX = 1e5;
const long long LINF = 4.5e18;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define endl '\n'

int n, m, k, p;
string s;
vector<string> v;
vector<string> poss;

void permutar(string pm, int x) {
    for (int i = 0; i < (int)v[x].size(); i++) {
        string aa = pm + v[x][i];
        if ((int)aa.size() == m) {
            poss.push_back(aa);
        } else {
            permutar(aa, x + 1);
        }
    }
}

void solve() {
    cin >> n >> m >> k >> s;
    for (int i = 0; i < m; i++) {
        string psps;
        cin >> psps;
        // sortar ?
        v.push_back(psps);
    }
    cin >> p;
    permutar("", 0);
    sort(begin(poss), end(poss));
    int j = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '#') {
            s[i] = poss[p - 1][j];
            j++;
        }
    }
    cout << s << endl;
}

int main() {
    solve();
    return 0;
}
