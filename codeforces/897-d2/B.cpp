#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define endl '\n'
#define cerr if (false) cerr
#endif
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
void out(bool ans) { cout << (ans ? "YES" : "NO") << endl; }

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    string ans(n + 1, '2');
    debug(ans);
    int diff = 0, eq = 0;
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        diff += s[i] != s[j];
        eq += s[i] == s[j];
    }
    debug(diff);
    for (int i = 0; i <= n / 2; i++) {
        ans[i] = '0';
        int df2 = diff - i;
        if (df2 == 0) ans[i] = '1';
        if (df2 < 0) {
            ans[i] = '0' + ((df2 % 2 == 0) || (n & 1));
        }
    }
    for (int i = n, j = 0; j < i; i--, j++) {
        ans[i] = ans[j];
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) { cin >> TC;
        int TEST = 1;
        while (TEST <= TC) {
            cerr << "[Testcase " << TEST << "]" << endl;
            solve();
            ++TEST;
        }
    } else solve();
}
