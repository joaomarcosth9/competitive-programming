#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define cerr                                                                                                           \
    if (false) cerr
#endif
#define endl '\n'
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto &x) { return res; }
#define L2(res...) [&](const auto &x, const auto &y) { return res; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int ll
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> i3;
void out(bool ans) { cout << (ans ? "YES" : "NO") << endl; }

void solve() {
    int n;
    ll k;
    cin >> n;
    vector<ll> a(n + 1), c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    cin >> k;
    vector<ii> b, B(n);
    for (int i = 0; i < n; i++) {
        B[i] = {c[i], i + 1};
    }

    sort(all(B), [&](auto &l, auto &r) {
        if (l.first != r.first) return l.first < r.first;
        return l.second > r.second;
    });

    debug(B);
    b.eb(B[0]);
    for (int i = 1; i < n; i++) {
        if (B[i].second > b.back().second) b.eb(B[i]);
    }

    debug(b);

    int N = size(b);

    for (int i = 0; i < N; i++) {
        if (i != 0) {
            ll diff = b[i].first - b[i - 1].first;
            ll add = k / diff;
            if (add == 0) break;
            add = min(add, abs(a[b[i - 1].second]));
            a[b[i - 1].second] += add;
            a[b[i].second] -= add;
            k -= add * diff;
        } else {
            ll curr = k / b[i].first;
            if (curr == 0) break;
            k -= curr * b[i].first;
            a[0] += curr;
            a[b[i].second] -= curr;
        }
        debug(a);
    }
    ll ac = 0;
    for (int i = 0; i < n; i++) {
        ac += a[i];
        cout << ac << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        int TEST = 1;
        while (TEST <= TC) {
            cerr << "[Testcase " << TEST << "]" << endl;
            solve();
            /* cout << solve() << endl; */
            /* cout << (solve() ? "YES" : "NO") << endl; */
            ++TEST;
        }
    } else
        solve();
}
