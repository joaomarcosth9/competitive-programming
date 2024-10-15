#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

tuple<int, int, int> expand(int l, int r, int L, int R) {
    debug(l, r, L, R);
    if (R < l) {
        return {l - L, L, r};
    }
    if (L > r) {
        return {R - r, l, R};
    }
    L = min(L, l);
    R = max(R, r);
    return {(l - L) + (R - r), L, R};
}

pair<int, int> intersect(pair<int, int> a, pair<int, int> b) {
    if (a.first == -1 || b.first == -1) return {-1, -1};

    if (a.second < b.first) return {-1, -1};
    if (b.second < a.first) return {-1, -1};

    if (a.first >= b.first && a.second <= b.second) return a;
    if (b.first >= a.first && b.second <= a.second) return b;

    int L = max(a.first, b.first);
    int R = min(a.second, b.second);

    return {L, R};
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a) 
        cin >> i;

    vector<int> f(n + 1);

    vector<basic_string<int>> pos(n + 1);

    for (int i = 0; i < n; i++) {
        f[a[i]]++;
        pos[a[i]].push_back(i);
    }

    vector<int> L(n + 1, n), R(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        if (pos[i].size()) {
            L[i] = pos[i][0], R[i] = pos[i].back();
        }
    }

    int time = 1;

    int winning = 0;

    pair<int, int> w = {0, n - 1};

    int myL = -1, myR = -1;

    int i = -1;

    // for (i = 1; i <= n; i++) {
    //     if (L[i] <= R[i]) {
    //         int nL = max(0, R[i] - i + 1);
    //         int nR = min(n - 1, L[i] + i - 1);
    //         debug(w, nL, nR);
    //         w = intersect(w, {nL, nR});
    //     }
    // }

    // cout << (w.first != -1 ? w.second - w.first + 1 : 0) << endl;

    // return;

    for (i = 1; i <= n; i++) {
        if (L[i] <= R[i]) {
            if (R[i] - L[i] + 1 > i) {
                cout << 0 << endl;
                return;
            }

            myL = L[i], myR = R[i];

            time = R[i] - L[i] + 1;

            w = intersect(w, {max(0, R[i] - i + 1), min(n - 1, L[i] + i - 1)});

            break;
        }
    }

    for (int j = i + 1; j <= n; j++) {
        if (L[j] <= R[j]) {
            auto [add, new_L, new_R] = expand(myL, myR, L[j], R[j]);
            debug(j, myL, myR, new_L, new_R);
            int max_time = j;
            if (time + add <= max_time) {
                myL = new_L, myR = new_R;

                time += add;

                w = intersect(w, {max(0, R[j] - j + 1), min(n - 1, L[j] + j - 1)});

                debug(time, resta);
            } else {
                cout << 0 << endl;
                return;
            }
        }
    }

    cout << (w.first == -1 ? 0 : (w.second - w.first + 1)) << endl;
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