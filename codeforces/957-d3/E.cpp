#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int MAX = 10000;

string cc(string s, int n) {
    string res = "";
    while (n--) {
        res += s;
    }
    return res;
}

bool good(int n, int a, int b) {
    int num = n * a - b;
    string N = to_string(n);
    N = cc(N, a);
    while (b--) {
        N.pop_back();
        assert(N.size());
    }
    assert(N.size());
    assert(N.size() <= 10);
    return stoll(N) == (ll)num;
}

void solve() {
    int n; cin >> n;
    string N = to_string(n);
    string concat = cc(N, MAX + 10);
    vector<ll> nums(15);
    vector<bool> bad(15);

    ll now = 0;
    for (int i = 1; i <= 11; i++) {
        now *= 10;
        now += (concat[i - 1] - '0');
        debug(i, now);
        nums[i] = now;
    }

    int ln = (int)N.size();
    vector<pair<int, int>> res;

    for (int a = 1; a <= MAX; a++) {
        int len = ln * a;
        int num = n * a;
        for (int db = 1; db <= 10; db++) {
            int b = len - db;
            if (b <= 0 || b > min(MAX, a * n)) continue;
            int num2 = num - b;
            if (to_string(nums[db]).size() != db) {
                continue;
            }
            if (num2 == nums[db]) {
                res.push_back({a, b});
            }
        }
    }
    cout << ssize(res) << endl;
    for (auto [u, v] : res) {
        // if (!good(n, u, v)) {
        //     cout << "=========" << endl;
        //     cout << n << " " << u << " " << v << endl;
        //     cout << "=========" << endl;
        // }
        cout << u << " " << v << endl;
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
