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
    string s; cin >> s;
    int n = size(s);
    int st = 0;
    if (s[0] == '0' || s[0] == '-') return 0;

    vector<int> res(n + 1, -1);
    res[0] = res[1] = 1;

    for (int i = 0; i < n; i++) {
        if (s[i] == '-') {
            if (st > 1) res[st] = -1;
            st--;
            continue;
        }
        if (s[i] == '+') {
            st++;
            if (st > 1) res[st] = -1;
            continue;
        }

        if ((s[i] == '1' && res[st] == 0) || (s[i] == '0' && res[st] == 1)) return 0;

        if (res[st] == -1) {
            int now = s[i] - 48;
            int stt = st;
            if (s[i] == '1') while (res[stt] != 1) {
                if (res[stt] == 0) return 0;
                else res[stt] = 1;
                stt--;
            } else res[stt] = 0;
        }
    }
    return 1;
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
        cout << (solve() ? "YES" : "NO") << endl;
        TEST += 1;
    }
}
