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
    int n; cin >> n;
    string s; cin >> s;

    for (int i = 0; i < n; i += 2) {
        s[i] = 0;
    }

    vector<int> suff(n);

    assert(s[n - 1] == ')');
    suff[n - 1] = s[n - 1] == ')';

    for (int i = n - 2; i >= 0; i--) {
        suff[i] = suff[i + 1] + (s[i] == ')');
    }

    ll cost = 0;

    stack<int> stk;

    for (int i = 0; i < n; i++) {
        if (s[i] != 0) {
            if (s[i] == ')') {
                cost += (i - stk.top());
                stk.pop();
            } else {
                stk.push(i);
            }
        } else {
            // quero fechar se der
            // .... _ 
            if (stk.size()) {
                cost += (i - stk.top());
                stk.pop();
            } else {
                stk.push(i);
            }
        }
    }

    cout << cost << endl;
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
