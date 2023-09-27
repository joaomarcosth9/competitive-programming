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
    int n, a, q; cin >> n >> a >> q;
    string s; cin >> s;
    if (n == a) {
        cout << "YES" << endl;
        return;
    }
    int Not = n - a;
    if (count(all(s), '+') + a < n) {
        cout << "NO" << endl;
        return;
    }
    int A = a;
    for (int i = 0; i < q; i++) {
        if (s[i] == '+') {
            a++;
        } else a--;
        debug(i, a);
        if (a == n) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "MAYBE" << endl;
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
