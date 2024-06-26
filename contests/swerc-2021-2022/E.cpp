#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

vector<char> fix(string s) {
    int n = (int)s.size();
    vector<char> stk;
    for (char c : s) {
        if (c != 'B') {
            if (stk.empty() || stk.back() != c) stk.push_back(c);
            else stk.pop_back();
        }
    }
    return stk;
}

bool solve() {
    string s, t; cin >> s >> t;

    int n = (int)s.size();
    int m = (int)t.size();

    string ss, tt;

    map<char, int> fs, ft;

    for (char c : s) {
        fs[c]++;
    }
    for (char c : t) {
        ft[c]++;
    }

    for (char c : {'A', 'B', 'C'}) {
        if (fs[c] % 2 != ft[c] % 2) {
            return 0;
        }
    }

    return fix(s) == fix(t);

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        // solve();
        // cout << solve() << endl;
        cout << (solve() ? "Yes" : "No") << endl;
    }
}