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

const int maxn = 1e5 + 5;
int n;
bool dr = 0;
ll x = 0;
string s[maxn];

ll calc(int &l) {
    if (l == n) return 0;
    auto now = s[l];
    if (now == "add") {
        return 1 + calc(++l);
    }
    if (now == "end") return 0;
    ll num = stoll(now);
    ll ret = num * calc(++l);
    if (ret > UINT_MAX) {
        dr = 1;
    }
    return ret + calc(++l);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (s[i] == "for") {
            cin >> s[i];
        }
    }
    int i = 0;
    ll ret = calc(i);
    if (ret > UINT_MAX) {
        dr = 1;
    }
    if (dr) cout << "OVERFLOW!!!" << endl;
    else cout << ret << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
