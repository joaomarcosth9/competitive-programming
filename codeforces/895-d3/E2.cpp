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
#define int ll
vector<int> u;
vector<int> pref;

int query(int l, int r) {
    l++; r++;
    return pref[r] ^ pref[l - 1];
}

void solve() {
    int n; cin >> n;
    u.assign(n, 0);
    pref.assign(n + 1, 0);
    for (int i = 0; i < n; i++) cin >> u[i];
    string s; cin >> s;
    int X = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] - '0') X ^= u[i];
        pref[i + 1] = pref[i] ^ u[i];
    }

    int q; cin >> q;
    for (int Q = 0; Q < q; Q++) {
        int t; cin >> t;
        if (t == 2) {
            int g; cin >> g;
            // XOR de todos que s[i] == g;
            if (g) cout << X << " ";
            else cout << (X ^ query(0, n - 1)) << " ";
        } else {
            int l, r; cin >> l >> r;
            l--; r--;
            X ^= query(l, r);
        }
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
