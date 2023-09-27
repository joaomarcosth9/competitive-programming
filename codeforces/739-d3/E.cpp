#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve() {
    string t, s, order;
    cin >> t;
    map<char, int> freq, freq_s;
    int n = t.size(), size_s = 0;
    map<char, bool> f;
    for (int i = n - 1; i >= 0; i--) {
        char &c = t[i];
        if (!f[c]) {
            order.push_back(c);
            f[c] = 1;
        }
    }

    reverse(begin(order), end(order));

    for (int i = 0; i < n; i++) {
        freq[t[i]]++;
    }

    for (int i = (int)order.size() - 1; i >= 0; i--) {
        freq_s[order[i]] = freq[order[i]] / (i + 1);
        size_s += freq_s[order[i]];
    }

    for (int i = 0; i < size_s; i++) {
        if (freq_s[t[i]]) {
            s.push_back(t[i]);
            freq_s[t[i]]--;
        } else {
            cout << -1 << endl;
            return;
        }
    }

    map<char, bool> rem;
    int idxrem = 0;
    for (int idx = 0; idx < n;) {
        bool dr = 1;
        for (int i = 0; i < size_s; i++)
            if (!rem[s[i]]) {
                dr = 0;
                if (s[i] != t[idx]) {
                    cout << -1 << endl;
                    return;
                }
                idx++;
            }
        if (dr) {
            cout << -1 << endl;
            return;
        }
        if (idxrem < (int)order.size()) {
            rem[order[idxrem]] = 1;
        }
        idxrem++;
    }

    cout << s << " " << order << endl;
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
