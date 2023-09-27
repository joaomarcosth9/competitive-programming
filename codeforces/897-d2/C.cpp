#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
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
#define int ll

void solve() {
    int n; cin >> n;
    set<ll> st;
    int cmex = 0;
    for (int i = 0; i < n; i++) {
        int u; cin >> u;
        st.emplace(u);
    }
    st.emplace(LLONG_MAX);
    auto it = begin(st);
    while (*it == cmex) {
        cmex += 1;
        it++;
    }

    int moves = 0;
    while (true) {
        if (moves == 2 * n) {
            cout << cmex << endl;
            break;
        }
        cout << cmex << endl;
        cin >> cmex;
        if (cmex == -1) break;
    };
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
