#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif
#define endl '\n'
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto& x){ return res; }
#define L2(res...) [&](const auto& x, const auto& y){ return res; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

bool solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;
    vector<int> res(3);
    for (int i = 0; i < n; i++) {
        int op = 0;
        debug(i);
        if (a[i] == 0 && b[i] == 0) {
            res[0]++;
            res[1]++;
            res[2]++;
            continue;
        }
        while (a[i]) {
            debug(a[i], b[i]);
            if (b[i] == 0) {
                op++;
                break;
            }
            if (a[i] <= b[i]) {
                int nop = b[i] / a[i];
                b[i] %= a[i];
                if (nop & 1) {
                    swap(a[i], b[i]);
                }
                op += nop + (nop + 1) / 2;
            } else {
                int nop = a[i] / b[i];
                a[i] %= b[i];
                if (nop & 1) {
                    swap(a[i], b[i]);
                }
                op += nop + (nop) / 2;
            }
        }
        res[op % 3]++;
    }
    return (res[0] == n || res[1] == n || res[2] == n);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        /* solve(); */
        /* cout << solve() << endl; */
        cout << (solve() ? "Yes" : "No") << endl;
        TEST += 1;
    }
}
