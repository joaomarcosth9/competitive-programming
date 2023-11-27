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
#define int ll

void solve() {
    string s; cin >> s;
    int n = size(s);

    int pos; cin >> pos;
    vector<int> back(n);

    for (int i = 1; i < n; i++) {
        back[i] = i - 1;
    }
    back[0] = -1;

    int numop = 0;
    int N = n;

    while (pos > N) {
        pos -= N;
        numop++;
        N--;
    }

    debug(pos, numop);

    vector<int> rem(n);

    for (int i = 1; numop && i < n; i++) {
        int j = back[i];
        while (numop && j >= 0 && s[j] > s[i]) {
            rem[j] = 1;
            numop--;
            back[i] = (j = back[j]);
        }
    }

    debug(rem);

    string t;

    for (int i = 0; i < n; i++) {
        if (!rem[i]) t += s[i];
    }

    cout << t[pos - 1];
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
    cout << endl;
}
