#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define endl '\n'
#define cerr                                                                                                           \
    if (false) cerr
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n - 1);
    for (ll &i : a) cin >> i;
    ll sum = (n * (n + 1)) / 2;
    vector<ll> perm{a[0]};
    for (int i = 1; i < n - 1; i++) {
        perm.emplace_back(a[i] - a[i - 1]);
    }
    vector<int> vis(n + 1);
    vector<ll> sobra, gtn;
    for (auto i : perm) {
        if (i > n)
            gtn.emplace_back(i);
        else if (vis[i])
            sobra.emplace_back(i);
        else {
            vis[i] = 1;
        }
    }
    if ((gtn.size() && sobra.size()) || gtn.size() > 1 || sobra.size() > 1) {
        cout << "NO" << endl;
        return;
    }
    debug(sobra);
    debug(gtn);
    debug(perm);
    if (gtn.size()) {
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            gtn[0] -= i;
        }
        if (gtn[0] == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return;
    }
    vector<int> check;
    if (sobra.size()) {
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            sobra[0] -= i;
        }
        if (sobra[0] == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += !vis[i];
    }
    cout << (cnt == 1 ? "YES" : "NO") << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    auto start = chrono::steady_clock::now();
    if (TC) {
        cin >> TC;
        start = chrono::steady_clock::now();
        int TEST = 0;
        while (TEST < TC) {
            cerr << "[Testcase " << TEST + 1 << "]" << endl;
            solve();
            ++TEST;
        }
    } else
        solve();
#ifdef LOCAL_DEBUG
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "\nTime taken: ";
    cerr << chrono::duration<double, milli>(diff).count() << " ms" << endl;
#endif
}
