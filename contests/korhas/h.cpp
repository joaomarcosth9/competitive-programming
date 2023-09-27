#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

string v = "aeiou";

bool is(char c) {
    for (char u : v)
        if (u == c) return 1;
    return 0;
}

void solve() {
    string s, t;
    cin >> s;
    for (char c : s) {
        if (is(c)) t.push_back(c);
    }
    string tt = t;
    reverse(begin(tt), end(tt));
    cout << (tt == t ? "S" : "N") << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
