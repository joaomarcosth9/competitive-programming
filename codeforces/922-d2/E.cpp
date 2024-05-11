#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cassert>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
using ll = long long;
#include <random>
#include <chrono>
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int op = 0;
int ask(int i) {
    cout << "? " << i << endl;
    op++;
    char c; cin >> c;
    if (c == '=') {
        return 0;
    }
    if (c == '<') {
        return -1;
    }
    return 1;
}

vector<int> p;
void guess() {
    cout << "! ";
    for (int i = 1; i < (int)p.size(); i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}

void get_vals(int l, int r, vector<vector<int>> &vals, int level = 0) {
    if (l > r) return;
    int val = (l + r) / 2;
    vals[level].emplace_back(val);
    if (l < r) {
        get_vals(l, val - 1, vals, level + 1);
        get_vals(val + 1, r, vals, level + 1);
    }
}

void solve() {
    int n; cin >> n;

    p.assign(n + 1, 0);

    while (ask(1) != 0) { // n
        continue;
    }
    int curr_min = 1, curr_max = 1;
    int x = -1;

    vector<int> L(n + 1, 2), R(n + 1, n - 1);

    for (int i = 2; i <= n; i++) { // 3n
        int r = ask(i);
        if (r == 1) {
            ask(curr_min);
        } else {
            curr_min = i;
            if (r == -1) {
                while (ask(i) == -1) {
                    continue;
                }
            }
        }
    }

    L[curr_min] = 1;
    R[curr_min] = 0;
    p[curr_min] = 1;
    x = 1;
    while (ask(1) != 0) { // n
        continue;
    }

    for (int i = 2; i <= n; i++) { // 3n
        int r = ask(i);
        if (r == -1) {
            ask(curr_max);
        } else {
            curr_max = i;
            if (r == 1) {
                while (ask(i) == 1) {
                    continue;
                }
            }
        }
    }

    L[curr_max] = n + 1;
    R[curr_max] = n;
    p[curr_max] = n;
    x = n;

    auto change = [&] (int k) {
        while (x < k) {
            ask(curr_max);
            x++;
        }
        while (x > k) {
            ask(curr_min);
            x--;
        }
    };

    vector<vector<int>> q(n + 1);
    for (int i = 1; i <= n; i++) if (L[i] <= R[i]) {
        q[(L[i] + R[i]) / 2].push_back(i);
    }

    int it = 1;
    int BG = 1, EN = n + 1;
    while (true) {
        bool ok = 0;

        auto go = [&] (int i) {
            if (it == 1) return i + 1;
            else return i - 1;
        };

        for (int i = BG; i != EN; i = go(i)) {
            if (q[i].size()) {
                change(i);
                ok = 1;
                for (auto j : q[i]) {
                    int r = ask(j);
                    if (r == 1) {
                        x++;
                        L[j] = i + 1;
                    } else if (r == -1) {
                        x--;
                        R[j] = i - 1;
                    } else {
                        p[j] = i;
                        R[j] = 0; L[j] = n + 1;
                    }
                    if (L[j] <= R[j]) {
                        int mid = (L[j] + R[j]) / 2;
                        q[mid].push_back(j);
                    }
                    change(i);
                }
                q[i].clear();
            }
        }

        it ^= 1;
        if (it == 1) {
            BG = 1, EN = n + 1;
        } else {
            BG = n, EN = 0;
        }
        if (ok) continue;
        else break;
    }
    assert(op <= 40*n);
    guess();
    op = 0;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
