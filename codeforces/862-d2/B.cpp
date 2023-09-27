#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1) {
        cout << s << endl;
        return;
    } else if (n == 2) {
        sort(begin(s), end(s));
        cout << s << endl;
        return;
    }
    map<char, int> fq;
    char sm = s[0];
    fq[s[0]]++;
    for (int i = 1; i < n; i++) {
        fq[s[i]]++;
        sm = min(sm, s[i]);
    }
    int i;
    if (s[0] == sm) {
        if (fq[sm] == 1) {
            cout << s << endl;
        } else {
            for (i = n - 1; i > 0; i--) {
                if (s[i] == sm) {
                    break;
                }
            }
            cout << s[i];
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                cout << s[j];
            }
            cout << endl;
        }
    } else if (s[0] > sm) {
        bool f = 0;
        for (i = n - 1; i > 0; i--) {
            if (s[i] == sm) {
                break;
            }
        }
        cout << s[i];
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            cout << s[j];
        }
        cout << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
