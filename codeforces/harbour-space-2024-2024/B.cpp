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

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    if (k % 2 == 0) {
        sort(all(s));
        cout << s << endl;
        return;
    }
    string a, b;
    for (int i = 0; i < n; i++) {
        if (i & 1) b += s[i];
        else a += s[i];
    }
    sort(all(a));
    sort(all(b));
    int it = 0, it2 = 0;
    for (int i = 0; i < n; i++) {
        if (i & 1) cout << b[it++];
        else cout << a[it2++];
    }
    cout << endl;
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
