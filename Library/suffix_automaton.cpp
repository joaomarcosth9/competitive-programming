#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

namespace sa {
    const int N = 3e5 + 5, S = 2 * N;

    array<int, 26> to[S];
    int lnk[S], len[S];

    int last = 1, id = 2;
    void push(char ch) {
        int c = (int)(ch - 'a');
        int cur = id++;
        len[cur] = len[last] + 1;
        int p = last;
        while (p != 0 && to[p][c] == 0) {
            to[p][c] = cur;
            p = lnk[p];
        }
        if (p == 0) {
            lnk[cur] = 1;
        } else {
            int s = to[p][c];
            if (len[s] == len[p] + 1) {
                lnk[cur] = s;
            } else {
                int clone = id++;
                len[clone] = len[p] + 1;
                lnk[clone] = lnk[s];
                to[clone] = to[s];
                while (p != 0 && to[p][c] == s) {
                    to[p][c] = clone;
                    p = lnk[p];
                }
                lnk[s] = lnk[cur] = clone;
            }
        }
        last = cur;
    }
    void dbg() {
        for (int u = 1; u < id; u++) {
            cout << u << ", len = " << len[u] << ", lnk = " << lnk[u] << ", to = {";
            int cnt = 0;
            for (int i = 0; i < 26; i++) {
                if (to[u][i] != 0) {
                    if (cnt > 0) {
                        cout << ", ";
                    }
                    cout << (char)('a' + i) << " -> " << to[u][i];
                    cnt++;
                }
            }
            cout << "}" << endl;
        }
    }
}


void solve() {
    string s; cin >> s;
    for (char ch : s) {
        sa::push(ch);
        cout << "inserindo " << ch << endl;
        sa::dbg();
        cout << endl;
    }
    cout << "ok" << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}
