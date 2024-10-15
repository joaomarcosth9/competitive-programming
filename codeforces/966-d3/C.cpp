#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    int m;
    cin >> m;

    while (m--) {
        string s;
        cin >> s;
        bool dr = 0;
        if (s.size() != a.size()) {
            dr = 1;
        } else {
            map<char, int> conv;
            map<int, char> conv2;
            for (int i = 0; i < n; i++) {
                if (conv.count(s[i]) && conv2.count(a[i])){
                    if (conv[s[i]] != a[i] || conv2[a[i]] != s[i]) dr = 1;
                } else if (conv.count(s[i])) {
                    dr = 1;
                } else if (conv2.count(a[i])) {
                    dr = 1;
                } else {
                    conv[s[i]] = a[i];
                    conv2[a[i]] = s[i];
                }
            }
        }
        cout << (dr ? "No" : "Yes") << endl;
    }

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}