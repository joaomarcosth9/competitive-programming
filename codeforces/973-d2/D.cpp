#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

bool ask(string s) {
    cout << "? " << s << endl;
    int ans;
    cin >> ans;
    return (bool)ans;
}

void guess(string s) {
    cout << "! " << s << endl;
}

void solve() {
    int n;
    cin >> n;
    if (ask("0")) {
        string s = "0";
        while ((int)s.size() < n && true) {
            bool has_0 = ask("0" + s);
            if (has_0) {
                s = "0" + s;
            } else {
                bool has_1 = ask("1" + s);
                if (has_1) {
                    s = "1" + s;
                } else {
                    break;
                }
            }
        }
        while ((int)s.size() < n && true) {
            bool has_0 = ask(s + "0");
            if (has_0) {
                s += "0";
            } else {
                s += "1";
            }
        }
        guess(s);
    } else {
        guess(string(n, '1'));
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
