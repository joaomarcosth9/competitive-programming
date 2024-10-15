#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 2e5 + 5;

int n, len = 0;
ll a[N], b[N];
map<ll, int> m;

vector<ll> used;

bool make(ll x, bool first = 1) {
    if (x % 2 == 0) {
        if (m[x] > 0) {
            used.push_back(x);
            m[x]--;
            return true;
        } else {
            return false;
        }
    }
    if (first || m[x] == 0) {
        return make(x / 2, 0) && make(x / 2 + 1, 0);
    } else {
        used.push_back(x);
        m[x]--;
        return true;
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);
    reverse(a, a + n);

    for (int i = 0; i < n; i++) {
        m[a[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            while (make(2 * a[i] + 1)) {
                used.clear();
                m[2 * a[i] + 1]++;
            }
            for (auto u : used) {
                m[u]++;
            }
            used.clear();
            while (make(2 * a[i] - 1)) {
                used.clear();
                m[2 * a[i] - 1]++;
            }
            for (auto u : used) {
                m[u]++;
            }
            used.clear();
        }
    }

    auto it = m.rbegin();

    while (it != m.rend()) {
        for (int i = 0; i < it->second; i++) {
            b[len++] = it->first;
        }
        it++;
    }

    cout << len << endl;

    for (int i = 0; i < len; i++) {
        cout << b[i] << " ";
    }

    cout << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}