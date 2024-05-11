#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

map<string, string> best;

void solve() {
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        string s; cin >> s;
        sort(begin(s), end(s));
        int n = (int)size(s);
        string res;
        for (int i = 0; i < (1 << n); i++) {
            string now;
            for (int j = 0; j < n; j++) if (i & (1 << j)) {
                now += s[j];
            }
            string poss = best[now];
            if (poss == "") continue;
            if (size(poss) > size(res)) {
                res = poss;
            } else if (size(poss) == size(res)) {
                res = min(res, poss);
            }
        }
        cout << (res == "" ? "IMPOSSIBLE" : res) << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int magic; cin >> magic;
    for (int i = 0; i < magic; i++) {
        string s; cin >> s;
        string sorted = s;
        sort(begin(sorted), end(sorted));
        if (best.count(sorted)) best[sorted] = min(s, best[sorted]);
        else best[sorted] = s;
    }
    solve();
}
