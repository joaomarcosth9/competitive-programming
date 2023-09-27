#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;
string s;

void solve() {
    cin >> s;
    int len = s.size();
    int inside = 0;
    int c = 0;
    int res = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            inside = 1;
        } else if (s[i] == ')') {
            inside = 0;
            c = 0;
        } else if (inside && s[i] == '|') {
            c++;
            res = min(2, max(res, c));
        }
    }
    cout << res + 1 << "-SAT" << endl;
}

int main() {
    _ solve();
    return 0;
}
