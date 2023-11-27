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

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    if (n & 1) {
        cout << -1 << endl;
        return;
    }
    if (count(all(s), '0') != n / 2) {
        cout << -1 << endl;
        return;
    }
    vector<int> ops;

    int i = 0, j = n - 1;
    int opl = 0;

    deque<char> dq;
    for (auto c : s) dq.push_back(c);

    while (dq.size() > 1) {
        char f = dq.front(), b = dq.back();
        if (f != b) {
            dq.pop_front(), dq.pop_back();  
            i++, j--;
        } else {
            if (b == '0') {
                dq.pop_front(), dq.push_back('0');
                ops.push_back(j);
                i++;
                j++;
            } else {
                dq.pop_back(), dq.push_front('1');
                ops.push_back(i - 1);
                i++;
                j++;
            }
        }
    }
    assert(dq.empty());

    cout << size(ops) << endl;

    for (auto u : ops) cout << u + 1 << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
