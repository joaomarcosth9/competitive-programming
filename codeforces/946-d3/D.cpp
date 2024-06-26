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
    int f[4] = {0, 0, 0, 0};
    pair<int, int> pos = {0, 0};
    string s; cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'S') {
            pos.first--;
            f[0]++;
        } else if (s[i] == 'N') {
            pos.first++;
            f[1]++;
        } else if (s[i] == 'E') {
            pos.second--;
            f[2]++;
        } else if (s[i] == 'W') {
            pos.second++;
            f[3]++;
        }
    }
    if ((pos.first & 1) || (pos.second & 1) || ((int)s.size() == 2 && s[0] != s[1])) {
        cout << "NO" << endl;
    } else {
        vector<bool> h(n);
        if (pos != pair<int, int> {0, 0}) {
            pos.first /= 2;
            pos.second /= 2;
            pair<int, int> ini = {0, 0};
            for (int i = 0; i < n; i++) {
                auto ini2 = ini;
                if (s[i] == 'S') {
                    ini2.first--;
                } else if (s[i] == 'N') {
                    ini2.first++;
                } else if (s[i] == 'E') {
                    ini2.second--;
                } else if (s[i] == 'W') {
                    ini2.second++;
                }
                auto nowdist = abs(ini.first - pos.first) + abs(ini.second - pos.second);
                if (abs(ini2.first - pos.first) + abs(ini2.second - pos.second) < nowdist) {
                    h[i] = 1;
                    ini = ini2;
                }
            }
            for (int i = 0; i < n; i++) {
                cout << (h[i] ? "H" : "R");
            }
        } else {
            int ct = 0;
            int first = -1;
            for (int i = 0; i < n; i++) {
                if (first == -1) {
                    if (s[i] == 'S') {
                        first = 0;
                    } else if (s[i] == 'N') {
                        first = 1;
                    } else if (s[i] == 'E') {
                        first = 2;
                    } else if (s[i] == 'W') {
                        first = 3;
                    }
                    h[i] = 1;
                } else {
                    if (s[i] == 'S' && first == 1) {
                        first = -2;
                        h[i] = 1;
                    } else if (s[i] == 'N' && first == 0) {
                        first = -2;
                        h[i] = 1;
                    } else if (s[i] == 'E' && first == 3) {
                        first = -2;
                        h[i] = 1;
                    } else if (s[i] == 'W' && first == 2) {
                        first = -2;
                        h[i] = 1;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                cout << (h[i] ? "H" : "R");
            }
        }
        cout << endl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
