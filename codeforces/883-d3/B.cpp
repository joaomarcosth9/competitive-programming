#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

string w1 = "+++";
string w2 = "XXX";
string w3 = "OOO";

void solve() {
    vector<string> jogo(3);
    for (int i = 0; i < 3; i++) {
        string s;
        cin >> s;
        jogo[i] = s;
    }
    for (int i = 0; i < 3; i++) {
        string s = jogo[i];
        if (s == w1) {
            cout << "+" << '\n';
            return;
        }
        if (s == w2) {
            cout << "X" << '\n';
            return;
        }
        if (s == w3) {
            cout << "O" << '\n';
            return;
        }
    }
    for (int i = 0; i < 3; i++) {
        string s;
        for (int j = 0; j < 3; j++) {
            s.push_back(jogo[j][i]);
        }
        if (s == w1) {
            cout << "+" << '\n';
            return;
        }
        if (s == w2) {
            cout << "X" << '\n';
            return;
        }
        if (s == w3) {
            cout << "O" << '\n';
            return;
        }
    }
    string s;
    for (int j = 0; j < 3; j++) {
        s.push_back(jogo[j][j]);
    }
    if (s == w1) {
        cout << "+" << '\n';
        return;
    }
    if (s == w2) {
        cout << "X" << '\n';
        return;
    }
    if (s == w3) {
        cout << "O" << '\n';
        return;
    }
    s.clear();
    for (int j = 0; j < 3; j++) {
        s.push_back(jogo[j][2 - j]);
    }
    if (s == w1) {
        cout << "+" << '\n';
        return;
    }
    if (s == w2) {
        cout << "X" << '\n';
        return;
    }
    if (s == w3) {
        cout << "O" << '\n';
        return;
    }
    cout << "DRAW" << '\n';
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
