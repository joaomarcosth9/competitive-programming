#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;

void solve() {
    string n;
    int m;
    cin >> n >> m;
    // vector<int> v(26) = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
    // vector<char> v(26)
    // ('2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9');
    char v[] = "22233344455566677778889999";
    int res = 0;
    while (m--) {
        string s;
        cin >> s;
        if (s.size() == n.size()) {
            int ok = 1;
            for (int i = 0; i < (int)s.size(); i++) {
                ok &= (v[s[i] - 'a'] == n[i]);
            }
            res += ok;
        }
    }
    cout << res << endl;
}

int main() {
    _ solve();
    return 0;
}
